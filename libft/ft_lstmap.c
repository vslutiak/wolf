/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 07:05:47 by vslutiak          #+#    #+#             */
/*   Updated: 2018/11/03 14:00:27 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*q;
	t_list	*new;
	t_list	*cache;
	t_list	*save;

	if (!lst || !f)
		return (NULL);
	if (!(cache = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	cache = f(lst);
	save = cache;
	q = lst->next;
	while (q != NULL)
	{
		if (!(new = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		new = f(q);
		q = q->next;
		cache->next = new;
		cache = cache->next;
		new = NULL;
	}
	return (save);
}
