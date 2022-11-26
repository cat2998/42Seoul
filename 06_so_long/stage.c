/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:56:57 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/27 00:49:33 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    render_img(t_game *game, void *img, int i)
{
    mlx_put_image_to_window(game->board->mlx, game->board->win, img, (i % game->map_width) * 64, (i / game->map_width) * 64);
    return ;
}

void    init_image(void *mlx, void *img[])
{
    int img_width;
	int img_height;

    img[0] = mlx_xpm_file_to_image(mlx, "./images/land.xpm", &img_width, &img_height);
	img[1] = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &img_width, &img_height);
	img[2] = mlx_xpm_file_to_image(mlx, "./images/coin.xpm", &img_width, &img_height);
	img[3] = mlx_xpm_file_to_image(mlx, "./images/player.xpm", &img_width, &img_height);
	img[4] = mlx_xpm_file_to_image(mlx, "./images/hole_closed.xpm", &img_width, &img_height);
	img[5] = mlx_xpm_file_to_image(mlx, "./images/hole_opened.xpm", &img_width, &img_height);
    return ;
}

int	render_stage(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_str[i] != '\0')
	{
		if (game->map_str[i] == '0')
            render_img(game, game->board->img[0], i);
		else if (game->map_str[i] == '1')
            render_img(game, game->board->img[1], i);
		else if (game->map_str[i] == 'C')
            render_img(game, game->board->img[2], i);
		else if (game->map_str[i] == 'P')
        {
            render_img(game, game->board->img[3], i);
            game->player_loc = i;
        }
		else if (game->map_str[i] == 'E')
            render_img(game, game->board->img[4], i);
		else if (game->map_str[i] == 'O')
            render_img(game, game->board->img[5], i);
		i++;
	}
	return (0);
}

int key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move(game, -game->map_width);
	else if (keycode == KEY_S)
		move(game, game->map_width);
	else if (keycode == KEY_A)
		move(game, -1);
	else if (keycode == KEY_D)
		move(game, 1);
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
void	init_stage(t_game *game)
{
	game->board->mlx = mlx_init();
	game->board->win = mlx_new_window(game->board->mlx, game->map_width * 64, game->map_height * 64, "my_mlx");
    init_image(game->board->mlx, game->board->img);
	render_stage(game);
    mlx_hook(game->board->win, X_EVENT_KEY_RELEASE, 0, &key_press, game);
    mlx_loop_hook(game->board->mlx, &render_stage, game);
	mlx_loop(game->board->mlx);
}
