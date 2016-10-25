/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 19:33:06 by ofedorov          #+#    #+#             */
/*   Updated: 2016/10/23 17:33:11 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10000
# include <libft.h>

int				get_next_line(const int fd, char **line);

typedef struct	s_fd
{
	int			fd;
	char		*left;
	size_t		left_size;
	struct s_fd	*next;
	struct s_fd *prev;
}				t_fd;

#endif
