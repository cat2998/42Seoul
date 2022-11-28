/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:45:19 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/28 21:50:55 by jgwon            ###   ########.fr       */
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

int	is_valid(int x, t_game *game)
{
	if (game->dfs_visit[x] == 1 || game->map_str[x] == '1')
		return (0);
	return (1);
}

void	dfs(int x, t_game *game)
{
	game->dfs_visit[x] = 1;
	if (game->map_str[x] == 'C')
		game->dfs_coin_cnt++;
	if (game->map_str[x] == 'E')
		game->dfs_exit_cnt++;
	if (is_valid(x - game->map_width, game))
		dfs(x - game->map_width, game);
	if (is_valid(x + 1, game))
		dfs(x + 1, game);
	if (is_valid(x + game->map_width, game))
		dfs(x + game->map_width, game);
	if (is_valid(x - 1, game))
		dfs(x - 1, game);
	return ;
}
