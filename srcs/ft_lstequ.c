/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 16:06:05 by ofedorov          #+#    #+#             */
/*   Updated: 2016/10/01 17:52:18 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstequ(void *content1, void *content2, size_t content_size)
{
	if (!content1 || !content2)
		return (content1 == content2) ? 1 : 0;
	if (content_size == 0)
		return (0);
	return (ft_memcmp((const void *)content1, (const void *)content2,
			content_size) == 0) ? 1 : 0;
}
