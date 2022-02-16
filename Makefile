# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 20:22:27 by lkrebs-l          #+#    #+#              #
#    Updated: 2022/02/16 00:20:01 by lkrebs-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

SRC =	src/dup42.c \
		src/error.c \
		src/exec_cmd.c \
		src/files.c \
		src/free_all.c \
		src/init_values.c \
		src/main.c \
		src/parse_env.c \
		src/pipes.c \
		src/pipex.c \
		src/treat_space.c \
		src/libft/ft_calloc.c \
		src/libft/ft_split.c \
		src/libft/ft_strchr.c \
		src/libft/ft_strdup.c \
		src/libft/ft_strjoin.c \
		src/libft/ft_strlen.c \
		src/libft/ft_strncmp.c \
		src/libft/ft_strnstr.c \
		src/libft/ft_strrchr.c \
		src/libft/ft_substr.c

CFLAGS = -g3 -Wextra -Werror -Wall

OBJ = $(SRC:.c=.o)

RM = rm -rf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re