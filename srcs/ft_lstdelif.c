/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 22:50:29 by ofedorov          #+#    #+#             */
/*   Updated: 2017/02/15 22:50:30 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelif(t_list **list, int (*needs_to_del)(void *, size_t),
					void (*del)(void *, size_t))
{
	t_list	*previous_node;
	t_list	*current_node;
	t_list	*node_to_delete;
	t_list	*new_start;

	previous_node = NULL;
	new_start = NULL;
	current_node = *list;
	while (current_node)
	{
		if (needs_to_del(current_node->content, current_node->content_size))
		{
			node_to_delete = current_node;
			current_node = current_node->next;
			(previous_node) ? previous_node->next = current_node : (0);
			ft_lstdelone(&node_to_delete, del);
		}
		else
		{
			previous_node = current_node;
			current_node = current_node->next;
		}
		(previous_node && !new_start) ? new_start = previous_node : (0);
	}
	*list = new_start;
}
