/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 06:19:39 by vslutiak          #+#    #+#             */
/*   Updated: 2018/11/02 06:38:52 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*f;

	if (!alst || !del)
		return ;
	while (*alst != NULL)
	{
		f = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = f;
	}
	*alst = NULL;
}
