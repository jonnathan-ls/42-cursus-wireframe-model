/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/14 02:25:43 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	config_windown(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	if (fdf->mlx_ptr == NULL)
		exit_with_error(MLX_INIT_ERROR, fdf);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	if (fdf->win_ptr == NULL)
		exit_with_error(WINDOW_CREATION_ERROR, fdf);
	fdf->map.image = (t_image *)malloc(sizeof(t_image));
	fdf->map.image->pointer = mlx_new_image(
			fdf->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (fdf->map.image->pointer == NULL)
		exit_with_error(IMAGE_CREATION_ERROR, fdf);
	fdf->map.image->addr = mlx_get_data_addr(
			fdf->map.image->pointer, &fdf->map.image->bits_per_pixel,
			&fdf->map.image->line_length, &fdf->map.image->endian);
}

static void	config_map(t_fdf *fdf)
{
	if (!config_map_values(fdf))
		exit_with_error(MAP_DATA_ERROR, fdf);
	if (fdf->map.height == 0 || fdf->map.width == 0)
		exit_with_error(MAP_EMPTY_ERROR, fdf);
	if (!validates_map_values(fdf))
		exit_with_error(INVALID_MAP_VALUES, fdf);
	config_coordinates(fdf);
}

static void	config_factors(t_fdf	*fdf)
{
	// double	center_x;
	// double	center_y;
	// double	window_center_x;
	// double	window_center_y;

	// center_x = (fdf->map.width - 1) / 2.0;
	// center_y = (fdf->map.height - 1) / 2.0;
	// window_center_x = WINDOW_WIDTH / 2.0;
	// window_center_y = WINDOW_HEIGHT / 2.0;
	// fdf->factors.x_zoom = (WINDOW_WIDTH * 0.7) / fdf->map.width;
	// fdf->factors.y_zoom = (WINDOW_HEIGHT * 0.7) / fdf->map.height;
	// fdf->factors.x_offset = (window_center_x - center_x
	// 		* fdf->factors.x_zoom) / 4;
	// fdf->factors.y_offset = (window_center_y - center_y
	// 		* fdf->factors.y_zoom) * 4;
	// fdf->factors.x_offset = WINDOW_WIDTH / 4;
	// fdf->factors.y_offset = WINDOW_HEIGHT / 4;
	// fdf->factors.x_zoom = (WINDOW_WIDTH	/ fdf->map.width) * 0.8;
	// fdf->factors.y_zoom = (WINDOW_HEIGHT / fdf->map.height) * 0.8;
	fdf->factors.x_zoom = (WINDOW_WIDTH * 0.8)	/ fdf->map.width;
	fdf->factors.y_zoom = (WINDOW_HEIGHT * 0.8)	/ fdf->map.height;
	fdf->factors.x_offset = 500;
	fdf->factors.y_offset = 500;
	fdf->factors.x_rotation = DEFAULT_ROTATION_ANGLE;
	fdf->factors.y_rotation = DEFAULT_ROTATION_ANGLE;
	fdf->factors.z_rotation = DEFAULT_ROTATION_ANGLE;
}

static void	validates_file_extension(t_fdf *fdf)
{
	char	*extension;

	extension = ft_strrchr(fdf->file_path, DOT_CHAR);
	if (extension == NULL || ft_strncmp(extension, ".fdf", 5) != 0)
		exit_with_error(INVALID_FILE_EXTENSION, fdf);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
	{
		ft_putstr_fd(INVALID_ARGS_ERROR, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	init_fdf_values(&fdf);
	fdf.file_path = argv[1];
	validates_file_extension(&fdf);
	config_map(&fdf);
	config_windown(&fdf);
	config_factors(&fdf);
	draw_map(&fdf);
	mlx_put_image_to_window(fdf.mlx_ptr,
		fdf.win_ptr, fdf.map.image->pointer, 0, 0);
	mlx_key_hook(fdf.win_ptr, on_key_press, &fdf);
	mlx_mouse_hook(fdf.win_ptr, on_mouse_click, &fdf);
	mlx_hook(fdf.win_ptr, 17, 0, on_close_window, &fdf);
	mlx_loop(fdf.mlx_ptr);
	free_mallocs(&fdf);
	return (EXIT_SUCCESS);
}
