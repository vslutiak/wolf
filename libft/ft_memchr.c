/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:27:57 by vslutiak          #+#    #+#             */
/*   Updated: 2018/11/05 12:52:47 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*b;

	b = (char *)s;
	i = 0;
	while (i < n)
	{
		if (b[i] == (char)c)
			return (&b[i]);
		i++;
	}
	return (NULL);
}
