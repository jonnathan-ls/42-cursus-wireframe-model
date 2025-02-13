/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/13 03:35:56 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void apply_conic_projection(int *x, int *y, int z, t_fdf	*fdf)
{
	int previous_x;
	int previous_y;
	int previous_z;

	previous_x = *x;
	previous_y = *y;
	previous_z = z * fdf->factors.z_scale;
	*x = (previous_x * fdf->factors.focal_length)
		/ (fdf->factors.focal_length + previous_z);
	*y = (previous_y * fdf->factors.focal_length)
		/ (fdf->factors.focal_length + previous_z);
}

// static void apply_isometric_projection(int *x, int *y, int z, float z_scale)
// {
// 		int previous_x = *x;
// 		int previous_y = *y;
// 		*x = (previous_x - previous_y) * cos(0.523599);
// 		*y = (previous_x + previous_y) * sin(0.523599) - z * z_scale;
// }

static void	apply_zoom(t_line *line, t_fdf *fdf)
{
	line->x0 *= fdf->factors.x_zoom;
	line->y0 *= fdf->factors.y_zoom;
	line->x1 *= fdf->factors.x_zoom;
	line->y1 *= fdf->factors.y_zoom;
}

static void	apply_displacement(t_line *line, t_fdf *fdf)
{
	line->x0 += fdf->factors.x_displacement;
	line->y0 += fdf->factors.y_displacement;
	line->x1 += fdf->factors.x_displacement;
	line->y1 += fdf->factors.y_displacement;
}

static void	apply_rotation(int *x, int *y, t_fdf *fdf)
{
	int		x_new;
	int		y_new;
	double	x_rad;
	double	y_rad;

	x_rad = fdf->factors.x_rotation * M_PI / 180.0;
	y_rad = fdf->factors.y_rotation * M_PI / 180.0;
	x_new = *x * cos(x_rad) - *y * sin(x_rad);
	y_new = *x * sin(y_rad) + *y * cos(y_rad);
	*x = x_new;
	*y = y_new;
}

void	draw_line(t_line *line, t_fdf *fdf)
{
	int	z0;
	int	z1;
	int	color0;
	int	color1;

	z0 = fdf->map.coordinates[line->y0][line->x0].z;
	z1 = fdf->map.coordinates[line->y1][line->x1].z;
	color0 = fdf->map.coordinates[line->y0][line->x0].color;
	color1 = fdf->map.coordinates[line->y1][line->x1].color;
	apply_zoom(line, fdf);
	apply_rotation(&line->x0, &line->y0, fdf);
	apply_rotation(&line->x1, &line->y1, fdf);
	// apply_isometric_projection(&line->x0, &line->y0, z0, fdf->factors.z_scale);
	// apply_isometric_projection(&line->x1, &line->y1, z1, fdf->factors.z_scale);
	apply_conic_projection(&line->x0, &line->y0, z0, fdf);
	apply_conic_projection(&line->x1, &line->y1, z1, fdf);
	// apply_parallel_projection(&line->x0, &line->y0, z0);
	// apply_parallel_projection(&line->x1, &line->y1, z1);
	apply_displacement(line, fdf);
	fdf->segment.initial = (t_coordinate){line->x0, line->y0, z0, color0};
	fdf->segment.final = (t_coordinate){line->x1, line->y1, z1, color1};
	xiaolin_wu_algorithm(fdf);
}

void	draw_map(t_fdf *fdf)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (y < fdf->map.height)
	{
		x = 0;
		while (x < fdf->map.width)
		{
			if (x < fdf->map.width - 1)
				draw_line(&(t_line){x, y, x + 1, y}, fdf);
			if (y < fdf->map.height - 1)
				draw_line(&(t_line){x, y, x, y + 1}, fdf);
			x++;
		}
		y++;
	}
}
