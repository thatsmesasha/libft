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
		path_with_slash = ft_strjoin(path, "/");
	else
		path_with_slash = NULL;
	new_file->full_name = ft_strjoin(path_with_slash, name);
	FREE_IFN_NULL(path_with_slash);

	new_file->formatted_info = NULL;

	new_file->time_of_modification = 0;

	return (new_file);
}
