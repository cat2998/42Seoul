/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:11:02 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/30 23:36:55 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file_name(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (len < 4 || \
		argv[len - 4] != '.' || argv[len - 3] != 'b' || \
		argv[len - 2] != 'e' || argv[len - 1] != 'r')
	{
		write(2, "Error\n", 6);
		ft_putstr("File name error\n");
		exit(0);
	}
	return ;
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_game	*game;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
	{
		ft_putstr("Error\nFile open error\n");
		return (0);
	}
	check_file_name(argv[1]);
	game = init_game();
	if (!game)
		return (0);
	make_map(fd, game);
	check_map(game);
	init_stage(game);
	return (0);
}
