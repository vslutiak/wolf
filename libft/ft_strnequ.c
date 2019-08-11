/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 21:28:26 by vslutiak          #+#    #+#             */
/*   Updated: 2018/11/02 00:45:36 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		i;
	size_t	b;

	i = 0;
	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	b = 1;
	if (n == 0)
		return (1);
	while (s1[i] == s2[i] && n > b)
	{
		i++;
		b++;
	}
	if (s1[i] != s2[i])
		return (0);
	return (1);
}
