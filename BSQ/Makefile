SRCDIR		= ./srcs/
SRCNAME		= main.c			\
			  ft_find_square.c	\
			  ft_general_lib.c	\
			  ft_read_file.c	\
			  ft_split.c		\
			  ft_get.c 			\
			  ft_atoi.c			\
			  ft_check.c		\
			  ft_check2.c

SRCS		= ${addprefix ${SRCDIR}, ${SRCNAME}}

INCDIR		= ./includes/

OBJS		= ${SRCS:.c=.o}

NAME		= BSQ

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:	
			${CC} ${CFLAGS} -I ${INCDIR} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY	= 	all clean fclean re
