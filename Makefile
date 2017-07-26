# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/24 09:39:33 by vtouffet          #+#    #+#              #
#    Updated: 2017/07/26 20:44:31 by vtouffet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=bsq
SRCS=srcs/display.c srcs/main.c srcs/parser.c srcs/resolve.c srcs/lib/ft_atoi.c srcs/lib/ft_create_elem.c srcs/lib/ft_list_clear.c srcs/lib/ft_list_push_back.c srcs/lib/ft_list_size.c srcs/lib/ft_putchar.c srcs/lib/ft_putstr.c srcs/lib/ft_strcut.c srcs/lib/ft_strlen.c
# TODO: Relinks
all:
	gcc -Wall -Wextra -Werror $(SRCS) -o $(NAME)

clean:
	/bin/rm -f .o # TODO

%.o: %.c

fclean:
	/bin/rm -f $(NAME)

re: fclean all
