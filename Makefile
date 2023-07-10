SRCS	=	src/main.c src/checkmap.c src/initstruct.c src/stockinfo.c \
			src/utils.c src/parsemap.c src/initraycast.c src/error.c src/hook.c \
			src/utils2.c src/move.c src/raycasting.c src/initraycast2.c \
			src/draw.c src/sprite.c

OBJS	= ${SRCS:.c=.o}

CC	= gcc

RM	= rm -f

NAME	= test


all:		${NAME}

%.o: %.c
	$(CC) -I./libft -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L./libft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
						${RM} ${OBJS}

fclean:		clean
						${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
