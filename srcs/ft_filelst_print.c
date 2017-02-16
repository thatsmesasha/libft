/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelst_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 22:12:08 by ofedorov          #+#    #+#             */
/*   Updated: 2017/02/15 22:12:09 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_filelst_print(t_list *file_list)
{
	t_list	*node;
	t_file	*file;

	node = file_list;
	while (node)
	{
		file = (t_file*)node->content;
		ft_putendl(file->name);
		node = node->next;
	}
}
