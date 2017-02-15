/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelst_getinfo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 21:44:04 by ofedorov          #+#    #+#             */
/*   Updated: 2017/02/09 21:44:05 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_filelst_getinfo(t_list *files, char *add_to_error)
{
	t_list	*node;

	node = files;
	while (node)
	{
		ft_file_getinfo((t_file*)node->content, add_to_error);
		node = node->next;
	}
}
