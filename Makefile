# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 12:37:12 by eerazo-c          #+#    #+#              #
#    Updated: 2024/02/19 18:19:50 by eerazo-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME_CLIENT = client
NAME_SERVER = server

SOURCES_CLIENT = src/client.c
SOURCES_SERVER = src/server.c

LIB_PRINTF_PATH = Inc/printf

LIB_PRINTF_H = $(LIB_PRINTF_PATH)/ft_printf.h

OBJECTS_CLIENT = $(SOURCES_CLIENT:.c=.o) 

OBJECTS_SERVER = $(SOURCES_SERVER:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: print $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJECTS_CLIENT) $(LIB_PRINTF_H)
	$(CC) $(CFLAGS) $(LIB_PRINTF_PATH)/libftprintf.a $(SOURCES_CLIENT) -o $@

$(NAME_SERVER): $(OBJECTS_SERVER) $(LIB_PRINTF_H)
	$(CC) $(CFLAGS) $(LIB_PRINTF_PATH)/libftprintf.a $(SOURCES_SERVER) -o $@

print:
	make -C $(LIB_PRINTF_PATH)
	
clean:
	rm -rf $(OBJECTS_CLIENT) $(OBJECTS_SERVER)
	make clean -C $(LIB_PRINTF_PATH)

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	make fclean -C $(LIB_PRINTF_PATH)

re: fclean all

.PHONY: all clean fclean re print
