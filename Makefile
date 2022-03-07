# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seulah <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 10:25:26 by seulah            #+#    #+#              #
#    Updated: 2021/11/17 10:25:28 by seulah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIST =	srcs/ft_printf.c\
		srcs/ft_putchar_fd.c\
		srcs/ft_strdup.c\
		srcs/ft_putstr_fd.c\
		srcs/ft_itoa.c\
		srcs/ft_print_hex.c\
		srcs/ft_print_ptr.c\
		srcs/ft_print_unsigned.c\
		srcs/ft_printf_utils.c\

OBJ = $(patsubst %.c, %.o, $(LIST))

D_FILES  = $(patsubst %.c, %.d, $(LIST))

OPTFLAGS = -O2

GREEN = \033[0;92m

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?
	@echo "$(GREEN)ft_printf compiled!"

%.o : %.c
	gcc $(FLAGS) $(OPTFLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean :
	@rm -f $(OBJ) $(D_FILES)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONE : all clean fclean re bonus

