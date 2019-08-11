/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:34:09 by vslutiak          #+#    #+#             */
/*   Updated: 2018/11/02 00:28:53 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (size)
	{
		str[i++] = '\0';
		size--;
	}
	str[i] = '\0';
	return (str);
}
