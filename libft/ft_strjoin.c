/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 22:12:34 by vslutiak          #+#    #+#             */
/*   Updated: 2018/11/10 17:35:45 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_ft(char *q, const char *s1, const char *s2)
{
	int	i;
	int b;

	i = 0;
	b = 0;
	while (s1[i])
	{
		q[i] = s1[i];
		i++;
	}
	while (s2[b])
	{
		q[i] = s2[b];
		i++;
		b++;
	}
	q[i] = '\0';
	return (q);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		b;
	char	*q;

	i = 0;
	b = 0;
	if (!s1 && s2)
		return ((char *)s2);
	else if (!s2 && s1)
		return ((char *)s1);
	else if (!s1 || !s2)
		return (0);
	while (s1[i])
		i++;
	while (s2[b])
		b++;
	q = (char *)malloc(sizeof(char) * (i + b + 1));
	if (!q)
		return (0);
	i = 0;
	b = 0;
	q = ft_ft(q, s1, s2);
	return (q);
}
