# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcazenav <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 09:57:15 by tcazenav          #+#    #+#              #
#    Updated: 2023/02/15 15:23:10 by lulaens          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC =	./src/check_cmd.c \
		./src/check_cmd_bis.c \
		./src/condition_prompt.c \
		./src/current_path.c \
		./src/free_utils.c \
		./src/builtins/ft_cd.c \
		./src/builtins/ft_echo.c \
		./src/builtins/ft_env.c \
		./src/builtins/ft_exit.c \
		./src/builtins/export/ft_export.c \
		./src/builtins/ft_pwd.c \
		./src/builtins/ft_unset.c \
		./src/builtins/builtins.c \
		./src/builtins/export/ft_check_export.c \
		./src/builtins/export/utils_export.c \
		./src/builtins/utils_builtins.c \
		./src/builtins/utils_unset.c \
		./src/is_pipe.c \
		./src/main.c \
		./src/no_pipe.c \
		./src/parse_cmd.c \
		./src/parse_cmd_bis.c \
		./src/signal.c \
		./src/strtok.c \

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
