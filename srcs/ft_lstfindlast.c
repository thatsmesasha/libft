/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfindlast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:02:20 by ofedorov          #+#    #+#             */
/*   Updated: 2016/10/01 17:52:45 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfindlast(t_list *lst, void *content, size_t content_size)
{
	t_list	*found;

	found = NULL;
	if (!lst)
		return (NULL);
	if (!content)
		content_size = 0;
	while (lst)
	{
		if (content_size == lst->content_size &&
			ft_lstequ(content, lst->content, content_size) == 1)
			found = lst;
		lst = lst->next;
	}
	return (found);
}
