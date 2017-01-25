/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:03:12 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/17 14:35:14 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# define RESET		0
# define BRIGHT 	1
# define DIM		2
# define UNDERLINE 	3
# define BLINK		4
# define REVERSE	7
# define HIDDEN		8

# define BLACK 		0
# define RED		1
# define GREEN		2
# define YELLOW		3
# define BLUE		4
# define MAGENTA	5
# define CYAN		6
# define WHITE		7

# define NOCOLOR	RESET, WHITE, BLACK

/*
**	Part I
*/
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
long long		ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
/*
**	Part II
*/
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
int				ft_putchar(char c);
int				ft_putstr(char const *s);
int				ft_putendl(char const *s);
void			ft_putnbr(int n);
int				ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(char const *s, int fd);
int				ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
/*
**	Bonus part
*/
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
/*
**	Extra
*/
void			ft_lstaddend(t_list **alst, t_list *new);
void			ft_lstprint(t_list *lst);
t_list			*ft_lstfindfirst(t_list *lst, void *content,
				size_t content_size);
t_list			*ft_lstfindlast(t_list *lst, void *content,
				size_t content_size);
int				ft_lstequ(void *content1, void *content2, size_t content_size);
t_list			*ft_lstgetlast(t_list *lst);
void			ft_lstdellast(t_list **lst);
void			ft_lstdelcontent(void *content, size_t content_size);
int 			ft_lstlen(t_list *lst);
/*
**	Math
*/
long long		ft_power(int base, int power);
int 			ft_lstlen(t_list *lst);
/*
**	Wide char
*/
int				ft_putwchar_fd(wchar_t c, int fd);
int				ft_putwchar(wchar_t c);
int				ft_putwstr_fd(wchar_t const *str, int fd);
int				ft_putnwstr_fd(wchar_t const *str, int fd, int length);
int				ft_putnstr_fd(char const *str, int fd, int length);
int				ft_putwstr(wchar_t const *str);
int				ft_putnwstr(wchar_t const *str, int length);
int				ft_putnstr(char const *str, int length);
int				ft_wcharlen(wchar_t wc);
size_t			ft_wstrlen(wchar_t const *str);
int 			ft_lstlen(t_list *lst);
/*
**	Errors
*/
void			ft_error(char const *str);
int 			ft_lstlen(t_list *lst);
/*
**	Console output
*/
void			ft_textcolor(int attr, int fg, int bg);

#endif
