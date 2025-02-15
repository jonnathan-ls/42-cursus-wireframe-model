/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/15 06:26:31 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coordinate	config_point(int x, int y, t_fdf *fdf)
{
	t_coordinate	coordinate;

	coordinate.z = fdf->map.coordinates[y][x].z;
	coordinate.color = fdf->map.coordinates[y][x].color;
	coordinate.x = x * fdf->factors.zoom;
	coordinate.y = y * fdf->factors.zoom;
	coordinate.z *= fdf->factors.zoom / fdf->factors.z_scale;
	coordinate.x -= (fdf->map.width * fdf->factors.zoom) / 2;
	coordinate.y -= (fdf->map.height * fdf->factors.zoom) / 2;
	apply_isometric_projection(&coordinate, fdf);
	coordinate.x += WINDOW_WIDTH / 2 + fdf->factors.x_offset;
	coordinate.y += (WINDOW_HEIGHT + fdf->map.height
			/ 2 * fdf->factors.zoom) / 2 + fdf->factors.y_offset;
	fdf->segment.reverse = 0;
	return (coordinate);
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
