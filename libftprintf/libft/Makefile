# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 02:00:34 by bede-car          #+#    #+#              #
#    Updated: 2023/01/21 10:10:52 by bede-car         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c\
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c\
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c\
ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c\
ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_atof.c ft_isnum.c

FILESB	= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstmap.c\
ft_lstdelone.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstiter.c

NAME	= libft.a

OBJS	= $(FILES:.c=.o) 

OBJSB	= $(FILESB:.c=.o) 

CFLAG	= -Wall -Werror -Wextra -I.

MAKEFLAGS = --no-print-directory

HEADER	= libft.h

.c.o : ${HEADER}
	cc ${CFLAG} -c $< -o $@ 
	
all : $(NAME)

$(NAME) : ${OBJS} 
	ar -rcs ${NAME} $^
	
clean :
	rm -f ${OBJS} ${OBJSB}

fclean : clean
	rm -f ${NAME}

re : fclean all

bonus :	${OBJSB}
	@make OBJS="${OBJS} ${OBJSB}" all

.PHONY:	all clean fclean re
