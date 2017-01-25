/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelcontent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:40:46 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/19 17:40:50 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdelcontent(void *content, size_t content_size)
{
	(void)content_size;
	ft_bzero(content, content_size);
	free(content);
}
