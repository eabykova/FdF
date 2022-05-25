# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile_MAC                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: mmicheli <micheli@student.21-school.ru>    +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2021/10/13 19:11:58 by mmicheli          #+#    #+#             #
#   Updated:#    Updated: 2022/05/16 20:27:34 by mmicheli         ###   ########.fr        #
#                                              #
# ************************************************************************** #

NAME	=	libft.a

SRC		=	ft_atoi.c		ft_errors.c		ft_isalnum.c		ft_lstadd_back.c \
			ft_lstlast.c	ft_memchr.c		ft_putchar_fd.c		ft_split.c \
			ft_strchr.c		ft_strjoin.c	ft_strlen.c			ft_strrchr.c \
			ft_tolower.c	ft_printf.c		ft_printf_utils.c	ft_spec_c.c \
			ft_spec_s.c		ft_spec_i_d.c	ft_spec_p.c			ft_spec_xs.c \
			ft_spec_xl.c	ft_spec_u.c		get_next_line.c		get_next_line_utils.c \
			ft_mod.c		ft_htoi.c		get_lines_fd.c

HEAD	=	libft.h
OBJ		=	$(SRC:%.c=%.o)
D_FIL	=	$(SRC:%.c=%.d)

FLAG	=	-Wall -Werror -Wextra
CC		=	gcc

.PHONY	:	all clean fclean re bonus

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	@echo "🚀 Making of libft... 🚀"
	@ar rcs $(NAME) $?

%.o		:	%.c $(HEAD)
	@$(CC) $(FLAG) -c $< -o $@ -MD

include $(wildcard $(D_FIL))

clean	:
	@rm -f $(OBJ) $(D_FIL)

fclean	: clean
	@rm -rf $(NAME)

re		:	fclean all