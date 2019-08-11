/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:41:53 by vslutiak          #+#    #+#             */
/*   Updated: 2018/11/05 12:49:54 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c,
		size_t n)
{
	unsigned char	*q1;
	unsigned char	*q2;
	size_t			i;

	i = 0;
	q1 = (unsigned char *)dst;
	q2 = (unsigned char *)src;
	while (i < n)
	{
		q1[i] = q2[i];
		if (q2[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
