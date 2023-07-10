SRCS	=	src/main.c src/checkmap.c src/initstruct.c src/stockinfo.c \
			src/utils.c src/parsemap.c src/initraycast.c src/error.c src/hook.c \
			src/utils2.c src/move.c src/raycasting.c src/initraycast2.c \
			src/draw.c src/sprite.c libft/ft_strlen.c libft/ft_strjoin.c libft/ft_substr.c \
			libft/ft_atoi.c libft/ft_split.c libft/get_next_line.c libft/get_next_line_utils.c

OBJS	= ${SRCS:.c=.o}

GCC		= gcc -Wall -Werror -Wextra -I./mlx -Lmlx -lmlx

FW		= -framework OpenGL -framework AppKit

RM		= rm -f

NAME	= test


all:		${NAME}

${NAME}:	${OBJS}
						${GCC} ${FW} -o ${NAME} ${OBJS}

clean:
						${RM} ${OBJS}

fclean:		clean
						${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re