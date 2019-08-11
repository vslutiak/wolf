/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 19:09:11 by vslutiak          #+#    #+#             */
/*   Updated: 2018/11/01 21:26:33 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft(char *f, int c, int i, int b)
{
	f[i] = '\0';
	while (c >= 1)
	{
		i--;
		if (b == -1 && i == 1)
			f[i - 1] = '-';
		f[i] = (c % 10 + 48);
		c = c / 10;
	}
	return (f);
}

char			*ft_itoa(int n)
{
	int		i;
	int		b;
	int		c;
	char	*f;

	i = 0;
	if (n == 0 && n == -0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		i++;
		n *= -1;
		b = -1;
	}
	c = n;
	while (n >= 1)
	{
		i++;
		n = n / 10;
	}
	if (!(f = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	return (ft(f, c, i, b));
}
