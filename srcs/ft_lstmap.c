/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 12:04:34 by ofedorov          #+#    #+#             */
/*   Updated: 2016/09/28 12:18:44 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*elem_curr;
	t_list	*list;

	list = NULL;
	if (!lst)
		return (NULL);
	if (lst->next != NULL)
	{
		list = ft_lstmap(lst->next, f);
		if (list == NULL)
			return (NULL);
	}
	elem_curr = f(lst);
	if (!elem_curr)
		return (NULL);
	ft_lstadd(&list, elem_curr);
	return (elem_curr);
}
