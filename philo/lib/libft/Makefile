# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/18 16:42:30 by avilla-m          #+#    #+#              #
#    Updated: 2021/03/01 12:00:47 by avilla-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		libft.a
SRCS = 		$(wildcard *.c)
OBJS = 		$(SRCS:.c=.o)
CC = 		gcc
CFLAGS = 	-Wall -Wextra -Werror
GREEN 				= \033[01;32m
RESET 				= \033[00m

%.o:		%.c 		
			@$(CC) -c $(CFLAGS) $< 

$(NAME): 	$(OBJS)
			@ar rcs $(NAME) $(OBJS)
			@echo "\n$(GREEN)$(NAME) successfully compiled $(RESET)"

all: 		$(NAME)

clean:
			@rm -f $(OBJS)
			@echo "$(GREEN)Successfully cleaned objects  - $(NAME)$(RESET)"

fclean: 	clean
			@rm -f $(OBJS)
			@rm -f $(NAME)
			@echo "$(GREEN)Successfully forced cleaned - $(NAME)$(RESET)"


re:			fclean all

.PHONY: 	all clean fclean re
