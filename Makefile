# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ywang2 <ywang2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/15 19:07:02 by ywang2            #+#    #+#              #
#    Updated: 2025/12/16 12:36:04 by ywang2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = check_argv_a.c check_argv_b.c set_stack.c\
		operations_c.c operations_a.c operations_b.c\
		make_move.c cal_cost.c pushswap.c

CFILES = $(addprefix $(SRCS_DIR), $(SRCS))

OFILES = $(CFILES:.c=.o)

SRCS_DIR = ./src/

INCLUDES = -I ./include

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

${NAME}: ${OFILES}
	cc ${CFLAGS} -o ${NAME} ${OFILES}

%.o: %.c
	cc -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
