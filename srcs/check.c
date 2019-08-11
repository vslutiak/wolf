/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:40:48 by vslutiak          #+#    #+#             */
/*   Updated: 2019/02/26 20:08:08 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	iter(t_struct *ray)
{
	if (ray->up == 1 || ray->down == 1)
		ft_move(ray);
	if (ray->right == 1 || ray->left == 1)
		ft_move1(ray);
	if (ray->mus == 1 || ray->mus == 10)
		music(ray);
}

int		music(t_struct *ray)
{
	if (ray->mus == 1)
	{
		if (Mix_PlayMusic(ray->music, -1) == -1)
		{
			ray->mus = 0;
			return (-1);
		}
		ray->mus = 0;
	}
	else if (ray->mus == 10)
		Mix_PauseMusic();
	return (0);
}

void	drawroof(SDL_Surface *surface, SDL_Surface *tex, t_struct *ray)
{
	int	*pix;
	int	*texpix;
	int	color;

	pix = (int *)surface->pixels;
	texpix = (int *)tex->pixels;
	ray->drawend += 1;
	while (ray->drawend < HEIGHT)
	{
		ray->currentdist = HEIGHT / (2.0 * ray->drawend - HEIGHT);
		ray->weid = (ray->currentdist - ray->distplayer)
		/ (ray->distwall - ray->distplayer);
		ray->currentfloorx = ray->weid * ray->floorx +
		(1.0 - ray->weid) * ray->player_posx;
		ray->currentfloory = ray->weid * ray->floory +
		(1.0 - ray->weid) * ray->player_posy;
		ray->floorxx = (int)(ray->currentfloorx * TEXWIDTH) % TEXWIDTH;
		ray->floorxy = (int)(ray->currentfloory * TEXHEIGHT) % TEXHEIGHT;
		color = texpix[TEXWIDTH * ray->floorxy + ray->floorxx];
		pix[(HEIGHT - ray->drawend) * surface->w + ray->x] = color;
		pix[ray->drawend * surface->w + ray->x] = color;
		ray->drawend++;
	}
}

void	sidefloor(t_struct *ray)
{
	if (ray->side == 0 && ray->raydirx > 0)
	{
		ray->floorx = ray->mapx;
		ray->floory = ray->mapy + ray->wallx;
	}
	else if (ray->side == 1 && ray->raydirx < 0)
	{
		ray->floorx = ray->mapx + 1.0;
		ray->floory = ray->mapy + ray->wallx;
	}
	else if (ray->side == 2 && ray->raydiry > 0)
	{
		ray->floorx = ray->mapx + ray->wallx;
		ray->floory = ray->mapy;
	}
	else
	{
		ray->floorx = ray->mapx + ray->wallx;
		ray->floory = ray->mapy + 1.0;
	}
	ray->distwall = ray->perpwalldist;
	ray->distplayer = 0.0;
	if (ray->drawend < 0)
		ray->drawend = HEIGHT;
}

int		checkmaps(t_struct *ch)
{
	int	i;
	int	b;

	i = 1;
	b = 1;
	if (ch->lines > 200 || ch->chars > 200)
		return (-1);
	while (i < ch->lines)
	{
		b = 1;
		while (b < ch->chars)
		{
			if (ch->worldmap[i][b] > 9 || ch->worldmap[i][b] < 0)
				return (-1);
			b++;
		}
		i++;
	}
	return (0);
}
