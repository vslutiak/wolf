/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 21:57:09 by vslutiak          #+#    #+#             */
/*   Updated: 2018/10/30 22:12:03 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	size_t	b;
	char	*q;

	i = 0;
	if (!s)
		return (0);
	q = (char*)malloc(sizeof(char) * (len + 1));
	if (!q)
		return (0);
	b = 1;
	while (len > b - 1)
	{
		q[i] = s[start];
		start++;
		i++;
		b++;
	}
	q[i] = '\0';
	return (q);
}
