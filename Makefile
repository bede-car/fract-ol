# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 20:26:37 by bede-car          #+#    #+#              #
#    Updated: 2023/01/22 19:16:31 by bede-car         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	fractol

MANDATORY	=	main.c set_fractal.c \
				errors.c events.c \
				render_fractal.c calc_fractal.c

BONUS		=	main_bonus.c set_fractal_bonus.c \
				errors_bonus.c events_bonus.c \
				render_fractal_bonus.c calc_fractal_bonus.c

PATH_M		=	./mandatory/
PATH_B		=	./bonus/

OBJS		=	$(addprefix $(PATH_M), $(MANDATORY:.c=.o))
OBJS_B		=	$(addprefix $(PATH_B), $(BONUS:.c=.o))

CFLAG		=	-lmlx -lX11 -lXext -Imlx -lm -Wall -Wextra -Werror

MAKEFLAGS	=	--no-print-directory

HEADER		=	-I./includes/fractol.h
HEADER_B	=	-I./includes/fractol_bonus.h

LIB 		=	./libftprintf/libftprintf.a

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
	@make -C ./libftprintf

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