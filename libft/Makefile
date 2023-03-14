# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lulaens <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 14:15:24 by lulaens           #+#    #+#              #
#    Updated: 2023/03/10 14:39:40 by lulaens          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c \
		ft_isprint.c \
		ft_calloc.c \
		ft_striteri.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_split.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_putchar_fd.c \
		ft_strjoin.c \
		ft_tolower.c \
		ft_isascii.c \
		ft_strlen.c \
		ft_memcpy.c \
		ft_strdup.c \
		ft_strnstr.c \
		ft_bzero.c \
		ft_isdigit.c \
		ft_memmove.c \
		ft_strlcat.c \
		ft_strrchr.c \
		ft_isalnum.c \
		ft_memchr.c \
		ft_memset.c \
		ft_strlcpy.c \
		ft_substr.c \
		ft_isalpha.c \
		ft_memcmp.c \
		ft_strchr.c \
		ft_strncmp.c \
		ft_strcmp.c \
		ft_toupper.c

BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \

FLAGS = -Wall -Wextra -Werror -g 

.c.o:
	clang $(FLAGS) -c $< -o ${<:.c=.o}

OBJ=$(SRC:.c=.o)

OBJ_BONUS=$(BONUS:.c=.o)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

all: $(BONUS)

bonus: $(NAME) $(OBJ_BONUS)
	ar -rcs $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
	/bin/rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
