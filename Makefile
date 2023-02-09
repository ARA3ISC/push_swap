# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maneddam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 03:05:54 by maneddam          #+#    #+#              #
#    Updated: 2023/02/03 19:26:06 by maneddam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
B_NAME = checker
CC = cc
CFLAGS = -Werror -Wextra -Wall
SRC = src/push_swap.c src/error.c src/utils.c src/instructions.c src/sorting.c  src/ft_free.c src/large_sort.c src/large_sort_utils.c\
src/large_sort_utils1.c libft/ft_atoi.c printf/ft_printf.c printf/ft_putchar.c printf/ft_putnbr.c printf/ft_putnbr_add.c \
printf/ft_putnbr_u_dec.c printf/ft_putstr.c printf/ft_strlen.c libft/ft_split.c libft/ft_strjoin.c  libft/ft_strdup.c libft/ft_strchr.c \
libft/ft_strncmp.c libft/ft_lstclear_bonus.c libft/ft_lstdelone_bonus.c src/instructions_utils.c src/large_sort_utils2.c

B_SRC = src_b/checker.c src_b/utils.c libft/ft_atoi.c libft/ft_strjoin.c libft/ft_strdup.c printf/ft_strlen.c printf/ft_printf.c \
printf/ft_putchar.c printf/ft_putnbr.c printf/ft_putnbr_add.c libft/ft_split.c  \
printf/ft_putnbr_u_dec.c printf/ft_putstr.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c libft/ft_strchr.c \
src_b/utils1.c src_b/utils2.c src_b/operators.c src_b/is_valid.c src_b/operators_utils.c
OBJ = $(SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)

all: $(NAME)

bonus: $(B_NAME)


$(NAME): $(OBJ)
	@echo "\033[0;32m\n\nCompiling push_swap..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "\n\033[38;5;200mDone !"

$(B_NAME): $(B_OBJ)
	@echo "\033[0;32m\n\nCompiling checker..."
	@$(CC) $(CFLAGS) -o $(B_NAME) $(B_OBJ)
	@echo "\n\033[38;5;200mDone !"

%.o: %.c
	@printf "\033[0;33mGenerating objects... %-100.900s\r" $@
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "\033[0;31m\nDeleting objects..."
	@rm -f $(OBJ)
	@rm -f $(B_OBJ)
	@echo "\033[0m"

fclean:
	@echo "\033[0;31m\nDeleting objects..."
	@rm -f $(OBJ)
	@rm -f $(B_OBJ)
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@rm -f $(B_NAME)
	@echo "\033[0m"

re: fclean all bonus
