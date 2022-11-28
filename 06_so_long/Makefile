NAME = so_long

SRCS_DIR = ./srcs/
SRCS_NAME = so_long.c map.c map_check.c dfs.c stage.c stage_utils.c printf.c

SRCS = $(addprefix $(SRCS_DIR),$(SRCS_NAME))
OBJS = $(SRCS:.c=.o)

BONUS_DIR = ./bonus/
BONUS_NAME = so_long_bonus.c map_bonus.c map_check_bonus.c dfs_bonus.c stage_bonus.c stage_utils_bonus.c printf_bonus.c

BONUS_SRCS = $(addprefix $(BONUS_DIR),$(BONUS_NAME))
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

GNL_DIR = ./get_next_line/
GNL_NAME = get_next_line.c get_next_line_utils.c

GNL_SRCS = $(addprefix $(GNL_DIR),$(GNL_NAME))
GNL_OBJS = $(GNL_SRCS:.c=.o)

MLX = ./mlx/

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror
INCLUDE = (-L./mlx) -lmlx -framework OpenGL -framework AppKit

%.o:	%.c
		$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS) $(GNL_OBJS)
			$(MAKE) -C $(MLX)
			$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(NAME)

bonus:		$(BONUS_OBJS) $(GNL_OBJS)
			$(MAKE) -C $(MLX)
			$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(NAME)

clean:
			$(RM) $(OBJS)
			$(RM) $(GNL_OBJS)
			$(RM) $(BONUS_OBJS)
			$(MAKE) -C $(MLX) clean

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus