/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_file.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:19:57 by ofedorov          #+#    #+#             */
/*   Updated: 2017/02/03 15:19:59 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FILE_H
# define T_FILE_H

# include "ft_ls_options.h"
# include <sys/types.h>

/*
**  Fields of the structure:
**  - name:                  the name of the file
**  - path:                  the path from the primal directory(one that was
**                           called by executable ft_ls)
**  - full_name:             full path to the file
**  - formatted_info:        the line that is formatted according to ft_ls
**                           options
**  - time_of_modification:  time of last modification to the file
**  - mode:                  type of file(directory, link, etc) and permissions
**  - number_of_links:       number of hard links
**  - user_id:               user-id of the owner
**  - group_id:              group-id of the owner
**  - size:                  size of the file in bytes
**  - blocks:                blocks allocated to the file
**  - linking_to:            name of the file that is linked by this file
**  -
**  -
**  -
*/

# define FT_ISBLK(mode) ((mode) & S_IFBLK)
# define FT_ISCHR(mode) ((mode) & S_IFCHR)
# define FT_ISDIR(mode) ((mode) & S_IFDIR)
# define FT_ISFIFO(mode) ((mode) & S_IFIFO)
# define FT_ISREG(mode) ((mode) & S_IFREG)
# define FT_ISLNK(mode) ((mode) & S_IFLNK)
# define FT_ISSOCK(mode) ((mode) & S_IFSOCK)

typedef struct	s_file
{
	char		*name;
	char		*path;
	char		*full_name;
	char 		*formatted_info;

	time_t		time_of_modification;
	mode_t		mode;
	nlink_t		number_of_links;

	uid_t		user_id;
	gid_t		group_id;

	off_t		size;
	quad_t		blocks;

	char		*linking_to;
}				t_file;
//TODO check where to initialize files_inside and where
#endif
