NAME = solution
CC = cc
CFLAGS = #-Wall -Wextra -Werror -g -O0
ADD_DIR = get_next_line

SRC_FILES = day01.c \
	$(ADD_DIR)/get_next_line_utils.c \
	$(ADD_DIR)/get_next_line.c \

OBJS_FILES = $(SRC_FILES:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(NAME): $(OBJS_FILES)
	$(CC) $(CFLAGS) $(OBJS_FILES) -o $(NAME)

clean:
	rm -f $(OBJS_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
