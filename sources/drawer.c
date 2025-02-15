/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/15 03:05:47 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	draw_line(t_line *line, t_fdf *fdf)
// {
// 	int	z0;
// 	int	z1;
// 	int	color0;
// 	int	color1;

// 	z0 = fdf->map.coordinates[line->y0][line->x0].z;
// 	z1 = fdf->map.coordinates[line->y1][line->x1].z;
// 	color0 = fdf->map.coordinates[line->y0][line->x0].color;
// 	color1 = fdf->map.coordinates[line->y1][line->x1].color;
// 	apply_zoom(line, fdf);
// 	apply_rotation(&line->x0, &line->y0, fdf);
// 	apply_rotation(&line->x1, &line->y1, fdf);
// 	apply_isometric_projection(&line->x0, &line->y0, z0, fdf->factors.z_scale);
// 	apply_isometric_projection(&line->x1, &line->y1, z1, fdf->factors.z_scale);
// 	apply_offset(line, fdf);
// 	fdf->segment.initial = (t_coordinate){line->x0, line->y0, z0, color0};
// 	fdf->segment.final = (t_coordinate){line->x1, line->y1, z1, color1};
// 	xiaolin_wu_algorithm(fdf);
// }
static void	ft_rotate_x(int *y, int *z, double x_angle)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(x_angle) + *z * sin(x_angle);
	*z = prev_y * -sin(x_angle) + *z * cos(x_angle);
}

static void	ft_rotate_y(int *x, int *z, double y_angle)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(y_angle) + *z * sin(y_angle);
	*z = prev_x * -sin(y_angle) + *z * cos(y_angle);
}

static void	ft_rotate_z(int *x, int *y, double z_angle)
{
	t_coordinate	prev;

	prev.x = *x;
	prev.y = *y;
	*x = prev.x * cos(z_angle) - prev.y * sin(z_angle);
	*y = prev.x * sin(z_angle) + prev.y * cos(z_angle);
}

static t_coordinate config_point(int x, int y, t_fdf *fdf)
{
	t_coordinate	coord;

	coord.z = fdf->map.coordinates[y][x].z;
	coord.color = fdf->map.coordinates[y][x].color;
	coord.x = x * fdf->factors.zoom;
	coord.y = y * fdf->factors.zoom;
	coord.z *= fdf->factors.zoom / fdf->factors.z_height;
	coord.x -= (fdf->map.width * fdf->factors.zoom) / 2;
	coord.y -= (fdf->map.height * fdf->factors.zoom) / 2;
	ft_rotate_x(&coord.y, &coord.z, fdf->factors.x_angle);
	ft_rotate_y(&coord.x, &coord.z, fdf->factors.y_angle);
	ft_rotate_z(&coord.x, &coord.y, fdf->factors.z_angle);
	coord.x += WINDOW_WIDTH / 2 + fdf->factors.x_offset;
	coord.y += (WINDOW_HEIGHT + fdf->map.height
			/ 2 * fdf->factors.zoom) / 2 + fdf->factors.y_offset;
	fdf->segment.reverse = 0;
	return (coord);
}

void	draw_line(t_coordinate initial, t_coordinate final, t_fdf	*fdf)
{
	fdf->segment.initial = config_point(initial.x, initial.y, fdf);
	fdf->segment.final = config_point(final.x, final.y, fdf);
	xiaolin_wu_algorithm(fdf);
}

void	draw_map(t_fdf *fdf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < fdf->map.height)
	{
		x = 0;
		while (x < fdf->map.width)
		{
			if (x < fdf->map.width - 1)
				draw_line(fdf->map.coordinates[y][x],
					fdf->map.coordinates[y][x + 1], fdf);
			if (y < fdf->map.height - 1)
				draw_line(fdf->map.coordinates[y][x],
					fdf->map.coordinates[y + 1][x], fdf);
			x += -2 * (fdf->factors.y_angle > 0) + 1;
			}
		y += -2 * (fdf->factors.x_angle > 0) + 1;
	}
}
