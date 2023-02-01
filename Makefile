# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 09:57:15 by tcazenav          #+#    #+#              #
#    Updated: 2023/02/01 08:08:30 by lulaens          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = ./src/main.c\
	  ./src/current_path.c \
	  ./src/signal.c \
	  ./src/env.c \
	  ./src/init_path.c \
	  ./src/strtok.c

CFLAGS = -Wall -Wextra -Werror -g3

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
		@make -C libft -s && echo "LIBFT COMPILED"
		@clang -s $(CFLAGS) $(OBJ) libft/libft.a -lreadline -o $(NAME) | echo "OBJ COMPILED"

all: $(NAME)

clean: 
	rm -f $(OBJ)

fclean:  clean
		rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
