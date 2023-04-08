
NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror

CFILES = philo_checker.c \
		 philo_init.c \
		 philo_routine.c \
		 philo_utils.c \
		 philo.c \
		 philo_free.c \

all: $(NAME)

$(NAME): $(CFILES)
	$(CC) $(CFLAGS) $(CFILES) -o $@

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re