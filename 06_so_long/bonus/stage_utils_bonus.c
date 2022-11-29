/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:23:38 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/29 21:22:02 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_game	*init_game(void)
{
	t_game	*game;
	t_board	*board;

	game = malloc(sizeof(t_game) * 1);
	if (!game)
		return (0);
	board = malloc(sizeof(t_board) * 1);
	if (!board)
	{
		free(game);
		return (0);
	}
	game->board = board;
	game->map_str = 0;
	game->map_coin = 0;
	game->player_dir = 0;
	game->coin_cnt = 0;
	game->walk_cnt = 0;
	game->dfs_coin_cnt = 0;
	game->dfs_exit_cnt = 0;
	return (game);
}

void	init_player(void *mlx, t_game *game)
{
	int		w;
	int		h;
	t_board	*tmp;

	tmp = game->board;
	tmp->player[0][0] = mlx_xpm_file_to_image(mlx, "./img/p/d0.xpm", &w, &h);
	tmp->player[0][1] = mlx_xpm_file_to_image(mlx, "./img/p/d1.xpm", &w, &h);
	tmp->player[0][2] = mlx_xpm_file_to_image(mlx, "./img/p/d2.xpm", &w, &h);
	tmp->player[0][3] = mlx_xpm_file_to_image(mlx, "./img/p/d3.xpm", &w, &h);
	tmp->player[1][0] = mlx_xpm_file_to_image(mlx, "./img/p/u0.xpm", &w, &h);
	tmp->player[1][1] = mlx_xpm_file_to_image(mlx, "./img/p/u1.xpm", &w, &h);
	tmp->player[1][2] = mlx_xpm_file_to_image(mlx, "./img/p/u2.xpm", &w, &h);
	tmp->player[1][3] = mlx_xpm_file_to_image(mlx, "./img/p/u3.xpm", &w, &h);
	tmp->player[2][0] = mlx_xpm_file_to_image(mlx, "./img/p/r0.xpm", &w, &h);
	tmp->player[2][1] = mlx_xpm_file_to_image(mlx, "./img/p/r1.xpm", &w, &h);
	tmp->player[2][2] = mlx_xpm_file_to_image(mlx, "./img/p/r2.xpm", &w, &h);
	tmp->player[2][3] = mlx_xpm_file_to_image(mlx, "./img/p/r3.xpm", &w, &h);
	tmp->player[3][0] = mlx_xpm_file_to_image(mlx, "./img/p/l0.xpm", &w, &h);
	tmp->player[3][1] = mlx_xpm_file_to_image(mlx, "./img/p/l1.xpm", &w, &h);
	tmp->player[3][2] = mlx_xpm_file_to_image(mlx, "./img/p/l2.xpm", &w, &h);
	tmp->player[3][3] = mlx_xpm_file_to_image(mlx, "./img/p/l3.xpm", &w, &h);
	return ;
}

void	init_image(void *mlx, void *img[], void *coin[], t_game *game)
{
	int		w;
	int		h;

	img[0] = mlx_xpm_file_to_image(mlx, "./img/land.xpm", &w, &h);
	img[1] = mlx_xpm_file_to_image(mlx, "./img/wall.xpm", &w, &h);
	img[2] = mlx_xpm_file_to_image(mlx, "./img/coin.xpm", &w, &h);
	img[3] = mlx_xpm_file_to_image(mlx, "./img/player.xpm", &w, &h);
	img[4] = mlx_xpm_file_to_image(mlx, "./img/hole_closed.xpm", &w, &h);
	img[5] = mlx_xpm_file_to_image(mlx, "./img/hole_opened.xpm", &w, &h);
	img[6] = mlx_xpm_file_to_image(mlx, "./img/enemy.xpm", &w, &h);
	coin[0] = mlx_xpm_file_to_image(mlx, "./img/coin/coin0.xpm", &w, &h);
	coin[1] = mlx_xpm_file_to_image(mlx, "./img/coin/coin1.xpm", &w, &h);
	coin[2] = mlx_xpm_file_to_image(mlx, "./img/coin/coin2.xpm", &w, &h);
	coin[3] = mlx_xpm_file_to_image(mlx, "./img/coin/coin3.xpm", &w, &h);
	init_player(mlx, game);
	return ;
}

void	game_clear(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_str[i] != '\0')
	{
		if (game->map_str[i] == 'E')
			game->map_str[i] = 'O';
		i++;
	}
	return ;
}

void	set_dir(int dir, t_game *game)
{
	if (dir == 0)
		game->player_dir = 0;
	else if (dir == 1)
		game->player_dir = 1;
	else if (dir == 2)
		game->player_dir = 2;
	else if (dir == 3)
		game->player_dir = 3;
	return ;
}
