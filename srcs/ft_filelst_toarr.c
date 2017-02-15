/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelst_toarr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:37:25 by ofedorov          #+#    #+#             */
/*   Updated: 2017/02/07 15:37:27 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_file	**ft_filelst_toarr(t_list *lst, int *size)
{
	t_file	**array_of_files;
	t_list	*node;
	int		index;

	if (!lst || !size)
		return (NULL);
	*size = ft_lstlen(lst);
	array_of_files = (t_file**)malloc(sizeof(t_file*) * *size);
	index = 0;
	node = lst;
	while (index < *size)
	{
		array_of_files[index] = (t_file*)node->content;
		node = node->next;
		index++;
	}
	return (array_of_files);
}
