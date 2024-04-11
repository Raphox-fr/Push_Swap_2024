# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raphox <raphox@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 15:01:28 by raphox            #+#    #+#              #
#    Updated: 2024/04/11 18:28:05 by raphox           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

SRC			=	split.c annexe.c index_stack.c\
				check_args.c error.c initialization.c\
				move.c move2.c push_swap.c sorting.c\
				get_stack_info.c\

OBJ			=	$(SRC:.c=.o)
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
			${RM} $(OBJ)

fclean:
			${RM} $(NAME) ${OBJ}


.PHONY:		all clean fclean re
