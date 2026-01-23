# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eseragio <eseragio@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 18:36:59 by eseragio          #+#    #+#              #
#    Updated: 2025/10/23 19:08:16 by eseragio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -fr

SCRS = ft_atoi.c ft_isprint.c ft_putchar_fd.c ft_striteri.c ft_strnstr.c\
       ft_bzero.c ft_itoa.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c\
       ft_calloc.c ft_memchr.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c\
       ft_isalnum.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c\
       ft_isalpha.c ft_memcpy.c ft_split.c ft_strlen.c ft_tolower.c\
       ft_isascii.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c\
       ft_isdigit.c ft_memset.c ft_strdup.c ft_strncmp.c

BONUS = ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstadd_back_bonus.c\
	ft_lstsize_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c\
	ft_lstclear_bonus.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c

OBJS = ${SCRS:.c=.o}
OOBJS = ${BONUS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}
%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@
clean:
	${RM} ${OBJS} ${OOBJS}
	${RM} .bonus

fclean: clean
	${RM} ${NAME}

re: fclean all 

bonus: .bonus

.bonus: ${OBJS} ${OOBJS}
	ar rcs ${NAME} ${OOBJS}
	touch .bonus

.PHONY: all clean fclean re bonus
