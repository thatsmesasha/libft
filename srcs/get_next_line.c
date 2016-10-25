/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 19:16:04 by ofedorov          #+#    #+#             */
/*   Updated: 2016/10/23 17:37:57 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <libft.h>

static void	new_fd(t_fd **fds, const int fd, char *left, int left_size)
{
	t_fd	*cur;
	t_fd	*new_el;

	cur = *fds;
	new_el = (t_fd *)malloc(sizeof(t_fd));
	new_el->fd = fd;
	new_el->left = ft_strdup(left);
	new_el->left_size = left_size;
	new_el->next = NULL;
	new_el->prev = NULL;
	while (cur && cur->next)
		cur = cur->next;
	if (cur == NULL)
	{
		*fds = new_el;
		return ;
	}
	cur->next = new_el;
	cur->next->prev = cur;
}

static void	adjust_fd(const int fd, t_list **lst, char *left, int left_size)
{
	static t_fd	*fds = NULL;
	t_fd		*cur;

	cur = fds;
	if (left == NULL)
	{
		while (cur && cur->fd != fd)
			cur = cur->next;
		if (cur != NULL)
		{
			*lst = ft_lstnew(cur->left, cur->left_size);
			if (cur->prev == NULL)
				fds = fds->next;
			else
				(cur->prev)->next = cur->next;
			if (cur->next != NULL)
				(cur->next)->prev = cur->prev;
			free(cur);
		}
		return ;
	}
	if (left_size > 1)
		new_fd(&fds, fd, left, left_size);
}

static char	*create_str(t_list *lst)
{
	t_list	*cur;
	int		size;
	char	*str;

	cur = lst;
	size = 0;
	while (cur)
	{
		size += cur->content_size - 1;
		cur = cur->next;
	}
	str = ft_strnew(size);
	cur = lst;
	while (cur)
	{
		ft_strncat(str, (char *)cur->content, cur->content_size - 1);
		cur = cur->next;
	}
	return (str);
}

static int	read_buff(const int fd, t_list **lst, int *chars_read, char *buff)
{
	int		ret;
	int		i;

	ret = read(fd, buff, BUFF_SIZE);
	buff[BUFF_SIZE] = '\0';
	*chars_read = ret;
	if ((ret == 0 && *lst == NULL) || ret == -1)
		return (ret - 8);
	i = -1;
	while (++i < ret)
		if (buff[i] == '\n')
			break ;
	buff[i] = (buff[i] == '\n') ? '\0' : buff[i];
	ft_lstaddend(lst, ft_lstnew((void*)buff, i + 1));
	return (i);
}

int			get_next_line(const int fd, char **line)
{
	char	buff[BUFF_SIZE + 1];
	t_list	*lst;
	char	*tmp;
	int		ret;
	int		i;

	if (!line)
		return (-1);
	lst = NULL;
	adjust_fd(fd, &lst, NULL, 0);
	if (lst != NULL && (tmp = ft_strchr((char*)(lst->content), '\n')) != NULL)
	{
		*tmp++ = '\0';
		*line = ft_strdup(lst->content);
		adjust_fd(fd, 0, tmp, lst->content_size - (tmp - (char *)lst->content));
		return (1);
	}
	ret = 0;
	while ((i = read_buff(fd, &lst, &ret, buff)) == BUFF_SIZE)
		;
	if (i + 8 == -1)
		return (-1);
	adjust_fd(fd, NULL, buff + i + 1, (i == -8) ? 1 : ret - i);
	*line = create_str(lst);
	return (i == -8) ? 0 : 1;
}
