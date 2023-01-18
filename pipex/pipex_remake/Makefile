NAME = pipex

MAIN = pp.c errs.c free.c chd.c

UTILS = ${addprefix utils/, utils_a.c utils_b.c}

SRCS = ${MAIN} ${UTILS}

CFLAGS = -Wall -Werror -Wextra -g3

OBJS = ${SRCS:c=o}

%.o : %.c Makefile
	${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBJS} Makefile
	${CC} ${CFLAGS} ${OBJS} -o $@

all : ${NAME}

re : fclean all

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}
