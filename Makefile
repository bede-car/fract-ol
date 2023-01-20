# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 20:26:37 by bede-car          #+#    #+#              #
#    Updated: 2023/01/19 20:59:38 by bede-car         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIB = ./libftprintf/libftprintf.a

SOURCE = ./sources/main.c \
		 ./sources/errors.c \
#		 ./sources/window.c \
#		 ./sources/hooks.c \
#		 ./sources/math.c \
#		 ./sources/fract.c \

OBJECTS = $(FILES:.c=.o) 

CFLAG = -Imlx -Lmlx -lmlx -lXext -lX11 -lm -Wall -Wextra -Werror

MAKEFLAGS = --no-print-directory

HEADER	= ./includes/fractol.h

.c.o : ${HEADER}
	cc ${CFLAG} -c $< -o $@ 

#all : $(NAME)
all: libftprintf $(NAME)

libftprintf:
	make -C ./libftprintf 

$(NAME) : ${LIB} ${OBJS} 
#	$(MAKE) bonus -C ./libft 
#	mv ./libft/libft.a $(LIB)
	cc ${SOURCE} ${LIB} ${CFLAG} -o ${NAME} 

clean :
	rm -f ${OBJS} 
	$(MAKE) clean -C ./libftprintf
	 
fclean : clean
	rm -f ${NAME} 
	rm -f ${LIB}

re : fclean all

.PHONY:	all libftprintf clean fclean re