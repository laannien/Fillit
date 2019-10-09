# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djoye <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 11:32:41 by djoye             #+#    #+#              #
#    Updated: 2019/10/09 11:58:31 by djoye            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = algo.c check_file_content.c get_matrix.c main.c push.c saver.c

OBJ = $(SRC:.c=.o)

INCLUDES = ./

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) $(SRC) -o $(NAME) $<

clean:
		@/bin/rm -f $(OBJ)

fclean: clean
		@/bin/rm -f $(NAME) $(OBJ)

re: fclean all
