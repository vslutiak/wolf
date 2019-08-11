/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 21:03:15 by vslutiak          #+#    #+#             */
/*   Updated: 2018/10/30 21:10:46 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*q;

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
		q[i] = f((i), s[i]);
		i++;
	}
	q[i] = '\0';
	return (q);
}
