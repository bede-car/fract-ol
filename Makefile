NAME = fractol

LIB = ./libft/libft.a

SOURCE = ./src/main.c \
		 ./src/error.c \
		 ./src/window.c \
		 ./src/hooks.c \

OBJECTS = $(FILES:.c=.o) 

CFLAG = -Imlx -Lmlx -lmlx -lXext -lX11 -lm -Wall -Wextra -Werror

MAKEFLAGS = --no-print-directory

HEADER	= ./includes/fractol.h

.c.o : ${HEADER}
	cc ${CFLAG} -c $< -o $@ 

#all : $(NAME)
all: libft $(NAME)

libft:
	make bonus -C ./libft 

$(NAME) : ${LIB} ${OBJS} 
#	$(MAKE) bonus -C ./libft 
#	mv ./libft/libft.a $(LIB)
	cc ${SOURCE} ${LIB} ${CFLAG} -o ${NAME} 

clean :
	rm -f ${OBJS} 
	$(MAKE) clean -C ./libft
	 
fclean : clean
	rm -f ${NAME} 
	rm -f ${LIB}

re : fclean all

.PHONY:	all libft clean fclean re