/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 12:17:08 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/17 14:17:14 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_error(char const *error)
{
	if (!error)
		write(STDERR_FILENO, "Error\n", 6);
	else
	{
		write(STDERR_FILENO, "Error: ", 7);
		write(STDERR_FILENO, error, ft_strlen(error));
		write(STDERR_FILENO, "\n", 1);
	}
	exit(EXIT_FAILURE);
}
