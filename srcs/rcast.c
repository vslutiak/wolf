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

void	verline(SDL_Surface *surface, SDL_Surface *tex, int texx, t_struct *ray)
{
	int *pix;
	int *texpix;
	int color;

	pix = (int *)surface->pixels;
	texpix = (int *)tex->pixels;
	while (ray->drawstart < ray->drawend)
	{
		ray->d = ray->drawstart * 256 - HEIGHT * 128 + ray->lineheight * 128;
		ray->texy = ((ray->d * TEXHEIGHT) / ray->lineheight) / 256;
		color = texpix[TEXHEIGHT * ray->texy + texx];
		pix[ray->drawstart * surface->w + ray->x] = color;
		ray->drawstart++;
	}
	sidefloor(ray);
	drawroof(ray->surface, ray->wall_texture[3], ray);
}

void	r_ray1(t_struct *ray)
{
	if (ray->side == 0 || ray->side == 1)
		ray->perpwalldist = (ray->mapx - ray->player_posx
			+ (1 - ray->stepx) / 2) / ray->raydirx;
	else
		ray->perpwalldist = (ray->mapy - ray->player_posy
			+ (1 - ray->stepy) / 2) / ray->raydiry;
	ray->lineheight = (int)(HEIGHT / ray->perpwalldist);
	ray->drawstart = -(ray->lineheight) / 2 + HEIGHT / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + HEIGHT / 2;
	if (ray->drawend >= HEIGHT)
		ray->drawend = HEIGHT - 1;
	ray->texnum = ray->worldmap[ray->mapx][ray->mapy] - 1;
	if (ray->side == 0 || ray->side == 1)
		ray->wallx = ray->player_posy + ray->perpwalldist * ray->raydiry;
	else
		ray->wallx = ray->player_posx + ray->perpwalldist * ray->raydirx;
	ray->wallx -= floor((ray->wallx));
	ray->texx = (int)(ray->wallx * (double)(TEXWIDTH));
	if ((ray->side == 0 || ray->side == 1) && ray->raydirx > 0)
		ray->texx = TEXWIDTH - ray->texx - 1;
	if ((ray->side == 1 || ray->side == 2) && ray->raydiry < 0)
		ray->texx = TEXWIDTH - ray->texx - 1;
	verline(ray->surface, ray->wall_texture[ray->side], ray->texx, ray);
}

void	dda(t_struct *ray, int hit)
{
	while (hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			if (ray->raydirx > 0)
				ray->side = 0;
			else
				ray->side = 1;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			if (ray->raydiry > 0)
				ray->side = 2;
			else
				ray->side = 3;
		}
		if (ray->worldmap[ray->mapx][ray->mapy] > 0)
			hit = 1;
	}
	r_ray1(ray);
}

void	r_ray(t_struct *ray)
{
	int hit;

	hit = 0;
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (ray->player_posx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - ray->player_posx) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (ray->player_posy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - ray->player_posy) * ray->deltadisty;
	}
	dda(ray, hit);
}

void	raycast(t_struct *ray)
{
	while (ray->stop)
	{
		SDL_FillRect(ray->surface, NULL,
			SDL_MapRGB(ray->surface->format, 0x00, 0x00, 0x00));
		ray->x = 0;
		while (ray->x < WIDTH)
		{
			ray->x++;
			ray->camerax = 2 * ray->x / (double)WIDTH - 1;
			ray->raydirx = ray->dirx + ray->planex * ray->camerax;
			ray->raydiry = ray->diry + ray->planey * ray->camerax;
			ray->mapx = (int)ray->player_posx;
			ray->mapy = (int)ray->player_posy;
			ray->deltadistx = fabs(1 / ray->raydirx);
			ray->deltadisty = fabs(1 / ray->raydiry);
			r_ray(ray);
		}
		SDL_UpdateWindowSurface(ray->window);
		hook(ray);
		iter(ray);
		SDL_Delay(10);
	}
	clearsdl(ray);
}
