SRCS	= ft_isalpha.c \


OBJS	= $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f
AR		= ar crs

CFLAGS	= -Wall -Wextra -Werror

NAME	= libft.a

%.o:	%.c
		$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			$(MAKE) fclean
			$(MAKE) all

$(NAME):	$(OBJS)
			$(AR) $@ $^

.PHONY:		all clean fclean re