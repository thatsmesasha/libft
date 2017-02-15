/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filecmptime.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 21:55:42 by ofedorov          #+#    #+#             */
/*   Updated: 2017/02/09 21:55:43 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_filecmptime(t_file *file1, t_file *file2)
{
	if (file1->time_of_modification > file2->time_of_modification)
		return (1);
	if (file1->time_of_modification < file2->time_of_modification)
		return (-1);
	return (0);
}
