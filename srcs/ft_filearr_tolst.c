/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filearr_tolst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:48:21 by ofedorov          #+#    #+#             */
/*   Updated: 2017/02/07 15:48:22 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_filearr_tolst(t_file **array, int size)
{
	t_list	*new_list;
	int		index;

	index = size - 1;
	new_list = NULL;
	while (index >= 0)
	{
		ft_lstadd(&new_list, ft_lstnew(array[index], sizeof(t_file)));
		index--;
	}
	return (new_list);
}
