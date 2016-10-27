# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/23 12:56:49 by ofedorov          #+#    #+#              #
#    Updated: 2016/10/26 18:40:41 by ofedorov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	libft.a

SRCSFL 	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
			ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
			ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
			ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_toupper.c ft_tolower.c
SRCSFL	+=	ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
			ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
			ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
			ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCSFL	+=	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
			ft_lstmap.c
SRCSFL	+=	ft_lstaddend.c ft_lstprint.c ft_lstfindfirst.c ft_lstfindlast.c \
			ft_lstequ.c
SRCSFL	+=	get_next_line.c

OBJSFD	=	objs
SRCSFD	=	srcs
INCLFD	=	includes

OBJS	=	$(addprefix $(OBJSFD)/, $(SRCSFL:.c=.o))
SRCS	=	$(addprefix $(SRCSFD)/, $(SRCSFL))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar src $@ $(OBJS)
	ranlib $@

$(OBJSFD):
	mkdir $@

$(OBJSFD)/%.o: $(SRCSFD)/%.c | $(OBJSFD)
	$(CC) $(CFLAGS) -I$(INCLFD) -c $< -o $@

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJSFD)

fclean: clean
	rm -rf $(NAME)

re: fclean all
