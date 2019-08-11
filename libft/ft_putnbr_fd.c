/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 21:14:03 by vslutiak          #+#    #+#             */
/*   Updated: 2018/11/01 21:20:33 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		n *= (-1);
		ft_putchar_fd('-', fd);
	}
	if (n / 10 > 0)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd(n % 10 + 48, fd);
}