/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 15:01:48 by ofedorov          #+#    #+#             */
/*   Updated: 2016/10/01 18:18:09 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst)
{
	char	*content;
	size_t	content_size;

	if (!lst)
		ft_putendl("List is empty!");
	while (lst)
	{
		if (lst->content)
		{
			content = (char *)lst->content;
			content_size = lst->content_size;
			while (content_size-- > 0)
			{
				if (ft_isprint(*content) ||
					*content == '\t' || *content == '\v')
					ft_putchar(*content);
				content++;
			}
			ft_putchar('\n');
		}
		else
			ft_putendl("(null)");
		lst = lst->next;
	}
}
