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

void	clearsdl(t_struct *ray)
{
	SDL_FreeSurface(ray->surface);
	ray->surface = NULL;
	SDL_DestroyWindow(ray->window);
	ray->window = NULL;
	SDL_Quit();
}

int		main(int ac, char *av[])
{
	t_struct wl;

	if (ac == 2)
	{
		wl.name = av[1];
		wl.fd = open(wl.name, O_RDONLY);
		init(&wl);
		if (maps(&wl) == -1 || wl.plpos == 0 || checkwall(&wl) == -1
			|| checkmaps(&wl) == -1 || wl.space == -1 || sd_init(&wl) == -1)
		{
			ft_putstr("ERROR\n");
			return (0);
		}
		raycast(&wl);
	}
	else
		ft_putstr("USE MAP\n");
	return (0);
}
