# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/24 09:39:33 by vtouffet          #+#    #+#              #
#    Updated: 2017/07/26 21:48:16 by vtouffet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=bsq
SRCS=srcs/display.c srcs/main.c srcs/parser.c srcs/resolve.c srcs/lib/ft_atoi.c srcs/lib/ft_create_elem.c srcs/lib/ft_list_clear.c srcs/lib/ft_list_push_back.c srcs/lib/ft_list_size.c srcs/lib/ft_putchar.c srcs/lib/ft_putstr.c srcs/lib/ft_strcut.c srcs/lib/ft_strlen.c
OBJECTS=display.o main.o parser.o resolve.o ft_atoi.o ft_create_elem.o ft_list_clear.o ft_list_push_back.o ft_list_size.o ft_putchar.o ft_putstr.o ft_strcut.o ft_strlen.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRCS)
	gcc  $(OBJECTS) -o $(NAME)

clean:
	/bin/rm -f $(OBJECTS)

fclean:
	/bin/rm -f $(NAME)

re: fclean all
