/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:16:03 by ofedorov          #+#    #+#             */
/*   Updated: 2016/10/01 16:07:09 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*lst;

	if (!alst)
		return ;
	lst = *alst;
	while (lst && lst->next)
		lst = lst->next;
	if (!(*alst))
		*alst = new;
	else
		lst->next = new;
}
