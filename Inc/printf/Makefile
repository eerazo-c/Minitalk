# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 20:59:01 by eerazo-c          #+#    #+#              #
#    Updated: 2023/10/21 14:38:18 by eerazo-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
SOURCES = ft_printf.c ft_put_char.c ft_put_str.c ft_put_nbr.c ft_put_hex.c ft_put_pointer.c

INCLUDE = -I

HEADER = ft_printf.h

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs

all: $(NAME)

$(NAME): $(OBJECTS) 
	$(AR) $(NAME) $(OBJECTS) 

%.o: %.c $(HEADER)  Makefile
	$(CC) $(CFLAGS) $(INCLUDE)$(HEADER) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
