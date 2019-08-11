/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 21:06:30 by vslutiak          #+#    #+#             */
/*   Updated: 2018/10/29 20:31:33 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *dest, const char *str)
{
	int	i;
	int	b;
	int	q;

	i = 0;
	if (str[i] == '\0')
		return ((char*)&dest[i]);
	while (dest[i])
	{
		b = 0;
		q = i;
		while (str[b] == dest[q])
		{
			if (str[b + 1] == '\0')
				return ((char*)&dest[i]);
			b++;
			q++;
		}
		i++;
	}
	return (NULL);
}
