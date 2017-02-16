/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 18:52:07 by ofedorov          #+#    #+#             */
/*   Updated: 2017/02/05 18:52:08 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_file	*ft_filenew(char *name, char *path)
{
	t_file	*new_file;
	char	*path_with_slash;

	new_file = (t_file*)malloc(sizeof(t_file));
	new_file->name = ft_strdup(name);
	new_file->path = ft_strdup(path);
	if (path)
	{
		path_with_slash = ft_strjoin(path, "/");
		new_file->full_name = ft_strjoin(path_with_slash, name);
		free(path_with_slash);
	}
	else
		new_file->full_name = ft_strdup(name);
	new_file->time_of_modification = 0;
	new_file->file_size = 0;
	new_file->blocks = 0;
	new_file->user_id = 0;
	new_file->user_name = NULL;
	new_file->group_name = NULL;
	new_file->group_id = 0;
	new_file->linking_to = NULL;
	new_file->mode = 0;
	new_file->hard_links = 0;
	return (new_file);
}
