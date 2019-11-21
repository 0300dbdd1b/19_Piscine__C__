SRCS		= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

OBJS		= ${addprefix ${SRCDIR}, ${SRCS:.c=.o}}

NAME		= libft.a

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

SRCDIR		= ./srcs/
INCDIR		= ./includes/

.c.o:
			${CC} ${CFLAGS} -I${INCDIR} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:		${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
