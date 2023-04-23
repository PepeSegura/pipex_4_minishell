# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 13:27:49 by psegura-          #+#    #+#              #
#    Updated: 2023/04/20 01:24:43 by psegura-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS =					\
		srcs/main.c		\
		srcs/utils.c	\
		srcs/here_doc.c	\
		srcs/childs.c	\
		srcs/exec_cmd.c	\
		srcs/errors.c	\

OBJS = $(SRCS:.c=.o)

LIB = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I inc -I libft  -g3 -fsanitize=address,leak

date := $(shell date +"%a %b %_d %H:%M")

$(NAME): $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo "🏂 pepex Done 🏂"

all: $(NAME)

bonus: $(NAME)

clean:
	@make clean -C libft
	@rm -rf $(OBJS)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

norma:
	@echo 6966205b5b2024286e6f726d696e65747465207c206772657020274572726f7227207c207763202d6c29202d65712030205d5d3b207468656e206e6f726d696e657474653b20656c736520286e6f726d696e65747465207c206772657020274572726f7227293b206669 | xxd -r -p | zsh

commit: fclean
	@git add .
	@./input.sh
	@INPUT_VAR=$$(cat input.txt) && git commit -m "$(date):  $$INPUT_VAR" && rm -f input.txt
	@git push

.PHONY: all clean fclean re norma commit bonus
