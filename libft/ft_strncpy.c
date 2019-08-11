/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:13:23 by vslutiak          #+#    #+#             */
/*   Updated: 2018/11/03 11:39:02 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t num)
{
	size_t	i;
	size_t	j;

	if (!src && !num)
		return (NULL);
	i = ft_strlen(src);
	j = 0;
	while (j < num)
	{
		if (j >= i)
			dest[j] = '\0';
		else
			dest[j] = src[j];
		j++;
	}
	return (dest);
}
