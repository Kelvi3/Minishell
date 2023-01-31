# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 09:57:15 by tcazenav          #+#    #+#              #
#    Updated: 2023/01/31 10:20:08 by tcazenav         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = ./src/main.c\
	  	./src/current_path.c

CFLAGS = -Wall -Wextra -Werror -g3

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
			clang $(OBJ) -o $(NAME) -lreadline

all: $(NAME)

clean:	rm -rf $(OBJ)

fclean:  clean
		rm -rf $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
