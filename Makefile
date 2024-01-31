NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE_DIR = ./includes
SOURCE_DIR = ./sources

CFILES = $(wildcard $(SOURCE_DIR)/*.c)
SOURCES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(SOURCES)
	@echo "\033[92m[.] Building $(NAME)\033[0m"
	@$(CC) $(CFLAGS) $^ -o $@

./$(SOURCE_DIR)/%.o: $(SOURCE_DIR)/%.c ./$(INCLUDE_DIR)/philo.h
	@echo "\033[33m[.] Compiling $<\033[0m"
	@$(CC) $(CFLAGS)  $< -c -o $@

clean:
	@echo "\033[91m[.] Cleaning up\033[0m"
	@rm -rf $(NAME) $(SOURCES)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
