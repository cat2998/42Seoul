/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:11:02 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/26 19:18:53 by jgwon            ###   ########.fr       */
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
	game = malloc(sizeof(t_game) * 1);
	if (!game)
		return (0);
	make_map(argv[1], game);
	// check_map(game);
	printf("map_width: %d\n", game->map_width);
	printf("map_height: %d\n", game->map_height);
	printf("map_str : %s", game->map_str);
	
	// void *mlx;
	// void *win;
	// void *img;
	// void *img2;
	// void *img3;
	// void *img4;
	// void *img5;
	// void *img6;
	// void *img7;
	// int img_width;
	// int img_height;

	// mlx = mlx_init();
	// win = mlx_new_window(mlx, 500, 400, "my_mlx");
	// img = mlx_xpm_file_to_image(mlx, "./images/land_stone2.xpm", &img_width, &img_height);
	// img2 = mlx_xpm_file_to_image(mlx, "./images/land.xpm", &img_width, &img_height);
	// img3 = mlx_xpm_file_to_image(mlx, "./images/land_ninja.xpm", &img_width, &img_height);
	// img4 = mlx_xpm_file_to_image(mlx, "./images/land_hole.xpm", &img_width, &img_height);
	// img5 = mlx_xpm_file_to_image(mlx, "./images/land_door_open.xpm", &img_width, &img_height);
	// img6 = mlx_xpm_file_to_image(mlx, "./images/land_ins.xpm", &img_width, &img_height);
	// img7 = mlx_xpm_file_to_image(mlx, "./images/land_coin.xpm", &img_width, &img_height);
	
	// mlx_put_image_to_window(mlx, win, img, 0, 0);
	// mlx_put_image_to_window(mlx, win, img, 64, 0);
	// mlx_put_image_to_window(mlx, win, img, 128, 0);
	// mlx_put_image_to_window(mlx, win, img, 192, 0);
	// mlx_put_image_to_window(mlx, win, img, 256, 0);
	// mlx_put_image_to_window(mlx, win, img, 320, 0);
	// mlx_put_image_to_window(mlx, win, img, 384, 0);
	// mlx_put_image_to_window(mlx, win, img, 0, 64);
	// mlx_put_image_to_window(mlx, win, img, 384, 64);
	// mlx_put_image_to_window(mlx, win, img, 0, 128);
	// mlx_put_image_to_window(mlx, win, img, 64, 128);
	// mlx_put_image_to_window(mlx, win, img, 128, 128);
	// mlx_put_image_to_window(mlx, win, img, 192, 128);
	// mlx_put_image_to_window(mlx, win, img, 256, 128);
	// mlx_put_image_to_window(mlx, win, img, 320, 128);
	// mlx_put_image_to_window(mlx, win, img, 384, 128);
	// mlx_put_image_to_window(mlx, win, img3, 64, 64);
	// mlx_put_image_to_window(mlx, win, img2, 128, 64);
	// mlx_put_image_to_window(mlx, win, img7, 192, 64);
	// mlx_put_image_to_window(mlx, win, img6, 256, 64);
	// mlx_put_image_to_window(mlx, win, img4, 320, 64);


	
	// mlx_loop(mlx);
	return (0);
}
