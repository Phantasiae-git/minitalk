CC		= cc
FLAGS	= -Wall -Werror -Wextra
NAMEC	= client
NAMES	= server
PRINTF	= libftprintf.a
SRCC	=	client.c
SRCS	=	server.c
OBJC	= ${SRCC:.c=.o}
OBJS	= ${SRCS:.c=.o}
BNAMEC	= client_bonus
BNAMES	= server_bonus
BSRCC	=	client_bonus.c
BSRCS	=	server_bonus.c
BOBJC	= ${BSRCC:.c=.o}
BOBJS	= ${BSRCS:.c=.o}
INCLUDE = -I include
RM		= rm -f

all:	$(NAMEC) $(NAMES)

$(NAMEC) : $(OBJC)
		@make -C ft_printf
		$(CC) $(FLAGS) $(OBJC) $(INCLUDE) ft_printf/$(PRINTF) -o $(NAMEC)

$(NAMES) : $(OBJS)
		@make -C ft_printf
		$(CC) $(FLAGS) $(OBJS) $(INCLUDE) ft_printf/$(PRINTF) -o $(NAMES)

bonus:	$(BNAMEC) $(BNAMES)

$(BNAMEC) : $(BOBJC)
		@make -C ft_printf
		$(CC) $(FLAGS) $(BOBJC) $(INCLUDE) ft_printf/$(PRINTF) -o $(BNAMEC)

$(BNAMES) : $(BOBJS)
		@make -C ft_printf
		$(CC) $(FLAGS) $(BOBJS) $(INCLUDE) ft_printf/$(PRINTF) -o $(BNAMES)

clean :
		@make clean -C ft_printf
		${RM} ${OBJC}
		${RM} ${OBJS}
		${RM} ${BOBJC}
		${RM} ${BOBJS}

fclean : clean
		make fclean -C ft_printf
		${RM} $(NAMEC)
		${RM} $(NAMES)
		${RM} ${BNAMEC}
		${RM} ${BNAMES}

re : fclean all

.PHONY:		all bonus clean fclean re

# test:
# 	${CC} ${FLAGS} server.c ft_printf/*.c ft_printf/Libft/*.c -o server
# 	${CC} ${FLAGS} client.c ft_printf/*.c ft_printf/Libft/*.c -o client