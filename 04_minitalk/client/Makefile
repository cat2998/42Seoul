NAME = client

SRCS_DIR = ./srcs/
SRCS_NAME = client.c

SRCS = $(addprefix $(SRCS_DIR),$(SRCS_NAME))

OBJS = $(SRCS:.c=.o)

BONUS_DIR = ./bonus/
BONUS_NAME = client_bonus.c

BONUS_SRCS = $(addprefix $(BONUS_DIR),$(BONUS_NAME))

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

%.o:	%.c
		$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus:		$(BONUS_OBJS)
			$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)
			$(RM) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus