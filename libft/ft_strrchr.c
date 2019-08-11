/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 20:09:36 by vslutiak          #+#    #+#             */
/*   Updated: 2018/10/28 21:01:10 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int symbol)
{
	int	i;
	int	f;

	i = 0;
	while (str[i] != '\0')
		i++;
	f = i;
	while (str[--i] != symbol && f > 0)
		f--;
	if (i < 0 && symbol != '\0')
		return (NULL);
	if (str[i] == symbol && symbol != '\0')
		return ((char *)&str[i]);
	if (symbol == '\0')
		return ((char *)&str[ft_strlen(str)]);
	else
		return (NULL);
}
