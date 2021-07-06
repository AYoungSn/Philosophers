CC = gcc
CFLAGS = -Wall -Werror -Wextra #-lpthread

SRCS = philo.c utils.c print.c \
		routine.c \
		ft_atoi.c ft_putnbr_fd.c
OBJS = $(SRCS:.c=.o)
NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean: rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
