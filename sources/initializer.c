/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/12 23:59:06 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_factors(t_fdf *fdf)
{
	fdf->factors.x_zoom = 25;
	fdf->factors.y_zoom = 20;
	fdf->factors.x_displacement = (WINDOW_WIDTH / 2)
		- (fdf->map.width * fdf->factors.x_zoom);
	fdf->factors.y_displacement = (WINDOW_HEIGHT / 2)
		- (fdf->map.height * fdf->factors.y_zoom);
}

static void	init_map_values(t_fdf *fdf)
{
	fdf->map.width = 0;
	fdf->map.height = 0;
	fdf->map.image = NULL;
	fdf->map.values = NULL;
	fdf->map.coordinates = NULL;
}

static void	init_segment_values(t_fdf *fdf)
{
	fdf->segment.slope = 0;
	fdf->segment.range = 0;
	fdf->segment.delta_y = 0;
	fdf->segment.delta_x = 0;
	fdf->segment.distance = 0;
	fdf->segment.is_vertical = 0;
	fdf->segment.final = (t_coordinate){0, 0, 0, 0};
	fdf->segment.initial = (t_coordinate){0, 0, 0, 0};
}

void	init_fdf_values(t_fdf *fdf)
{
	init_factors(fdf);
	fdf->mlx_ptr = NULL;
	fdf->win_ptr = NULL;
	init_map_values(fdf);
	fdf->file_path = NULL;
	fdf->error_flag = false;
	init_segment_values(fdf);
}
