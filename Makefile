# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 13:27:49 by psegura-          #+#    #+#              #
#    Updated: 2023/04/15 20:48:49 by psegura-         ###   ########.fr        #
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
CFLAGS = -g3 -fsanitize=address -Wall -Wextra -Werror -I inc -I libft

$(NAME): $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo "🏂 pepex Done 🏂"

all: $(NAME)

clean:
	@make clean -C libft
	@rm -rf $(OBJS)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

norma:
	@if [[ $$(norminette | grep 'Error' | wc -l) -eq 0 ]]; then norminette; else (norminette | grep 'Error'); fi

date := $(shell date +"%a %b %_d %H:%M")

commit: fclean
	@git add .
	@./input.sh
	@INPUT_VAR=$$(cat input.txt) && git commit -m "$(date):  $$INPUT_VAR" && rm -f input.txt
	@git push

.PHONY: all clean fclean re norma commit
