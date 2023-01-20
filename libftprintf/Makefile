# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 01:13:21 by bede-car          #+#    #+#              #
#    Updated: 2023/01/20 16:40:01 by bede-car         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ./source/ft_printf.c \
		./source/print_character.c \
		./source/print_string.c \
		./source/print_pointer_adress.c \
		./source/print_signed_decimal_integer.c \
		./source/print_unsigned_decimal_integer.c \
		./source/print_unsigned_hexadecimal_integer.c \
				
NAME = libftprintf.a

OBJS	= $(FILES:.c=.o) 

CFLAG	= -Wall -Werror -Wextra

MAKEFLAGS = --no-print-directory

HEADER	= ft_printf.h

.c.o : ${HEADER}
	cc ${CFLAG} -c $< -o $@ 

all : $(NAME)

$(NAME) : ${OBJS} 
	$(MAKE) bonus -C ./libft 
	mv ./libft/libft.a $(NAME)
	ar -rc ${NAME} $^

clean :
	rm -f ${OBJS} 
	$(MAKE) clean -C ./libft
	 
fclean : clean
	rm -f ${NAME} 

re : fclean all

.PHONY:	all clean fclean re