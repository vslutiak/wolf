/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:47:02 by vslutiak          #+#    #+#             */
/*   Updated: 2018/11/02 00:54:38 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	size_t	*q;

	i = 0;
	if (!size)
		return (NULL);
	q = (size_t *)malloc(sizeof(size_t) * size);
	if (!q)
		return (NULL);
	while (size)
	{
		q[i] = 0;
		i++;
		size--;
	}
	return (q);
}
