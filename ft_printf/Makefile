# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tytang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 15:40:57 by tytang            #+#    #+#              #
#    Updated: 2022/09/09 12:30:12 by tytang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

cc = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

FILES = ft_printf \
		ft_printnull \
		ft_printstr \
		ft_printptr \
		ft_printnum \
		ft_print_unsigned_dex \
		ft_printhex \
		ft_printpcent \
		
SRCS_DIR = sources/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = sources/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

