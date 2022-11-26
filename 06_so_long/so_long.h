/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:13:23 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/26 19:19:14 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"

#include <stdio.h>

typedef struct s_game
{
	int		map_width;
	int		map_height;
	char	*map_str;
	int		map_coin;
	int		coin_cnt;
	int		walk_cnt;
}	t_game;

char	*make_map_str(char *sum, char *line);
void	make_map(char *argv, t_game *game);

#endif