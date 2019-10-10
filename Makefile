# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 11:32:41 by djoye             #+#    #+#              #
#    Updated: 2019/10/10 16:21:43 by uheirloo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = check_file_content.c get_matrix.c main.c saver.c fillit.c push.c #algo.c#

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
