/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/15 15:51:41 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	initialize_factors(t_fdf *fdf)
{
	fdf->factors.x_offset = 0;
	fdf->factors.y_offset = 0;
	fdf->factors.x_angle = 1;
	fdf->factors.y_angle = 1;
	fdf->factors.z_angle = 1;
	fdf->factors.z_scale = 1;
	fdf->factors.zoom = 1;
	fdf->factors.iso = false;
}

static void	initialize_segment(t_fdf *fdf)
{
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
}

static void	initialize_map(t_fdf *fdf)
{
	fdf->map.width = 0;
	fdf->map.height = 0;
	fdf->image.endian = 0;
	fdf->map.values = NULL;
	fdf->image.addr = NULL;
	fdf->image.pointer = NULL;
	fdf->image.line_length = 0;
	fdf->map.coordinates = NULL;
	fdf->map.coordinates = NULL;
	fdf->image.bits_per_pixel = 0;
}

void	init_fdf_values(t_fdf *fdf)
{
	fdf->mlx_ptr = NULL;
	fdf->win_ptr = NULL;
	fdf->file_path = NULL;
	fdf->error_flag = false;
	initialize_map(fdf);
	initialize_factors(fdf);
	initialize_segment(fdf);
}
