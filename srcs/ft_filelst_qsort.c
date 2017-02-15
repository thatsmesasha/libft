/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelst_qsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 11:20:14 by ofedorov          #+#    #+#             */
/*   Updated: 2017/02/06 11:20:15 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	file_swap(t_file **file1, t_file **file2)
{
	t_file	*tmp;

	tmp = *file1;
	*file1 = *file2;
	*file2 = tmp;
}

static void	rec_sort(t_file *files[], int begin, int end,
						int (*file_compare)(t_file*, t_file*))
{
	register int	left;
	register int	right;
	t_file			*pivot;

	if (begin >= end)
		return ;
	pivot = files[begin];
	left = begin;
	right = end;
	while (left < right)
	{
		while (left < end && file_compare(files[left], pivot) <= 0)
			left++;
		while (file_compare(files[right], pivot) > 0)
			right--;
		if (left < right)
			file_swap(&files[left], &files[right]);
	}
	file_swap(&files[begin], &files[right]);
	rec_sort(files, begin, left - 1, file_compare);
	rec_sort(files, right + 1, end, file_compare);
}

void	ft_filelst_qsort(t_list **lst, int (*file_compare)(t_file*, t_file*))
{
	int		size;
	t_file	**array_of_files;
	t_list	*sorted_list;

	if (!lst || !(*lst))
		return ;
	array_of_files = ft_filelst_toarr(*lst, &size);
	rec_sort(array_of_files, 0, size - 1, file_compare);
	sorted_list = ft_filearr_tolst(array_of_files, size);
	ft_lstdel(lst, ft_lstnotdelcontent);
	//here check if segfault?
	*lst = sorted_list;
}
