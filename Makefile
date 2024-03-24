# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamauss <mamauss@student.42quebec>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/24 15:06:21 by mamauss           #+#    #+#              #
#    Updated: 2024/03/24 15:35:34 by mamauss          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_putchar_fd.c ft_strlcpy.c ft_putchar_arg.c ft_puthexa_arg.c ft_putnbr_base.c ft_putstr_fd.c ft_putstr_arg.c ft_itoa_arg.c ft_uitoa_arg.c ft_printf.c

OBJS = $(SRCS:.c=.o)

-include $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@

clean: 
	rm -f $(OBJS) $(OBJS:.o=.d)

fclean: clean
	rm -f $(NAME)

re: fclean all
