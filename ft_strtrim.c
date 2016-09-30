/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 12:16:07 by ofedorov          #+#    #+#             */
/*   Updated: 2016/09/27 14:25:06 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char const	*start;
	char const	*end;
	size_t		length;

	length = 0;
	start = s;
	if (!s)
		return (NULL);
	while (*start == '\n' || *start == '\t' || *start == ' ')
		start++;
	if (*start == '\0')
		return (ft_strnew(0));
	end = start + ft_strlen(start) - 1;
	while (*end == '\n' || *end == '\t' || *end == ' ')
		end--;
	return (ft_strsub(s, start - s, end - start + 1));
}
