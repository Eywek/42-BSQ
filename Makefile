# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/24 09:39:33 by vtouffet          #+#    #+#              #
#    Updated: 2017/07/24 14:40:35 by vtouffet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=bsq
SRCS=srcs/*.c srcs/lib/*.c
# TODO: Relink ? Wildcards ?
all:
	gcc $(SRCS) -o $(NAME)

fclean:
	/bin/rm -f $(NAME)

re: fclean all
