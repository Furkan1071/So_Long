NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -L./mlx -lmlx -framework AppKit -framework OpenGL
SRCS =	main.c			\
		ft_split.c		\
		game.c			\
		locations.c		\
		map_control.c	\
		map_control2.c	\
		map.c			\
		reader.c		\
		move.c			\
		finish.c		\
OBJS= $(SRCS:.c=.o)
MINI = ./mlx/libmlx.a

B_NAME = so_long_bonus
BONUS_SRCS_DIR = ./bonus/
BSRCS =	$(addprefix $(BONUS_SRCS_DIR),\
		bonus_finish.c		\
 		bonus_ft_split.c		\
		bonus_game.c			\
		bonus_locations.c		\
		bonus_main.c			\
		bonus_map_control.c	\
		bonus_map_control2.c	\
		bonus_map.c			\
		bonus_move.c			\
		bonus_reader.c		\
		enemy_move.c)
BOBJS = $(BSRCS:.c=.o)

all: ${NAME}

$(MINI):
	make -C ./mlx &> /dev/null

$(NAME): $(MINI) $(OBJS)
	$(CC) ${CFLAGS} $(OBJS) -o $(NAME)

%.o: %.c
	${CC} -c $^ -o $@ -Wall -Werror -Wextra -g

bonus: $(B_NAME)

$(B_NAME): $(MINI) $(BOBJS)
	$(CC) ${CFLAGS} $(BOBJS) -o $(B_NAME)

clean:
	rm -rf ${OBJS}
	rm -rf $(BOBJS)
	make clean -C mlx/

fclean: clean
	rm -rf ${NAME}
	rm -rf $(B_NAME)
	make clean -C mlx/

re: fclean all
.PHONY: fclean re all clean bonus
