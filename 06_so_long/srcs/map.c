/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:13:29 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/28 19:24:00 by jgwon            ###   ########.fr       */
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

void	make_map(int fd, t_game *game)
{
	char	*line;

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
			if (game->map_width != ft_strlen(line) - 1)
				err("Map is not rectangle\n", game);
			game->map_str = make_map_str(game->map_str, line);
		}
	}
	return ;
}
