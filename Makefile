# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raphox <raphox@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 15:01:28 by raphox            #+#    #+#              #
#    Updated: 2024/03/23 17:56:59 by raphox           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = split.c annexe.c check_args.c error.c initialization.c move.c move2.c push_swap.c sorting.c get_stack_info.c \

OBJS = ${SRCS:.c=.o}
LIBC = ar rcs
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

push_swap : annexe.o split.o move2.o check_args.o error.o initialization.o move.o push_swap.o sorting.o get_stack_info.o
		gcc -o push_swap split.o annexe.o get_stack_info.o move2.o check_args.o error.o initialization.o move.o push_swap.o sorting.o
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