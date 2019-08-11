/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:03:49 by vslutiak          #+#    #+#             */
/*   Updated: 2018/11/01 18:59:08 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		n_pointer(char const *s, char c)
{
	int		i;
	int		b;

	i = 0;
	b = 0;
	while (s[i])
	{
		if (s[i] != c && ((s[i + 1] == c) || s[i] != '\0'))
			b++;
		i++;
	}
	return (b);
}

static char		*ft(char const *s, char c, int i)
{
	int		f;
	int		z;
	char	*w;

	f = 0;
	z = i;
	while (s[i] != c && s[i])
	{
		f++;
		i++;
	}
	w = (char *)malloc(sizeof(char) * (f + 1));
	if (!w)
		return (NULL);
	i = 0;
	while (s[z] != c && s[z])
	{
		w[i] = s[z];
		z++;
		i++;
	}
	w[i] = '\0';
	return (w);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		b;
	int		f;
	char	**q;

	f = 0;
	b = 0;
	if (!s || !c)
		return (NULL);
	i = n_pointer(s, c);
	q = (char **)malloc(sizeof(char *) * (i + 1));
	if (!q)
		return (NULL);
	while (s[b])
	{
		if ((s[b] != c && s[b - 1] == c) || (s[b] != c && b == 0))
		{
			q[f] = ft(s, c, b);
			f++;
		}
		b++;
	}
	q[f] = 0;
	return (q);
}
