NAME = libftprintf.a

SRCS_DIR = ./srcs/
SRCS_NAME = ft_print_cpercent.c ft_print_di.c ft_print_s.c ft_print_uxXp.c ft_printf.c ft_put.c utils.c

SRCS = $(addprefix $(SRCS_DIR),$(SRCS_NAME))

OBJS = $(SRCS:.c=.o)

BONUS_DIR = ./bonus/
BONUS_NAME = ft_print_cpercent_bonus.c ft_print_di_bonus.c ft_print_s_bonus.c ft_print_uxXp_bonus.c ft_printf_bonus.c ft_put_bonus.c utils_bonus.c

BONUS_SRCS = $(addprefix $(BONUS_DIR),$(BONUS_NAME))

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC		= gcc
RM		= rm -f
AR		= ar crs

CFLAGS	= -Wall -Wextra -Werror

%.o:	%.c
		$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
			$(AR) $@ $^

bonus:		$(BONUS_OBJS)
			$(AR) $(NAME) $^

clean:
			$(RM) $(OBJS)
			$(RM) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus