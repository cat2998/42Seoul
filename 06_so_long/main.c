/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgwon <jgwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:11:02 by jgwon             #+#    #+#             */
/*   Updated: 2022/11/20 18:04:08 by jgwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"

int main(void)
{
	void *mlx;
	void *win;
	void *img;
	void *img2;
	void *img3;
	void *img4;
	void *img5;
	void *img6;
	void *img7;
	int img_width;
	int img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "my_mlx");
	img = mlx_xpm_file_to_image(mlx, "./images/land.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "./images/door.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx, "./images/door_open.xpm", &img_width, &img_height);
	// img5 = mlx_xpm_file_to_image(mlx, "./images/chest_open.xpm", &img_width, &img_height);
	// img6 = mlx_xpm_file_to_image(mlx, "./images/rune.xpm", &img_width, &img_height);
	// img7 = mlx_xpm_file_to_image(mlx, "./images/rune_light.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win, img2, 0, 0);
	mlx_put_image_to_window(mlx, win, img3, 128, 0);
	mlx_put_image_to_window(mlx, win, img4, 192, 64);
	// mlx_put_image_to_window(mlx, win, img5, 0, 64);
	// mlx_put_image_to_window(mlx, win, img6, 64, 64);
	// mlx_put_image_to_window(mlx, win, img7, 128, 64);
	mlx_loop(mlx);
	return (0);
}
