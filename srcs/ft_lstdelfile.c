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

	if (!file)
		return ;
	file_to_delete = (t_file*)file;
	(void)content_size;
//	printf("*** %s ***\n", file_to_delete->full_name);
//	printf("deleting name at %p\n", (void*)file_to_delete->name);
	FREE_IFN_NULL(file_to_delete->name);
//	printf("deleting path at %p\n", (void*)file_to_delete->path);
	FREE_IFN_NULL(file_to_delete->path);
//	printf("deleting full name at %p\n", (void*)file_to_delete->full_name);
	FREE_IFN_NULL(file_to_delete->full_name);
//	printf("deleting link name at %p\n", (void*)file_to_delete->linking_to);
	FREE_IFN_NULL(file_to_delete->linking_to);
//	printf("deleting user name at %p\n", (void*)file_to_delete->user_name);
	FREE_IFN_NULL(file_to_delete->user_name);
//	printf("deleting group name at %p\n", (void*)file_to_delete->group_name);
	FREE_IFN_NULL(file_to_delete->group_name);
	free(file);
}
