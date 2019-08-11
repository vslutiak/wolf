/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 14:05:18 by vslutiak          #+#    #+#             */
/*   Updated: 2018/10/31 15:17:58 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ft(const char *s)
{
	int	i;
	int	b;
	int	f;

	i = 0;
	b = 0;
	while (s[b] == ' ' || s[b] == '\t' || s[b] == '\n')
		b++;
	while (s[i])
		i++;
	while (s[i - 1] == ' ' || s[i - 1] == '\t' || s[i - 1] == '\n')
		i--;
	f = i - b + 1;
	if (s[b] == '\0')
		f = 1;
	return (f);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	char	*q;
	int		b;

	i = 0;
	b = 0;
	if (!s)
		return (0);
	i = ft_ft(s);
	q = (char*)malloc(sizeof(char) * (i));
	if (!q)
		return (0);
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[i])
	{
		q[b] = s[i];
		b++;
		i++;
	}
	while (q[b - 1] == ' ' || q[b - 1] == '\t' || q[b - 1] == '\n')
		b--;
	q[b] = '\0';
	return (q);
}
