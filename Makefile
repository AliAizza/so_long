# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 12:10:11 by aaizza            #+#    #+#              #
#    Updated: 2022/02/06 01:38:05 by aaizza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC= get_next_line.c get_next_line_utils.c map_validation.c moves.c render.c ft_putchar.c\
	so_long.c so_long_helpers.c utils.c exit.c split.c ft_printf.c ft_putstr.c

NAME= so_long

CC= gcc

FLAGS= -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

all:		${NAME}

${NAME}:	${SRC}
			${CC} ${FLAGS} ${SRC} -o ${NAME}

clean:
			rm -f ${NAME}

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re