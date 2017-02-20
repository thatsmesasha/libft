/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstif_file_isdir.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 22:04:55 by ofedorov          #+#    #+#             */
/*   Updated: 2017/02/17 22:04:56 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstif_file_isdir(void *content, size_t content_size)
{
	t_file	*file;

	(void)content_size;
	file = (t_file*)content;
	return (FT_ISDIR(file->mode));
}
