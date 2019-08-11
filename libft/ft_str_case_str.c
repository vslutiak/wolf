/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 02:45:13 by vslutiak          #+#    #+#             */
/*   Updated: 2018/11/04 03:25:38 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_case_str(const char *s1, const char *s2)
{
	int	i;
	int b;
	int c;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		b = 0;
		c = i;
		while (ft_toupper((int)s1[i]) == ft_toupper((int)s2[b]))
		{
			i++;
			b++;
		}
		i = c;
		if (s2[b] == '\0')
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
