/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:40:48 by vslutiak          #+#    #+#             */
/*   Updated: 2019/02/26 20:08:08 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_new_line(char **join, char **line, int fd, int end)
{
	char	*tmp;
	int		len;

	len = 0;
	while (join[fd][len] != '\n' && join[fd][len] != '\0')
		len++;
	if (join[fd][len] == '\n')
	{
		*line = ft_strsub(join[fd], 0, len);
		tmp = ft_strdup(join[fd] + len + 1);
		free(join[fd]);
		join[fd] = tmp;
		if (join[fd][0] == '\0')
			ft_strdel(&join[fd]);
	}
	else if (join[fd][len] == '\0')
	{
		if (end == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(join[fd]);
		ft_strdel(&join[fd]);
	}
	return (1);
}

int		help_gnl(int end, char **join, int fd)
{
	int				i;
	char			*tmp;
	char			buffer[BUFF_SIZE + 1];

	i = 0;
	while ((end = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		i++;
		if (i > 1000000)
			exit(0);
		buffer[end] = '\0';
		if (join[fd] == NULL)
			join[fd] = ft_strnew(1);
		tmp = ft_strjoin(join[fd], buffer);
		free(join[fd]);
		join[fd] = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (end);
}

int		get_next_line(const int fd, char **line)
{
	static char		*join[MAX];
	int				end;

	end = 0;
	if (fd < 0 || line == NULL || BUFF_SIZE < 0)
		return (-1);
	end = help_gnl(end, join, fd);
	if (end < 0)
		return (-1);
	else if (end == 0 && (join[fd] == NULL || join[fd][0] == '\0'))
		return (0);
	return (ft_new_line(join, line, fd, end));
}
