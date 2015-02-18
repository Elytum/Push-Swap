# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:54:29 by pfournet          #+#    #+#              #
#    Updated: 2014/12/13 12:55:35 by pfournet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------Compilateur------------------#
CC = cc
CFLAGS = -Wall -Wextra -Werror -O2 -I./includes -I ./libft/includes
#--------------Name-------------------------#
NAME = Push_swap

#--------------Sources----------------------#
FILES =	main.c	\
		ft_lsttools.c \
		utils.c

OBJECT = $(patsubst %.c,%.o,$(FILES))
BASEDIR = ./srcs
#-------------------------------------------#



#--------------Actions----------------------#

all:$(NAME)

$(NAME):
		make re -C ./libft
		$(CC) -c $(CFLAGS) $(addprefix $(BASEDIR)/, $(FILES))
		$(CC) -o $(NAME) $(OBJECT) -L./libft -lft

clean :
		/bin/rm -Rf $(OBJECT)

fclean: clean
		/bin/rm -Rf $(NAME)

re: fclean all
