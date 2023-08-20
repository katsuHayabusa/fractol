# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saichaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 17:28:45 by saichaou          #+#    #+#              #
#    Updated: 2023/08/20 13:39:15 by saichaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	= src/

SRC			= main.c fractol.c utils.c utils_2.c window.c launcher.c pixel.c move.c events.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRC))

OBJS_DIR	= obj/

OBJ			= ${SRC:.c=.o}

OBJS		= $(addprefix $(OBJS_DIR), $(OBJ))

NAME		= fractol

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

LIBS		= minilibx-linux/libmlx_Linux.a -L -I minilibx-linux/mlx.h -lXext -lX11 -lm

MINILIBX	= minilibx-linux/libmlx_Linux.a

INCS		= -I ./include/

all:		${OBJS_DIR} ${NAME}

${MINILIBX}:
			make -C minilibx-linux

${OBJS_DIR}:
			mkdir ${OBJS_DIR}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
			${CC} ${CFLAGS} -c $< -o $@ ${INCS}

${NAME}:	${OBJS} ${MINILIBX}
			${CC} ${FLAGS} ${OBJS} ${LIBS} -o ${NAME}

clean:
			rm -rf ${OBJS_DIR} && rm -rf minilibx-linux/obj

fclean:		clean
			rm -f ${NAME} && make clean -C minilibx-linux

re:			fclean all

bonus:		all

.PHONY:		all clean fclean re
