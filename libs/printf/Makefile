# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/04 14:35:21 by eseragio          #+#    #+#              #
#    Updated: 2025/11/04 14:40:39 by eseragio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -fr

SRCS = ft_printfhexacase.c ft_printfputnbr.c\
ft_printf.c ft_printfhexapointer.c ft_printfputstr.c\
ft_printfdecimal.c ft_printfputchar.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
