# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 09:57:15 by tcazenav          #+#    #+#              #
#    Updated: 2023/02/06 09:33:01 by tcazenav         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = ./src/main.c\
	  ./src/current_path.c \
	  ./src/signal.c \
	  ./src/env.c \
	  ./src/strtok.c \
	  ./src/parse_cmd.c \
	  ./src/parse_cmd_bis.c \
	  ./src/is_executable.c \
	  ./src/is_executable_utils.c \
	  ./src/is_pipe.c \
	  ./src/no_pipe.c

#./src/init_path.c \
#./src/condition_prompt.c\

CFLAGS = -Wall -Wextra -Werror -g

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
