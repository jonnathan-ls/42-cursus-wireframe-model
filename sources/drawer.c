/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/12 23:49:00 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	apply_isometric_projection(int *x, int *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

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
	apply_isometric_projection(&line->x0, &line->y0, z0);
	apply_isometric_projection(&line->x1, &line->y1, z1);
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
