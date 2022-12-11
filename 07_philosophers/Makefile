NAME = philosophers

SRCS = philosopher.c

OBJS = $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

%.o:	%.c
		$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re