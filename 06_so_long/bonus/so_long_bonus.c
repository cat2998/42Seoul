/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:11:02 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/27 23:46:02 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char *argv[])
{
	int		fd;
	t_game	*game;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		return (0);
	game = init_game();
	if (!game)
		return (0);
	make_map(fd, game);
	check_map(game);
	init_stage(game);
	return (0);
}
