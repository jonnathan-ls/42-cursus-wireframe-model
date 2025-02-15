/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/15 06:12:53 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	init_fdf_values(t_fdf *fdf)
{
	fdf->mlx_ptr = NULL;
	fdf->win_ptr = NULL;
	fdf->map.image = NULL;
	fdf->file_path = NULL;
	fdf->map.values = NULL;
	fdf->error_flag = false;
	fdf->map.coordinates = NULL;
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
	draw_instructions(&fdf);
	draw_map(&fdf);
	mlx_put_image_to_window(fdf.mlx_ptr,
		fdf.win_ptr, fdf.map.image->pointer, 0, 0);
	hook_handlers(&fdf);
	mlx_loop(fdf.mlx_ptr);
	free_mallocs(&fdf);
	return (EXIT_SUCCESS);
}

// mlx_mouse_hook(fdf.win_ptr, on_mouse_click, &fdf);