# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 20:26:37 by bede-car          #+#    #+#              #
#    Updated: 2023/01/20 20:55:02 by bede-car         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIB = ./libftprintf/libftprintf.a

SOURCE = ./sources/main.c \
		 ./sources/set_fractal.c \
		 ./sources/errors.c \
		 ./sources/events.c \
		 ./sources/render_fractal.c \
		 ./sources/calc_fractal.c 	 


OBJS = $(SOURCE:.c=.o) 

CFLAG = -Imlx -Lmlx -lmlx -lXext -lX11 -lm -Wall -Wextra -Werror -I./includes

MAKEFLAGS = --no-print-directory

HEADER	= ./includes/fractol.h

#.c.o : ${HEADER}
%.o:%.c ${HEADER}
	cc ${CFLAG} -c $< -o $@ 

#all : $(NAME)
all: libftprintf $(NAME)

libftprintf:
	make -C ./libftprintf 

$(NAME) : ${LIB} ${OBJS} 
#	$(MAKE) bonus -C ./libft 
#	mv ./libft/libft.a $(LIB)
	cc ${OBJS} ${LIB} ${CFLAG} -o ${NAME} 

clean :
	rm -f ${OBJS} 
	$(MAKE) clean -C ./libftprintf
	 
fclean : clean
	rm -f ${NAME} 
	rm -f ${LIB}

re : fclean all

.PHONY:	all libftprintf clean fclean re