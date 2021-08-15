# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahnys <ahnys@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/30 21:40:24 by ahnys             #+#    #+#              #
#    Updated: 2021/08/15 14:34:17 by ahnys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra # -fsanitize=address

SRCS = philo.c utils.c print.c \
		routine.c \
		ft_atoi.c ft_putnbr_fd.c \
		utils2.c ft_sleep.c
OBJS = $(SRCS:.c=.o)
NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
