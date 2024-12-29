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

void	custom_mlx_pixel_put(t_image *img, t_point *point)
{
	char	*destination;

	destination = img->addr + \
	(point->y * img->line_length + point->x * (img->bits_per_pixel / 8));
	*(unsigned int *)destination = point->color;
}

int	main(int argc, char **argv)
{
	t_config	conf;
	int			i;

	if (argc < 2)
		return (fdf_file_path_not_provided_error());
	conf.mlx_ptr = mlx_init();
	if (!conf.mlx_ptr)
		return (fdf_mlx_init_error());
	conf.win_ptr = mlx_new_window(conf.mlx_ptr, WIDTH, HEIGHT, WINDOW_TITLE);
	if (!conf.win_ptr)
		return (fdf_mlx_window_creation_error(conf.mlx_ptr));
	conf.img.img_ptr = mlx_new_image(conf.mlx_ptr, WIDTH, HEIGHT);
	conf.img.addr = mlx_get_data_addr(conf.img.img_ptr, \
	&conf.img.bits_per_pixel, &conf.img.line_length, &conf.img.endian);
	conf.points = ft_set_points(ft_get_data(argv[1]));
	if (!conf.points)
		return (fdf_set_points_error(conf.mlx_ptr, conf.win_ptr));
	i = 0;
	while (conf.points[i])
		custom_mlx_pixel_put(&conf.img, conf.points[i++]);
	mlx_put_image_to_window(conf.mlx_ptr, conf.win_ptr, conf.img.img_ptr, 0, 0);
	mlx_loop(conf.mlx_ptr);
	return (EXIT_SUCCESS);
}
