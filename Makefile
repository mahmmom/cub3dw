ifndef VERPOSE
.SILENT:
endif

NAME = cub3D

SRC =	main.c \
		error_handle/error.c  error_handle/free.c \
		parsing/texture.c parsing/color.c parsing/texture_utils.c parsing/texture_utils2.c\
		parsing/map_parse.c parsing/map_parse_utils.c parsing/map_parse_utils2.c parsing/map_to_struct.c\
		GNL/get_next_line.c GNL/get_next_line_utils.c \

OBJS = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -Ilibft -g3 #-fsanitize=address

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(OBJS) $(CFLAGS) -Llibft -lft -o $(NAME)

%.o: %.c libft/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

libft/libft.a:
	make -C libft

clean:
	$(RM) $(OBJS)
	make -C libft clean
fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re libft/libft.a
