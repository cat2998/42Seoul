/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:13:23 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/27 00:24:17 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"

#include <stdio.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3

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
	int		map_width;
	int		map_height;
	char	*map_str;
	int		player_loc;
	t_board	*board;
	int		map_coin;
	int		coin_cnt;
	int		walk_cnt;
}	t_game;

char	*make_map_str(char *sum, char *line);
void	make_map(char *argv, t_game *game);
int	check_map_wall(t_game *game);
int	check_map_object(t_game *game);
void	check_map(t_game *game);
// void	render_stage(t_game *game);
void	init_stage(t_game *game);
void    move(t_game *game, int m);
t_game	*init_game();
void    err(char *str, t_game *game);

#endif