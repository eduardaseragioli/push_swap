# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/30 14:25:18 by eseragio          #+#    #+#              #
#    Updated: 2026/01/20 19:51:36 by eseragio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
P_PATH=./libs/printf
L_PATH=./libs/libft
GNL_PATH=./libs/getnextline
LIBFT = $(L_PATH)/libft.a
PRINTF = $(P_PATH)/libftprintf.a
GNL = $(GNL_PATH)/libftgetnextline.a
RM = rm -fr
MAKE = make -C
BONUS = checker


ALGORITHM=$(addprefix algorithm/, sort.c alg.c alg_utl.c)
PARSING = $(addprefix parsing/, ft_atol.c numCheck.c)
OPERATIONS = $(addprefix operations/, push.c swap.c rotate.c reverse_rotate.c)

SRC=$(addprefix  srcs/, \
	main.c \
	xor.c \
	free.c \
	ft_make_stack.c \
	ft_stack_utils.c \
	ft_make_stack_utl.c \
	index.c\
	$(PARSING) \
	$(OPERATIONS)\
	$(ALGORITHM))

BONUS_SRC=$(addprefix srcs/, \
	checker.c \
	checker_utl.c\
	xor.c \
	free.c \
	ft_make_stack.c \
	ft_stack_utils.c \
	ft_make_stack_utl.c \
	index.c\
	$(PARSING) \
	$(OPERATIONS)\
	$(ALGORITHM)) \
	libs/getnextline/get_next_line_bonus.c \
	libs/getnextline/get_next_line_utils_bonus.c

OBJ = ${SRC:.c=.o}
BONUS_OBJ = ${BONUS_SRC:.c=.o}

#RULES

all: ${NAME}

bonus: ${BONUS}

${LIBFT}:
	${MAKE} $(L_PATH) --no-print-directory

${PRINTF}:
	${MAKE} $(P_PATH) --no-print-directory

${NAME}: ${OBJ} ${LIBFT} ${PRINTF}
	${CC} ${CFLAGS} ${OBJ} ${LIBFT} $(PRINTF) -o ${NAME}

${BONUS}: ${BONUS_OBJ} ${LIBFT} ${PRINTF}
	${CC} ${CFLAGS} ${BONUS_OBJ} ${LIBFT} ${PRINTF} -o ${BONUS}

clean:
	${MAKE} $(L_PATH) clean
	${MAKE} $(P_PATH) clean
	${RM} ${OBJ} ${BONUS_OBJ}

fclean: clean
	${MAKE} $(L_PATH) fclean
	${MAKE} $(P_PATH) fclean
	${RM} ${NAME} ${BONUS}

re: fclean all

.PHONY: all clean fclean re bonus
