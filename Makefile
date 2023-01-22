# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 20:26:37 by bede-car          #+#    #+#              #
#    Updated: 2023/01/22 10:53:42 by bede-car         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIB = ./libftprintf/libftprintf.a

PATH_M = ./mandatory/

MANDATORY = main.c set_fractal.c \
			errors.c events.c \
			render_fractal.c calc_fractal.c 	

PATH_B = ./bonus/

BONUS = main_bonus.c set_fractal_bonus.c \
		errors_bonus.c events_bonus.c \
		render_fractal_bonus.c calc_fractal_bonus.c  

OBJS = $(addprefix $(PATH_M), $(MANDATORY:.c=.o))

OBJS_B = $(addprefix $(PATH_B), $(BONUS:.c=.o))

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