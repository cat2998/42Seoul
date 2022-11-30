/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage_render_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:39:29 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/30 22:34:35 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_walk(t_game *game)
{
	char	*str;

	str = ft_itoa(game->walk_cnt);
	mlx_string_put(game->board->mlx, game->board->win, 28, 36, 0x00000000, str);
	free(str);
	return ;
}

void	render_img(t_game *game, void *img, int i)
{
	mlx_put_image_to_window(game->board->mlx, game->board->win, img, \
					(i % game->map_width) * 64, (i / game->map_width) * 64);
	return ;
}

void	render_img_player(t_game *game, int i)
{
	mlx_put_image_to_window(game->board->mlx, game->board->win, \
				game->board->player[game->player_dir][game->player_loc % 4], \
				(i % game->map_width) * 64, (i / game->map_width) * 64);
	return ;
}

void	render_img_coin(t_game *game, int i, size_t c_i)
{
	mlx_put_image_to_window(game->board->mlx, game->board->win, \
				game->board->coin[c_i % 4], \
				(i % game->map_width) * 64, (i / game->map_width) * 64);
	return ;
}

int	render_stage(t_game *game)
{
	int				i;
	static size_t	c_i;

	i = 0;
	while (game->map_str[i] != '\0')
	{
		if (game->map_str[i] == '0')
			render_img(game, game->board->img[0], i);
		else if (game->map_str[i] == '1')
			render_img(game, game->board->img[1], i);
		else if (game->map_str[i] == 'C')
			render_img_coin(game, i, c_i);
		else if (game->map_str[i] == 'P')
			render_img_player(game, i);
		else if (game->map_str[i] == 'E')
			render_img(game, game->board->img[4], i);
		else if (game->map_str[i] == 'O')
			render_img(game, game->board->img[5], i);
		else if (game->map_str[i] == 'M')
			render_img(game, game->board->img[6], i);
		i++;
	}
	c_i++;
	render_walk(game);
	return (0);
}
