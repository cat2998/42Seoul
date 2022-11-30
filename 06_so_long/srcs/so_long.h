/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:13:23 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/30 22:04:39 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../get_next_line/get_next_line.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

typedef struct s_board
{
	void	*mlx;
	void	*win;
	void	*img[6];
}	t_board;

typedef struct s_game
{
	t_board	*board;
	int		map_width;
	int		map_height;
	char	*map_str;
	int		map_coin;
	int		player_loc;
	int		coin_cnt;
	int		walk_cnt;
	int		*dfs_visit;
	int		dfs_coin_cnt;
	int		dfs_exit_cnt;
}	t_game;

char	*make_map_str(char *sum, char *line);
void	make_map(int fd, t_game *game);
int		check_map_wall(t_game *game);
int		check_map_object(t_game *game);
int		check_map_valid_path(t_game *game);
void	check_map(t_game *game);
t_game	*init_game(void);
void	game_clear(t_game *game);
int		game_exit(t_game *game);
void	move(t_game *game, int m);
void	render_img(t_game *game, void *img, int i);
void	init_image(void *mlx, void *img[]);
int		render_stage(t_game *game);
int		key_press(int keycode, t_game *game);
void	init_stage(t_game *game);
void	init_visit(int *visit, int size);
int		is_valid(int flag, int x, t_game *game);
void	dfs(int flag, int x, t_game *game);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
void	err(char *str, t_game *game);

#endif