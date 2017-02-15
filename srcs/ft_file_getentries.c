/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_getentries.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 22:52:27 by ofedorov          #+#    #+#             */
/*   Updated: 2017/02/14 22:52:30 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	add_to_filelst(char *name, char *path, t_list **file_list)
{
	t_file	*new_file;
	t_list	*new_node;

	new_file = ft_filenew(name, path);
	new_node = ft_lstnew(new_file, sizeof(t_file));
	ft_lstadd(file_list, new_node);
}

t_list		*ft_file_getentries(t_file *directory, char *add_to_error)
{
	t_list			*files_in_directory;
	char			*info_for_error;
	DIR				*directory_stream;
	struct dirent	*new_entry;

	directory_stream = opendir(directory->full_name);
	if (!directory_stream)
	{
		info_for_error = ft_strjoin(add_to_error, directory->name);
		perror(ft_strjoin(add_to_error, directory->name));
		FREE_IFN_NULL(info_for_error);
		return (NULL);
	}
	files_in_directory = NULL;
	while ((new_entry = readdir(directory_stream)))
		add_to_filelst(new_entry->d_name, directory->name, &files_in_directory);
	closedir(directory_stream);
	return (files_in_directory);
}
