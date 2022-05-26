NAME = push_swap
NAMEB = checker

SRC = $(wildcard src/*.c)
SRCB = $(wildcard src_bonus/*.c)

INCLUDES = includes

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

$(RM) = rm -rf

.c.o: $(SRC) $(SRCB)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c -o $@ $<

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@

$(NAMEB): $(OBJB)
	$(CC) $(OBJB) -o $@

bonus: $(NAMEB)

all: $(NAME)

clean:
	$(RM) $(OBJ) $(OBJB)

fclean: clean
	$(RM) $(NAME) $(NAMEB)

re: fclean all

100: $(NAME)
	@./$(NAME) `ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`

500: $(NAME)
	@./$(NAME) `ruby -e "puts (-250..250).to_a.shuffle.join(' ')"`