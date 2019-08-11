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

void	init(t_struct *wl)
{
	wl->dirx = -1;
	wl->diry = 0;
	wl->planex = 0;
	wl->planey = 0.66;
	wl->movespeed = 0.035;
	wl->rotspeed = 0.05;
	wl->stop = 1;
	wl->left = 0;
	wl->up = 0;
	wl->down = 0;
	wl->right = 0;
	wl->lines = 0;
	wl->chars = 0;
	wl->plpos = 0;
	wl->space = 0;
	wl->mus = 0;
}

int		sd_init(t_struct *ray)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	ray->window = SDL_CreateWindow("SDL2", 50, 100, WIDTH, HEIGHT, 0);
	ray->surface = SDL_GetWindowSurface(ray->window);
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
		return (-1);
	if (!(ray->music = Mix_LoadMUS("pics/HAHAHA.wav")))
		return (-1);
	if (!(ray->wall_texture = malloc(sizeof(SDL_Surface) * 6)))
		return (-1);
	if (!(ray->wall_texture[0] = IMG_Load("pics/wood.png")))
		return (-1);
	if (!(ray->wall_texture[1] = IMG_Load("pics/eagle.png")))
		return (-1);
	if (!(ray->wall_texture[2] = IMG_Load("pics/bluestone.png")))
		return (-1);
	if (!(ray->wall_texture[3] = IMG_Load("pics/greystone.png")))
		return (-1);
	return (1);
}

void	ft_move1(t_struct *k)
{
	if (k->right == 1)
	{
		k->olddirx = k->dirx;
		k->dirx = k->dirx * cos(-(k->rotspeed)) - k->diry * sin(-k->rotspeed);
		k->diry = k->olddirx * sin(-k->rotspeed)
		+ k->diry * cos(-k->rotspeed);
		k->oldplanex = k->planex;
		k->planex = k->planex * cos(-k->rotspeed)
		- k->planey * sin(-k->rotspeed);
		k->planey = k->oldplanex * sin(-k->rotspeed) +
		k->planey * cos(-k->rotspeed);
	}
	if (k->left == 1)
	{
		k->olddirx = k->dirx;
		k->dirx = k->dirx * cos(k->rotspeed) - k->diry * sin(k->rotspeed);
		k->diry = k->olddirx * sin(k->rotspeed) + k->diry * cos(k->rotspeed);
		k->oldplanex = k->planex;
		k->planex = k->planex * cos(k->rotspeed) - k->planey * sin(k->rotspeed);
		k->planey = k->oldplanex * sin(k->rotspeed)
		+ k->planey * cos(k->rotspeed);
	}
}

void	ft_move(t_struct *ray)
{
	if (ray->down == 1)
	{
		if (ray->worldmap[(int)(ray->player_posx - ray->dirx * ray->movespeed
			* 3)][(int)(ray->player_posy)] == 0)
			ray->player_posx -= ray->dirx * ray->movespeed;
		if (ray->worldmap[(int)ray->player_posx]
			[(int)(ray->player_posy - ray->diry * ray->movespeed * 3)] == 0)
			ray->player_posy -= ray->diry * ray->movespeed;
	}
	if (ray->up == 1)
	{
		if (!ray->worldmap[(int)(ray->player_posx + ray->dirx
			* ray->movespeed * 3)][(int)ray->player_posy])
			ray->player_posx += ray->dirx * ray->movespeed;
		if (!ray->worldmap[(int)ray->player_posx][(int)
			(ray->player_posy + ray->diry * ray->movespeed * 3)])
			ray->player_posy += ray->diry * ray->movespeed;
	}
}

void	hook(t_struct *ray)
{
	int			i;
	SDL_Event	event;

	i = 0;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT || SDLK_ESCAPE == event.key.keysym.sym)
			ray->stop = 0;
		else if (event.type == SDL_KEYUP)
		{
			SDLK_UP == event.key.keysym.sym ? ray->up = 0 : 1;
			SDLK_RIGHT == event.key.keysym.sym ? ray->right = 0 : 1;
			SDLK_LEFT == event.key.keysym.sym ? ray->left = 0 : 1;
			SDLK_DOWN == event.key.keysym.sym ? ray->down = 0 : 1;
		}
		else if (event.type == SDL_KEYDOWN)
		{
			SDLK_UP == event.key.keysym.sym ? ray->up = 1 : 1;
			SDLK_RIGHT == event.key.keysym.sym ? ray->right = 1 : 1;
			SDLK_LEFT == event.key.keysym.sym ? ray->left = 1 : 1;
			SDLK_DOWN == event.key.keysym.sym ? ray->down = 1 : 1;
			SDLK_SPACE == event.key.keysym.sym ? ray->mus = 1 : 1;
			SDLK_a == event.key.keysym.sym ? ray->mus = 10 : 10;
		}
	}
}
