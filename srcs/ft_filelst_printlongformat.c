/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelst_printlongformat.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 22:10:00 by ofedorov          #+#    #+#             */
/*   Updated: 2017/02/15 22:10:02 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define SIX_MONTH 15778463

/*
**  The structure is used to determine min number of chars needed to display
**  every field for each file
*/

typedef struct	s_size_of_fields
{
	uint8_t		hard_links;
	uint8_t		user_name;
	uint8_t		group_name;
	uint8_t		file_size;
}				t_size_of_fields;

static quad_t	get_total_blocks(t_list *file_list)
{
	quad_t	total_blocks;
	t_file	*file;

	total_blocks = 0;
	while (file_list)
	{
		file = (t_file*)file_list->content;
		total_blocks += file->blocks;
		file_list = file_list->next;
	}
	return (total_blocks);
}

static void	determine_fields_size(t_list *file_list,
								t_size_of_fields *size_of_fields)
{
	t_file	*file;
	t_list	*node;

	node = file_list;
	while (node)
	{
		file = (t_file*)node->content;
		if (ft_nbrlen(file->hard_links) > size_of_fields->hard_links)
			size_of_fields->hard_links = ft_nbrlen(file->hard_links);
		if (ft_nbrlen(file->file_size) > size_of_fields->file_size)
			size_of_fields->file_size = ft_nbrlen(file->file_size);
		if (ft_strlen(file->user_name) > size_of_fields->user_name)
			size_of_fields->user_name = ft_strlen(file->user_name);
		if (ft_strlen(file->group_name) > size_of_fields->group_name)
			size_of_fields->group_name = ft_strlen(file->group_name);
		node = node->next;
	}
}

/*
**  long format: -rw-r--r--  1 ofedorov  august  1340 Feb  3 11:47 ft_strnstr.c
**  time_string: Thu Nov 24 18:22:48 1986\n\0
**  Fields of long format:
**  <10 chars filemode>2 spaces including @ if specified
**  <nlinks>1 space
**  <user name>2 spaces
**  <group name>2 spaces
**  <size>1 space
**  <3 letter of month>1 space
**  <2 chars of date>1 space
**  <5 chars of time or 1 space+year>1 space
**  <name of file>
**  if link " -> "<name of file linked to>
**  total: 31 + nlinks + user name + group name + size + file name + link name
*/


static void	print_filemode(mode_t mode)
{
	if (FT_ISBLK(mode))
		ft_putchar('b');
	else if (FT_ISCHR(mode))
		ft_putchar('c');
	else if (FT_ISDIR(mode))
		ft_putchar('d');
	else if (FT_ISLNK(mode))
		ft_putchar('l');
	else if (FT_ISSOCK(mode))
		ft_putchar('s');
	else if (FT_ISFIFO(mode))
		ft_putchar('p');
	else if (FT_ISREG(mode))
		ft_putchar('-');
	ft_putchar((mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((mode & S_IROTH) ? 'r' : '-');
	ft_putchar((mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((mode & S_IXOTH) ? 'x' : '-');
}

static void	print_one_longformat(t_file *file, t_size_of_fields *size_of_fields) //TODO check for block/special files and @
{
	char	*time_string;

	print_filemode(file->mode);

	ft_printf("  %*d %*s  %*s  %*d",
				size_of_fields->hard_links, file->hard_links,
				size_of_fields->user_name, file->user_name,
				size_of_fields->group_name, file->group_name,
				size_of_fields->file_size, file->file_size);
	time_string = ctime(&file->time_of_modification);
	ft_putnstr(&time_string[3], 8);
	if (time(NULL) - file->time_of_modification < SIX_MONTH)
		ft_putnstr(&time_string[11], 5);
	else
		ft_putnstr(&time_string[18], 5);
	ft_printf(" %s", file->name);
	if (FT_ISLNK(file->mode))
	{
		ft_putstr(" -> ");
		ft_putstr(file->linking_to);
	}
}

void		ft_filelst_printlongformat(t_list *file_list)
{
	t_size_of_fields	size_of_fields;
	t_list				*node;
	t_file				*file;
	quad_t				total_blocks;

	if (!file_list)
		return ;
	size_of_fields = (t_size_of_fields){0, 0, 0, 0};
	determine_fields_size(file_list, &size_of_fields);
	node = file_list;
	total_blocks = get_total_blocks(file_list);
	ft_printf("%lld total\n", total_blocks);
	while (node)
	{
		file = (t_file*)node->content;
		print_one_longformat(file, &size_of_fields);
		ft_putendl(NULL);
		node = node->next;
	}
}
