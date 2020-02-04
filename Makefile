# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vniemi <vniemi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/17 14:23:19 by vniemi            #+#    #+#              #
#    Updated: 2020/01/02 18:12:23 by vniemi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
LIBFT = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror
SRC =	main.c board.c ft_dllst.c print.c solver.c math.c \
		free_data.c ft_point2d.c tetromino.c
OBJ =	main.o board.o ft_dllst.o print.o solver.o math.o \
		free_data.o ft_point2d.o tetromino.o

all:		$(NAME)

$(LIBFT):
			make -C ./libft/

$(NAME):	$(LIBFT) $(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

clean:		
			rm -rf $(OBJ)
			make clean -C ./libft/

fclean:		clean
			rm -rf $(NAME)
			make fclean -C ./libft/

re:			fclean all

.PHONY:	all clean fclean re
