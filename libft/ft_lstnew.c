/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslutiak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 01:32:19 by vslutiak          #+#    #+#             */
/*   Updated: 2018/11/02 02:23:12 by vslutiak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*r;

	if (!(r = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		r->content = NULL;
		r->content_size = 0;
	}
	else
	{
		r->content = (void*)malloc(sizeof(char) * (content_size + 1));
		if (!r->content)
		{
			free(r);
			return (NULL);
		}
		r->content = ft_memcpy(r->content, content, content_size);
		r->content_size = content_size;
	}
	r->next = NULL;
	return (r);
}
