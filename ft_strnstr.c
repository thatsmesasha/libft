/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:06:29 by ofedorov          #+#    #+#             */
/*   Updated: 2016/09/30 15:07:29 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	litlen;
	size_t	biglen;

	i = 0;
	litlen = ft_strlen(little);
	biglen = ft_strlen(big);
	if (biglen < len)
		len = biglen;
	if (len < litlen)
		return (NULL);
	while (i <= len - litlen)
	{
		j = 0;
		while (j < litlen && big[i + j] == little[j])
			j++;
		if (j == litlen)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
