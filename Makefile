# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 11:32:41 by djoye             #+#    #+#              #
#    Updated: 2019/10/14 15:50:41 by uheirloo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = check_file_content.c get_matrix.c main.c save_figure.c fillit.c

OBJ = $(SRC:.c=.o)

INCLUDES = ./

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) -c $(SRC)
		@gcc $(FLAGS) $(OBJ) -o $(NAME) $<

clean:
		@/bin/rm -f $(OBJ)

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all

.PHONY : clean fclean re
