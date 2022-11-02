NAME = push_swap

SRCS = lis.c stack_utils.c a_to_b.c push_swap.c start_push_swap.c b_to_a.c utils.c b_to_a_utils.c ft_split.c stack_commands.c

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