/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strqsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:49:44 by ofedorov          #+#    #+#             */
/*   Updated: 2017/02/03 17:49:46 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec_sort(char *strings[], int begin, int end)
{
	register int	left;
	register int	right;
	char			*pivot;

	if (begin >= end)
		return ;
	pivot = strings[begin];
	left = begin;
	right = end;
	while (left < right)
	{
		while (left < end && ft_strcmp(strings[left], pivot) <= 0)
			left++;
		while (ft_strcmp(strings[right], pivot) > 0)
			right--;
		if (left < right)
			ft_strswap(&strings[left], &strings[right]);
	}
	ft_strswap(&strings[begin], &strings[right]);
	rec_sort(strings, begin, left - 1);
	rec_sort(strings, right + 1, end);
}

void	ft_strqsort(char *strings[], int size)
{
	rec_sort(strings, 0, size - 1);
}
