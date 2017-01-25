/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdellast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:34:35 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/19 17:34:36 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdellast(t_list **lst)
{
	t_list	*curr;

	if (!lst || !*lst)
		return ;
	if (!(*lst)->next)
	{
		ft_lstdelone(lst, ft_lstdelcontent);
		*lst = NULL;
		return ;
	}
	curr = *lst;
	while (curr->next->next)
		curr = curr->next;
	ft_lstdelone(&(curr->next), ft_lstdelcontent);
	curr->next = NULL;
}
