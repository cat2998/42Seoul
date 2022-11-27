/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:13:29 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/27 17:50:24 by jgwon            ###   ########.fr       */
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
	{
		err("File open error\n", game);
		return ;
	}
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
