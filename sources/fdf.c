/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/13 03:26:12 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	initialize_mlx_values(t_fdf *fdf)
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

static void	initialize_map(t_fdf *fdf)
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
	fdf->factors.x_zoom = (WINDOW_WIDTH * 0.8) / fdf->map.width;
	fdf->factors.y_zoom = (WINDOW_HEIGHT * 0.8) / fdf->map.height;
	fdf->factors.x_displacement = (WINDOW_WIDTH / 2)
		- (fdf->map.width * fdf->factors.x_zoom / 2);
	fdf->factors.y_displacement = (WINDOW_HEIGHT)
		- (fdf->map.height * fdf->factors.y_zoom / 2);
	fdf->factors.x_rotation	= -90;
	fdf->factors.y_rotation	= -90;
	fdf->factors.z_scale = 1;
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
	initialize_mlx_values(&fdf);
	initialize_map(&fdf);
	config_factors(&fdf);
	draw_map(&fdf);
	mlx_put_image_to_window(fdf.mlx_ptr,
		fdf.win_ptr, fdf.map.image->pointer, 0, 0);
	mlx_key_hook(fdf.win_ptr, on_key_press, &fdf);
	mlx_loop(fdf.mlx_ptr);
	free_mallocs(&fdf);
	return (EXIT_SUCCESS);
}
// if (fdf.map.height == 0 || fdf.map.width == 0)
// exit_with_error(MAP_EMPTY_ERROR, &fdf);
// Precisa corrigir exit_with_error aqui da segment fault
// PRECISA CORRIGIR GET_NEXT_LINE 
// quando nao é lido até o final, para liberar memoria

// TODO: renderizar janela de acordo com o tamanho do mapa
// TODO: Corrigir problema de altura (Z) esta compactada
