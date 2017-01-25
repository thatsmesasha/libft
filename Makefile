# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/23 12:56:49 by ofedorov          #+#    #+#              #
#    Updated: 2017/01/19 11:03:33 by ofedorov         ###   ########.fr        #
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
			ft_lstequ.c ft_lstgetlast.c ft_lstdelcontent.c ft_lstdellast.c \
			ft_lstlen.c
SRCSFL	+=	get_next_line.c
SRCSFL	+=	ft_power.c ft_putwchar_fd.c ft_putwchar.c ft_putwstr.c \
			ft_putwstr_fd.c ft_putnwstr.c ft_putnwstr_fd.c ft_putnstr.c \
			ft_putnstr_fd.c ft_wcharlen.c ft_wstrlen.c ft_error.c
SRCSFL	+=	ft_printf.c
PRNTFFD	+=	ft_printf_utils
PRNTFFL	+=	format_a.c format_another.c format_c.c format_d.c format_e.c \
			format_f.c format_i.c format_o.c format_p.c format_s.c \
			format_u.c format_x.c ft_double_utils.c ft_printf_format.c \
			ft_printf_checking_format.c ft_printf_get_value.c \
			ft_printf_read_format.c ft_printf_read_utils.c \
			ft_printf_write.c
SRCSFL	+=	$(addprefix $(PRNTFFD)/, $(PRNTFFL))
SRCSFL  +=  ft_textcolor.c

OBJSFD	=	objs
SRCSFD	=	srcs
INCLFD	=	includes

ADDFDS	+=	$(PRNTFFD)

ADDFD	=	$(addprefix $(OBJSFD)/, $(ADDFDS))

OBJS	=	$(addprefix $(OBJSFD)/, $(SRCSFL:.c=.o))
SRCS	=	$(addprefix $(SRCSFD)/, $(SRCSFL))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

RED		=	\033[0;31m
GREEN	=	\033[0;32m
NC		=	\033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Libft objects created.$(NC)"
	@ar src $@ $(OBJS)
	@ranlib $@
	@echo "$(GREEN)Libft created.$(NC)"

$(OBJSFD):
	@mkdir $@ $(ADDFD)

$(OBJSFD)/%.o: $(SRCSFD)/%.c | $(OBJSFD)
	@$(CC) $(CFLAGS) -I$(INCLFD) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@echo "$(RED)Libft objects deleted.$(NC)"
	@rm -rf $(OBJSFD)

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Libft deleted.$(NC)"

re: fclean all
