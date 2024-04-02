ifndef VERPOSE
.SILENT:
endif

NAME = cub3D

SRC =	main.c \
		error_handle/error.c  error_handle/free.c \
		parsing/texture.c parsing/color.c parsing/texture_utils.c parsing/texture_utils2.c \
		parsing/map_parse.c parsing/map_parse_utils.c parsing/map_parse_utils2.c parsing/map_to_struct.c \
		execution/init.c execution/set_text.c execution/hooks.c execution/set_things.c execution/drawaing.c\
		execution/drawing2.c\
		GNL/get_next_line.c GNL/get_next_line_utils.c \

OBJS = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -Iminilibx -Ilibft -g3 #-fsanitize=address

FFLAGS = -Lminilibx -lmlx -framework OpenGL -framework AppKit

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a minilibx/libmlx.a
	$(CC) $(OBJS) $(FFLAGS) $(CFLAGS) -Llibft -lft -o $(NAME)

%.o: %.c libft/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

minilibx/libmlx.a:
	make -C minilibx

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

