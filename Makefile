# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ywang2 <ywang2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/15 19:07:02 by ywang2            #+#    #+#              #
#    Updated: 2025/12/19 18:25:06 by ywang2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = check_argv_a.c check_argv_b.c set_stack.c\
		operations_c.c operations_a.c operations_b.c\
		large.c make_move.c cal_cost.c pushswap.c

CFILES = ${addprefix ${SRCS_DIR}, ${SRCS}}

OFILES = ${CFILES:.c=.o}

B_SRCS = check_argv_a_bonus.c check_argv_b_bonus.c\
		operations_a_bonus.c operations_b_bonus.c operations_c_bonus.c\
		make_checker_bonus.c

B_CFILES = ${addprefix ${SRCS_DIR}, ${B_SRCS}}

B_OFILES = ${B_CFILES:.c=.o}

SRCS_DIR = ./src/

INCLUDES = -I ./include

NAME = push_swap

B_NAME = checker

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OFILES}
	cc ${CFLAGS} -o ${NAME} ${OFILES}

bonus: ${B_NAME}

${B_NAME}: ${B_OFILES}
	cc ${CFLAGS} -o ${B_NAME} ${B_OFILES}

%.o: %.c
	cc -c -g ${CFLAGS} ${INCLUDES} $< -o $@

clean:
	rm -f ${OFILES} ${B_OFILES}

fclean: clean
	rm -f ${NAME} ${B_NAME}

re: fclean all

.PHONY: all bonus clean fclean re
