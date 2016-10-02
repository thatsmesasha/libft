/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfindfirst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:01:00 by ofedorov          #+#    #+#             */
/*   Updated: 2016/10/01 18:17:48 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfindfirst(t_list *lst, void *content, size_t content_size)
{
	if (!lst)
		return (NULL);
	if (!content)
		content_size = 0;
	while (lst)
	{
		if (content_size == lst->content_size &&
			ft_lstequ(content, lst->content, content_size) == 1)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
