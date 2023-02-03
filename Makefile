# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 09:57:15 by tcazenav          #+#    #+#              #
#    Updated: 2023/02/02 11:33:13 by lulaens          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = ./src/main.c\
	  ./src/signal.c \
	  ./src/strtok.c \
	  ./src/ft_export.c \
	  ./src/utils_builtins.c
	  #./src/env.c \

LIBFT =  libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g3

OBJ = $(SRC:.c=.o)

%.o: %.c
	clang $(CFLAGS)  -c $< -o $@

all: $(NAME)

$(NAME):$(LIBFT) $(OBJ)
		@clang -s $(CFLAGS) $(OBJ) -lreadline -o $(NAME) | echo "OBJ COMPILED"


$(LIBFT):
	@make -C libft

clean: 
	@make clean -C libft
	rm -f $(OBJ)

fclean:  clean
		@make fclean -C libft
		rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
