# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 09:57:15 by tcazenav          #+#    #+#              #
#    Updated: 2023/02/07 15:32:53 by lulaens          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = ./src/builtins.c \
	  ./src/condition_prompt.c\
	  ./src/current_path.c \
	  ./src/ft_env.c \
	  ./src/ft_cd.c \
	  ./src/main.c \
	  ./src/signal.c \
	  ./src/strtok.c \
	  ./src/parse_cmd.c \
	  ./src/parse_cmd_bis.c \
	  ./src/utils_builtins.c \
	  ./src/ft_pwd.c \
	  ./src/ft_export.c \
	  ./src/ft_exit.c \
	  ./src/ft_echo.c \
	  ./src/ft_unset.c

CFLAGS = -Wall -Wextra -Werror -g3

OBJ = $(SRC:.c=.o)

%.o: %.c
	@clang $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
		@make bonus -C libft -s && echo "LIBFT COMPILED"
		@clang $(CFLAGS) $(OBJ) libft/libft.a -lreadline -o $(NAME) | echo "OBJ COMPILED"

all: $(NAME)

clean: 
	@make clean -C libft
	rm -f $(OBJ)

fclean:  clean
		@make fclean -C libft
		rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
