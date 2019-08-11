/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <vslutiak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 21:21:34 by vslutiak          #+#    #+#             */
/*   Updated: 2018/10/29 13:45:30 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t		i;
	char		*cache;

	i = ft_strlen(src);
	cache = (char*)malloc(sizeof(char) * (i + 1));
	if (!cache)
		return (0);
	i = 0;
	while (src[i])
	{
		cache[i] = src[i];
		i++;
	}
	cache[i] = '\0';
	return (cache);
}
