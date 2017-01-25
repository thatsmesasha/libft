/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textcolor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:05:09 by ofedorov          #+#    #+#             */
/*   Updated: 2017/01/25 11:05:10 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_textcolor(int attr, int fg, int bg)
{
	char	*seq;

	seq = ft_strdup("\033[0;30;40m");
	seq[2] = '0' + attr;
	seq[5] = '0' + fg;
	seq[8] = '0' + bg;
	ft_putstr(seq);
	free(seq);
}
