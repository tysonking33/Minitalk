# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tytang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 11:11:43 by tytang            #+#    #+#              #
#    Updated: 2022/09/27 13:40:17 by tytang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server.out
CLIENT = client.out
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SFILES = server.c libftprintf.a
CFILES = client.c libftprintf.a
INCLUDES = includes/

all : server client

server :
	$(CC) $(CFLAGS) -I $(INCLUDES) $(SFILES) -o $(SERVER)

client :
	$(CC) $(CFLAGS) -I $(INCLUDES) $(CFILES) -o $(CLIENT)

clean :
	rm -f $(SERVER)
	rm -f $(CLIENT)

fclean : clean
	rm -f $(SERVER) $(CLIENT)
re : clean all

.PHONY : clean all re
