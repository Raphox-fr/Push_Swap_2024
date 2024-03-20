# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 15:01:28 by raphox            #+#    #+#              #
#    Updated: 2024/03/20 17:47:09 by rafaria          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = annexe.c check_args.c error.c initialization.c move.c push_swap.c sorting.c \

OBJS = ${SRCS:.c=.o}
LIBC = ar rcs
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

push_swap : annexe.o check_args.o error.o initialization.o move.o push_swap.o sorting.o
		gcc -o push_swap annexe.o check_args.o error.o initialization.o move.o push_swap.o sorting.o
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS} ${OBJSB}

fclean: clean
	${RM} ${NAME} ${bonus}

re: fclean all

.PHONY : all bonus clean fclean re