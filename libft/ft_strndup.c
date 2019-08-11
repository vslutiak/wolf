/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 11:46:16 by vslutiak          #+#    #+#             */
/*   Updated: 2018/11/03 12:04:42 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*q;
	size_t	i;

	i = 0;
	if (ft_strlen((char *)s1) < n)
		n = ft_strlen((char *)s1);
	q = (char *)malloc(sizeof(char) * (n + 1));
	if (!q)
		return (NULL);
	while (n)
	{
		q[i] = s1[i];
		i++;
		n--;
	}
	q[i] = '\0';
	return (q);
}
