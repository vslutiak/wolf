/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:20:17 by vslutiak          #+#    #+#             */
/*   Updated: 2018/10/29 16:02:57 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*q;
	char	*b;

	b = (char *)src;
	q = (char *)dst;
	i = 0;
	if (q <= b)
	{
		while (i < len)
		{
			q[i] = b[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			q[i - 1] = b[i - 1];
			i--;
		}
	}
	return ((void *)q);
}
