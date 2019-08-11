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

int				checkwall(t_struct *wall)
{
	int i;
	int b;

	i = -1;
	b = 0;
	while (wall->worldmap[0][b] <= 9 && wall->worldmap[0][b] >= 1)
		b++;
	if (b != wall->chars)
		return (-1);
	b = 0;
	while (wall->worldmap[wall->lines - 1][b] <= 9
		&& wall->worldmap[wall->lines - 1][b] >= 1)
		b++;
	if (b != wall->chars)
		return (-1);
	while (++i < wall->lines)
		if (wall->worldmap[i][0] > 9 ||
			wall->worldmap[i][0] < 1)
			return (-1);
	i = -1;
	while (++i < wall->lines)
		if (wall->worldmap[i][wall->chars - 1] > 9 ||
			wall->worldmap[i][wall->chars - 1] < 1)
			return (-1);
	return (0);
}

static void		ft_plpos(int b, char **buffer, int i, t_struct *parse)
{
	if (!(ft_strcmp(buffer[b], "P")) && parse->plpos == 0)
	{
		parse->player_posx = i + 0.5;
		parse->player_posy = b + 0.5;
		parse->plpos = 1;
	}
	free(buffer[b]);
}

static int		help_check(t_struct *parse, char *line)
{
	int		i;
	char	**buffer;

	i = 0;
	buffer = ft_strsplit(line, ' ');
	while (buffer[i])
	{
		free(buffer[i]);
		i++;
	}
	if (parse->lines == 0)
		parse->chars = i;
	else
	{
		if (i != parse->chars)
		{
			free(line);
			free(buffer);
			return (-1);
		}
	}
	free(line);
	free(buffer);
	parse->lines++;
	return (0);
}

static int		check(t_struct *parse)
{
	char	*line;
	int		ret;
	int		i;
	size_t	check;

	i = 0;
	line = NULL;
	while ((ret = get_next_line(parse->fd, &line)) > 0)
	{
		if (check != ft_strlen(line) && i > 0)
			parse->space = -1;
		check = ft_strlen(line);
		if (help_check(parse, line) == -1)
			return (-1);
		i++;
	}
	parse->worldmap = ft_memalloc(sizeof(int*) * parse->lines);
	close(parse->fd);
	parse->fd = open(parse->name, O_RDONLY);
	return (0);
}

int				maps(t_struct *parse)
{
	char	*line;
	char	**buffer;
	int		i;
	int		b;
	int		ret;

	i = 0;
	if (check(parse) == -1)
		return (-1);
	while ((ret = get_next_line(parse->fd, &line)) > 0)
	{
		b = 0;
		buffer = ft_strsplit(line, ' ');
		free(line);
		parse->worldmap[i] = ft_memalloc(sizeof(int) * parse->chars);
		while (buffer[b] != NULL)
		{
			parse->worldmap[i][b] = ft_atoi(buffer[b]);
			ft_plpos(b, buffer, i, parse);
			b++;
		}
		free(buffer);
		i++;
	}
	return ((ret == -1) ? -1 : 0);
}
