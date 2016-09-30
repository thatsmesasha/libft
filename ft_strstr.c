/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 19:50:52 by ofedorov          #+#    #+#             */
/*   Updated: 2016/09/24 20:18:40 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;
	size_t	litlen;
	size_t	biglen;

	litlen = ft_strlen(little);
	biglen = ft_strlen(big);
	i = 0;
	if (biglen < litlen)
		return (NULL);
	while (i <= biglen - litlen)
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
