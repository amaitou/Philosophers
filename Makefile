
NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror

CFILES = philo_checker.c \
		 philo_init.c \
		 philo_routine.c \
		 philo_utils.c \
		 philo.c \
		 philo_free.c \

all: $(NAME)

$(NAME): $(CFILES)
	@echo "\033[95m[.] output *.c to philo\033[0m"
	@$(CC) $(CFLAGS) $(CFILES) -o $@

clean:
	@echo "\033[95m[.] remove the executable file\033[0m"
	@rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re