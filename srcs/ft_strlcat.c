/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:48:41 by ofedorov          #+#    #+#             */
/*   Updated: 2016/09/27 12:45:42 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		chleft;
	char		*cdst;
	const char	*csrc;
	size_t		dstlen;

	cdst = dst;
	csrc = src;
	dstlen = size;
	while (*cdst && dstlen-- != 0)
		cdst++;
	dstlen = cdst - dst;
	chleft = size - dstlen;
	if (chleft == 0)
		return (dstlen + ft_strlen(src));
	while (*csrc && chleft != 1)
	{
		*cdst++ = *csrc++;
		chleft--;
	}
	*cdst = '\0';
	return (dstlen + ft_strlen(src));
}
