NAME = get_next_line.a
CC = cc
CCFLAGS = -Wall -Wextra -Werror
SRC = get_next_line.o get_next_line_utils.o

all: $(NAME)

$(NAME): $(SRC)
	ar rcs $(NAME) $(SRC)

.o:.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(SRC)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all bonus clean fclean
