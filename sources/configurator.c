/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configurator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/15 06:26:31 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	config_windown(t_fdf *fdf)
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

void	config_map(t_fdf *fdf)
{
	if (!config_map_values(fdf))
		exit_with_error(MAP_DATA_ERROR, fdf);
	if (fdf->map.height == 0 || fdf->map.width == 0)
		exit_with_error(MAP_EMPTY_ERROR, fdf);
	if (!validates_map_values(fdf))
		exit_with_error(INVALID_MAP_VALUES, fdf);
	config_coordinates(fdf);
}

void	config_factors(t_fdf	*fdf)
{
	fdf->factors.zoom = get_min(WINDOW_WIDTH / fdf->map.width / 2,
			WINDOW_HEIGHT / fdf->map.height / 2);
	fdf->factors.x_angle = -0.615472907;
	fdf->factors.y_angle = -0.523599;
	fdf->factors.z_angle = 0.615472907;
	fdf->factors.z_scale = 1;
	fdf->factors.x_offset = 0;
	fdf->factors.y_offset = 0;
	fdf->factors.iso = 1;
}
