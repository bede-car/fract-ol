# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 20:26:37 by bede-car          #+#    #+#              #
#    Updated: 2023/01/21 22:20:34 by bede-car         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIB = ./libftprintf/libftprintf.a

SOURCE = ./mandatory/main.c \
		 ./mandatory/set_fractal.c \
		 ./mandatory/errors.c \
		 ./mandatory/events.c \
		 ./mandatory/render_fractal.c \
		 ./mandatory/calc_fractal.c 	

BONUS =  ./bonus/main_bonus.c \
		 ./bonus/set_fractal_bonus.c \
		 ./bonus/errors_bonus.c \
		 ./bonus/events_bonus.c \
		 ./bonus/render_fractal_bonus.c \
		 ./bonus/calc_fractal_bonus.c  


OBJS = $(SOURCE:.c=.o) 

OBJS_B = $(BONUS:.c=.o) 

CFLAG = -Imlx -Lmlx -lmlx -lXext -lX11 -lm -Wall -Wextra -Werror -I./includes

MAKEFLAGS = --no-print-directory

HEADER		= ./includes/fractol.h

HEADER_B	= ./includes/fractol_bonus.h

%.o:%.c ${HEADER}
	cc ${CFLAG} -c $< -o $@ 

ifeq ($(wildcard $(OBJS_B)),)
all: libftprintf $(NAME)
else
all: 
endif

ifeq ($(wildcard $(OBJS)),)
bonus : libftprintf  ${OBJS_B}
		@make ${NAME} OBJS="${OBJS_B}" HEADER="${HEADER_B}"
else
bonus: fclean libftprintf ${OBJS_B} 
		@make ${NAME} OBJS="${OBJS_B}" HEADER="${HEADER_B}"
endif

libftprintf:
	make -C ./libftprintf 

$(NAME) : ${LIB} ${OBJS} 
	cc ${OBJS} ${LIB} ${CFLAG} -o ${NAME} 

clean :
	rm -f ${OBJS} ${OBJS_B} 
	$(MAKE) clean -C ./libftprintf
	 
fclean : clean
	rm -f ${NAME} 
	rm -f ${LIB}

re : fclean
	make


.PHONY:	all libftprintf clean fclean re