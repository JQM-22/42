# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joquinta <joquinta@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/14 13:32:44 by joquinta          #+#    #+#              #
#    Updated: 2026/10/14 13:33:28 by joquinta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

SRCS		= ft_printf.c \
			  ft_check_format.c \
			  ft_print_char.c \
			  ft_print_str.c \
			  ft_print_nbr.c \
			  ft_print_unsigned.c \
			  ft_print_hex.c \
			  ft_print_ptr.c

OBJS		= $(SRCS:.c=.o)

# ------------------------------------------------------------------------------
# REGLAS PRINCIPALES
# ------------------------------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re