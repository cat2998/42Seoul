/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:23:38 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/27 18:49:25 by jgwon            ###   ########.fr       */
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
	free(game->board->mlx);
	free(game->board->win);
	free(game->board->img[0]);
	free(game->board->img[1]);
	free(game->board->img[2]);
	free(game->board->img[3]);
	free(game->board->img[4]);
	free(game->board->img[5]);
	free(game->board);
	free(game->map_str);
	free(game);
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
