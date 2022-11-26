/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:35:56 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/27 00:29:07 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game    *init_game()
{
    t_game  *game;
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
    game->coin_cnt = 0;
    game->walk_cnt = 0;
	return (game);
}

void    err(char *str, t_game *game)
{
    int i;
    int size;

    write(2, "Error\n", 6);
    size = ft_strlen(str);
    i = 0;
    while (i < size)
    {
        write(1, &str[i], 1);
        i++;
    }
    free(game);
    exit(0);
}