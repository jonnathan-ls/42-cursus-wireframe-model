/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/15 06:26:31 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_fdf_values(t_fdf *fdf)
{
	fdf->error_flag = false;
	fdf->file_path = NULL;
	fdf->factors.x_offset = 0;
	fdf->factors.y_offset = 0;
	fdf->factors.x_angle = 1;
	fdf->factors.y_angle = 1;
	fdf->factors.z_angle = 1;
	fdf->factors.z_scale = 1;
	fdf->factors.zoom = 1;
	fdf->factors.iso = false;
	fdf->map.width = 0;
	fdf->map.height = 0;
	fdf->segment.color.blue = 0;
	fdf->segment.color.red = 0;
	fdf->segment.color.green = 0;
	fdf->segment.color.opacity = 0;
	fdf->segment.color.factor.integer = 0;
	fdf->segment.color.factor.fractional = 0;
	fdf->segment.color.factor.complement = 0;
	fdf->segment.slope = 0;
	fdf->segment.delta_x = 0;
	fdf->segment.delta_y = 0;
	fdf->segment.final = (t_coordinate){0, 0, 0, 0};
	fdf->segment.initial = (t_coordinate){0, 0, 0, 0};
	fdf->segment.is_vertical = false;
	fdf->segment.reverse = false;
	fdf->mlx_ptr = NULL;
	fdf->win_ptr = NULL;
	fdf->map.image = NULL;
	fdf->file_path = NULL;
	fdf->map.values = NULL;
	fdf->error_flag = false;
	fdf->map.coordinates = NULL;
}

static int	on_key_press(int keycode, t_fdf	*fdf)
{
	if (fdf != NULL)
	{
		if (keycode == ESC)
		{
			free_mallocs(fdf);
			exit(EXIT_SUCCESS);
		}
	}
	return (0);
}

static int	on_close_window(t_fdf *fdf)
{
	free_mallocs(fdf);
	exit(EXIT_SUCCESS);
	return (0);
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
	mlx_hook(fdf.win_ptr, 17, 0, on_close_window, &fdf);
	mlx_key_hook(fdf.win_ptr, on_key_press, &fdf);
	mlx_loop(fdf.mlx_ptr);
	free_mallocs(&fdf);
	return (EXIT_SUCCESS);
}
