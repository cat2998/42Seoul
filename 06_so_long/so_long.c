/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:11:02 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/27 00:19:41 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
	int	fd;
	char	*line;
	t_game	*game;

	if (argc != 2)
		return (0);
	game = init_game();
	if (!game)
		return (0);
	make_map(argv[1], game);
	check_map(game);
	init_stage(game);
	return (0);
}
