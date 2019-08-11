/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 20:26:21 by vslutiak          #+#    #+#             */
/*   Updated: 2018/10/30 21:00:44 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*q;

	i = 0;
	if (!s || !f)
		return (0);
	while (s[i])
	{
		i++;
	}
	q = (char *)malloc(sizeof(char) * (i + 1));
	if (!q)
		return (0);
	i = 0;
	while (s[i])
	{
		q[i] = f(s[i]);
		i++;
	}
	q[i] = '\0';
	return (q);
}
