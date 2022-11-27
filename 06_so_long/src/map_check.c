/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:49:49 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/27 18:53:52 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_wall(t_game *game)
{
	int	width;
	int	height;

	width = 0;
	while (width < game->map_width)
	{
		if (game->map_str[width] != '1' ||
			game->map_str[game->map_width * (game->map_height - 1) + width] != '1')
			return (1);
		width++;
	}
	height = 1;
	while (height < game->map_height - 1)
	{
		if (game->map_str[game->map_width * height] != '1' ||
			game->map_str[game->map_width * (height + 1) - 1] != '1')
			return (1);
		height++;
	}
	return (0);
}

int	check_map_object(t_game *game)
{
	int	i;
	int	exit_cnt;
	int	start_cnt;

	i = 0;
	exit_cnt = 0;
	start_cnt = 0;
	while (i < ft_strlen(game->map_str))
	{
		if (game->map_str[i] == 'E')
			exit_cnt++;
		else if (game->map_str[i] == 'C')
			game->map_coin++;
		else if (game->map_str[i] == 'P')
		{
			game->player_loc = i;
			start_cnt++;
		}
		else if (game->map_str[i] != '0' && game->map_str[i] != '1')
			return (1);
		i++;
	}
	if (exit_cnt != 1 || game->map_coin == 0 || start_cnt != 1)
		return (1);
	return (0);
}

int check_map_valid_path(t_game *game)
{
	int *visit;

	visit = malloc(sizeof(int) * ft_strlen(game->map_str));
	if (!visit)
		return (1);
	init_visit(visit, ft_strlen(game->map_str));
	game->dfs_visit = visit;
	dfs(game->player_loc, game);
	if (game->dfs_coin_cnt != game->map_coin || game->dfs_exit_cnt != 1)
	{
		free(game->dfs_visit);
		return (1);
	}
	free(game->dfs_visit);
	return (0);
}

void	check_map(t_game *game)
{
	if (game->map_width * game->map_height != ft_strlen(game->map_str))
		err("Map is not rectangle\n", game);
	if (check_map_wall(game))
		err("Map is not surrounded by wall\n", game);
	if (check_map_object(game))
		err("Map don't have necessary object\n", game);
	if (check_map_valid_path(game))
		err("Map don't have valid path\n", game);
	return ;
}
