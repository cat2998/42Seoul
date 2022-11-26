/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:13:29 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/27 00:49:03 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*make_map_str(char *sum, char *line)
{
	int		i;
	int		size;
	char	*copy;
	char	*str;

	if (!sum && !line)
		return (0);
	size = ft_find_newline(line);
	copy = (char *)malloc(sizeof(char) * (size + 1));
	if (!copy)
		return (0);
	i = 0;
	while (i < size)
	{
		copy[i] = line[i];
		i++;
	}
	copy[i] = '\0';
	str = ft_strjoin(sum, copy);
	free(line);
	free(copy);
	return (str);
}

void	make_map(char *argv, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd <= 0)
		return ;
	line = get_next_line(fd);
	game->map_height = 1;
	game->map_width = ft_strlen(line) - 1;
	game->map_str = make_map_str(0, line);
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			game->map_height += 1;
			game->map_str = make_map_str(game->map_str, line);
		}
	}
	close(fd);
	return ;
}

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
	int	hole_cnt;
	int	start_cnt;

	i = 0;
	hole_cnt = 0;
	start_cnt = 0;
	game->map_coin = 0;
	while (i < ft_strlen(game->map_str))
	{
		if (game->map_str[i] == 'E')
			hole_cnt++;
		else if (game->map_str[i] == 'C')
			game->map_coin++;
		else if (game->map_str[i] == 'P')
			start_cnt++;
		else if (game->map_str[i] != '0' && game->map_str[i] != '1')
			return (1);
		i++;
	}
	if (hole_cnt == 0 || game->map_coin == 0 || start_cnt != 1)
		return (1);
	game->player_loc = i;
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
	return ;
}
