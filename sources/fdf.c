/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/15 16:48:39 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		ft_putendl_fd(INVALID_ARGS_ERROR, STDERR_FILENO);
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
		fdf.win_ptr, fdf.image.pointer, 0, 0);
	mlx_hook(fdf.win_ptr, 17, 0, on_close_window, &fdf);
	mlx_key_hook(fdf.win_ptr, on_key_press, &fdf);
	mlx_loop(fdf.mlx_ptr);
	free_mallocs(&fdf);
	return (EXIT_SUCCESS);
}
