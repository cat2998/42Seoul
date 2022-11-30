/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:45:19 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/30 22:03:36 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_visit(int *visit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		visit[i] = 0;
		i++;
	}
	return ;
}

int	is_valid(int flag, int x, t_game *game)
{
	if (flag == 0)
	{
		if (game->dfs_visit[x] == 1 || game->map_str[x] == '1' || \
			game->map_str[x] == 'E')
			return (0);
	}
	else if (flag == 1)
	{
		if (game->dfs_visit[x] == 1 || game->map_str[x] == '1')
			return (0);
	}
	return (1);
}

void	dfs(int flag, int x, t_game *game)
{
	game->dfs_visit[x] = 1;
	if (flag == 0 && game->map_str[x] == 'C')
		game->dfs_coin_cnt++;
	if (flag == 1 && game->map_str[x] == 'E')
		game->dfs_exit_cnt++;
	if (is_valid(flag, x - game->map_width, game))
		dfs(flag, x - game->map_width, game);
	if (is_valid(flag, x + 1, game))
		dfs(flag, x + 1, game);
	if (is_valid(flag, x + game->map_width, game))
		dfs(flag, x + game->map_width, game);
	if (is_valid(flag, x - 1, game))
		dfs(flag, x - 1, game);
	return ;
}
