/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2024/12/29 20:28:46 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void custom_mlx_pixel_put(t_image *img, int x, int y, int color)
{
 char *dst;

 if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return;
 dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
 *(unsigned int *)dst = color;
}

int main(int argc, char **argv)
{
 t_config conf;

	if (argc < 2)
					return (fdf_file_path_not_provided_error());
	conf.mlx_ptr = mlx_init();
	if (!conf.mlx_ptr)
					return (fdf_mlx_init_error());
	conf.win_ptr = mlx_new_window(conf.mlx_ptr, WIDTH, HEIGHT, WINDOW_TITLE);
	if (!conf.win_ptr)
					return (fdf_mlx_window_creation_error(conf.mlx_ptr));
	conf.img.img_ptr = mlx_new_image(conf.mlx_ptr, WIDTH, HEIGHT);
	conf.img.addr = mlx_get_data_addr(conf.img.img_ptr, &conf.img.bits_per_pixel, &conf.img.line_length, &conf.img.endian);
	conf.img.width = WIDTH;
	conf.img.height = HEIGHT;
	if (!conf.img.addr) {
					perror("Failed to allocate memory for image");
					return 1;
	}
	set_points(&conf, ft_get_data(argv[1]));
	if (!conf.points)
					return (fdf_set_points_error(conf.mlx_ptr, conf.win_ptr));

	int i = 10;
	int j = 20;
	t_point initialPoint = {i, j, 0, DEFAULT_COLOR};
	t_point finalPoint = {i + 1500, j + 1000, 0, DEFAULT_COLOR};
	conf.draw_params = (t_draw_params){initialPoint, finalPoint, 0, 0, 0.0, &conf.img};
	draw_line(&conf.draw_params);

	t_point finalPoint2 = {i + 500, j + 100, 0, DEFAULT_COLOR};
	conf.draw_params = (t_draw_params){initialPoint, finalPoint2, 0, 0, 0.0, &conf.img};
	draw_line(&conf.draw_params);

	t_point finalPoint3 = {i + 150, j + 10, 0, DEFAULT_COLOR + 100};
	conf.draw_params = (t_draw_params){initialPoint, finalPoint3, 0, 0, 0.0, &conf.img};
	draw_line(&conf.draw_params);

	mlx_put_image_to_window(conf.mlx_ptr, conf.win_ptr, conf.img.img_ptr, 0, 0);
	mlx_loop(conf.mlx_ptr);
	return (EXIT_SUCCESS);
}
