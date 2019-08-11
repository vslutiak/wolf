/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:36:48 by vslutiak          #+#    #+#             */
/*   Updated: 2018/10/28 19:26:02 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int symbol)
{
	char	*src;
	int		i;

	i = 0;
	src = (char *)str;
	while (src[i])
	{
		if (src[i] == symbol)
			return (src + i);
		i++;
	}
	if (src[i] == symbol)
		return (src + i);
	return (NULL);
}
