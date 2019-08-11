/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:12:36 by vslutiak          #+#    #+#             */
/*   Updated: 2018/10/30 16:31:35 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *q1;
	char *q2;

	q1 = (char *)dst;
	q2 = (char *)src;
	if (!n || q1 == q2)
		return (dst);
	*q1 = *q2;
	while (n--)
		*q1++ = *q2++;
	return (dst);
}
