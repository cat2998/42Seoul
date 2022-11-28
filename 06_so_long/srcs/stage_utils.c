/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:23:38 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/28 21:12:36 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*init_game()
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
	game->coin_cnt = 0;
	game->walk_cnt = 0;
	game->dfs_coin_cnt = 0;
	game->dfs_exit_cnt = 0;
	return (game);
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

int	game_exit(t_game *game)
{
	mlx_destroy_image(game->board->mlx, game->board->img[0]);
	mlx_destroy_image(game->board->mlx, game->board->img[1]);
	mlx_destroy_image(game->board->mlx, game->board->img[2]);
	mlx_destroy_image(game->board->mlx, game->board->img[3]);
	mlx_destroy_image(game->board->mlx, game->board->img[4]);
	mlx_destroy_image(game->board->mlx, game->board->img[5]);
	mlx_destroy_window(game->board->mlx, game->board->win);
	free(game->board);
	free(game->map_str);
	free(game);
	//system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	exit(0);
	return (0);
}

void	move(t_game *game, int m)
{
	if (game->map_str[game->player_loc + m] == '1' ||
		game->map_str[game->player_loc + m] == 'E')
		return ;
	if (game->map_str[game->player_loc + m] == 'C')
		game->coin_cnt++;
	if (game->map_str[game->player_loc + m] == 'O')
	{
		game->walk_cnt++;
		ft_putnbr(game->walk_cnt);
		write(1, "\n", 1);
		game_exit(game);
	}
	game->map_str[game->player_loc] = '0';
	game->map_str[game->player_loc + m] = 'P';
	game->walk_cnt++;
	if (game->map_coin == game->coin_cnt)
		game_clear(game);
	ft_putnbr(game->walk_cnt);
	write(1, "\n", 1);
	return ;
}
