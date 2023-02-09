# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maneddam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 20:56:01 by maneddam          #+#    #+#              #
#    Updated: 2023/01/18 19:13:48 by maneddam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
SRC = ft_atoi.c ft_strchr.c ft_strncmp.c ft_strdup.c ft_split.c  ft_strjoin.c

BSRC = ft_lstnew_bonus.c ft_lstlast_bonus.c ft_lstsize_bonus.c  ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c\
ft_lstiter_bonus.c ft_lstadd_front_bonus.c
OBJ = $(SRC:.c=.o)
OBJB = $(BSRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

bonus : $(OBJB)
	@ar rc $(NAME) $(OBJB)


clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJB)
fclean: clean
	@$(RM) $(NAME)

re: fclean all
