/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 19:00:22 by vslutiak          #+#    #+#             */
/*   Updated: 2018/11/05 12:53:17 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*q;
	unsigned char	*b;

	i = 0;
	q = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (n > i)
	{
		if (q[i] != b[i])
			return ((q[i] - b[i]));
		i++;
	}
	return (0);
}
