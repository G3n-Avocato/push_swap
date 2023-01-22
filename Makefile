# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lamasson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 16:50:55 by lamasson          #+#    #+#              #
#    Updated: 2023/01/22 18:19:45 by lamasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= clang

CFLAGS	= -Wall -Wextra -Werror -g3

RM	= rm -f

NAME	= push_swap

SRCS	= ft_algo_big_opt.c \
	  ft_algo_big_sort.c \
	  ft_algo_big_utils.c \
	  ft_algo_little_sort.c \
	  ft_algo_little_utils.c \
	  ft_instruct_index.c \
	  ft_instruct_lst_d.c \
	  ft_instruct_rule.c \
	  ft_parse_digit.c \
	  ft_parse_max_min.c \
	  ft_parse_sort_and_doublon.c \
	  ft_parse_stack.c \
	  main.c

OBJS	= ${SRCS:%.c=%.o}

LIBFT	= ./libft

LIB	= ./libft/libft.a

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
	@make -C ${LIBFT}
	@${CC} ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}

all:	${NAME}

clean:
	@make -C ${LIBFT} clean
	@${RM} ${OBJS}

fclean: clean
	@make -C ${LIBFT} fclean
	@${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
