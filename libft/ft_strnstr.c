/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 22:03:23 by vslutiak          #+#    #+#             */
/*   Updated: 2018/11/03 10:55:33 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dst, const char *str, size_t n)
{
	size_t		i;
	size_t		len;
	size_t		j;

	i = 0;
	len = 0;
	j = 0;
	if (str[0] == '\0')
		return ((char *)dst);
	while (dst[i] && i < n)
	{
		len = i;
		while (dst[len] == str[j] && (i + j) < n)
		{
			j++;
			len++;
			if (j == ft_strlen(str))
				return ((char *)&dst[len - j]);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
