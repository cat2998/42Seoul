/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:23:38 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/27 00:56:50 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    game_clear(t_game *game)
{
    int i;

    i = 0;
    while (game->map_str[i] != '\0')
    {
        if (game->map_str[i] == 'E')
            game->map_str[i] = 'O';
        i++;
    }
    return ;
}

void    game_exit(t_game *game)
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
}

void    move(t_game *game, int m)
{
    if (game->map_str[game->player_loc + m] == '1' ||
        game->map_str[game->player_loc + m] == 'E')
        return ;
    if (game->map_str[game->player_loc + m] == 'C')
        game->coin_cnt++;
    if (game->map_str[game->player_loc + m] == 'O')
        game_exit(game);
    game->map_str[game->player_loc] = '0';
    game->map_str[game->player_loc + m] = 'P';
    game->walk_cnt++;
    if (game->map_coin == game->coin_cnt)
        game_clear(game);
    printf("%d\n", game->walk_cnt);
    return ;
}
