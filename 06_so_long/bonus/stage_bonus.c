/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:56:57 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/29 21:32:29 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	game_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			mlx_destroy_image(game->board->mlx, game->board->player[i][j++]);
		mlx_destroy_image(game->board->mlx, game->board->img[i]);
		mlx_destroy_image(game->board->mlx, game->board->coin[i++]);
	}
	mlx_destroy_image(game->board->mlx, game->board->img[4]);
	mlx_destroy_image(game->board->mlx, game->board->img[5]);
	mlx_destroy_image(game->board->mlx, game->board->img[6]);
	mlx_destroy_window(game->board->mlx, game->board->win);
	free(game->board);
	free(game->map_str);
	free(game);
	exit(0);
	return (0);
}

void	move(int dir, t_game *game, int m)
{
	if (game->map_str[game->player_loc + m] == '1' || \
		game->map_str[game->player_loc + m] == 'E')
		return ;
	if (game->map_str[game->player_loc + m] == 'C')
		game->coin_cnt++;
	if (game->map_str[game->player_loc + m] == 'O' || \
		game->map_str[game->player_loc + m] == 'M')
	{
		render_walk(game);
		game_exit(game);
	}
	game->map_str[game->player_loc] = '0';
	game->player_loc += m;
	game->map_str[game->player_loc] = 'P';
	game->player_dir = dir;
	if (game->map_coin == game->coin_cnt)
		game_clear(game);
	render_walk(game);
	return ;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_S)
		move(0, game, game->map_width);
	else if (keycode == KEY_W)
		move(1, game, -game->map_width);
	else if (keycode == KEY_D)
		move(2, game, 1);
	else if (keycode == KEY_A)
		move(3, game, -1);
	else if (keycode == KEY_ESC)
		game_exit(game);
	return (0);
}

void	init_stage(t_game *game)
{
	game->board->mlx = mlx_init();
	game->board->win = mlx_new_window(game->board->mlx, \
						game->map_width * 64, game->map_height * 64, "my_mlx");
	init_image(game->board->mlx, game->board->img, game->board->coin, game);
	render_stage(game);
	mlx_hook(game->board->win, X_EVENT_KEY_RELEASE, 0, &key_press, game);
	mlx_hook(game->board->win, X_EVENT_KEY_EXIT, 0, &game_exit, game);
	mlx_loop_hook(game->board->mlx, &render_stage, game);
	mlx_loop(game->board->mlx);
	return ;
}
