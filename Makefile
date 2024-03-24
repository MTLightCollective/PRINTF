# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamauss <mamauss@student.42quebec>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/24 15:06:21 by mamauss           #+#    #+#              #
#    Updated: 2024/03/24 15:11:48 by mamauss          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_putchar_fd.c ft_strlcpy.c ft_putchar_arg.c ft_puthexa_arg.c ft_putnbr_base.c ft_putstr_fd.arg ft_putstr_arg.c ft_itoa_arg.c ft_uitoa_arg.c ft_printf.c

OBJS = $(SRCS: .c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
