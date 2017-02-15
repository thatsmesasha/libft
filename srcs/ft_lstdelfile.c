/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 19:08:42 by ofedorov          #+#    #+#             */
/*   Updated: 2017/02/05 19:08:46 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelfile(void *file, size_t content_size)
{
	t_file	*file_to_delete;

	file_to_delete = (t_file*)file;
	(void)content_size;
	FREE_IFN_NULL(file_to_delete->name);
	FREE_IFN_NULL(file_to_delete->path);
	FREE_IFN_NULL(file_to_delete->full_name);
	FREE_IFN_NULL(file_to_delete->formatted_info);
	FREE_IFN_NULL(file_to_delete->linking_to);
}
