/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/12 21:14:37 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_projection(int *x, int *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z + 100;
}

void draw_line(int x0, int y0, int x1, int y1, t_fdf *fdf)
{
	int iz = fdf->map.coordinates[y0][x0].z;
	int fz = fdf->map.coordinates[y1][x1].z;
	int color = fdf->map.coordinates[y0][x0].color;
	int color2	= fdf->map.coordinates[y1][x1].color;
	int zoom = 25;
	x0 *= zoom;
	y0 *= zoom;
	x1 *= zoom;
	y1 *= zoom;
	isometric_projection(&x0, &y0, iz);
	isometric_projection(&x1, &y1, fz);
	int displacement = 350;
	x0 += displacement;
	y0 += displacement;
	x1 += displacement;
	y1 += displacement;

	fdf->segment.initial = (t_coordinate){x0, y0, iz, color};
	fdf->segment.final = (t_coordinate){x1, y1, fz, color2};
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
				draw_line(x, y, x + 1, y, fdf);
			if (y < fdf->map.height - 1)
				draw_line(x, y, x, y + 1, fdf);
			x++;
		}
		y++;
	}
}

// void	draw_map(t_fdf *fdf)
// {
// 	unsigned int	x;
// 	unsigned int	y;

// 	x = 0;
// 	y = 0;
// 	while (y < fdf->map.height)
// 	{
// 		x = 0;
// 		while (x < fdf->map.width)
// 		{
// 			fdf->segment.initial.x = x;
// 			fdf->segment.initial.y = y;
// 			fdf->segment.initial.z = fdf->map.coordinates[y][x].z;
// 			fdf->segment.initial.color = fdf->map.coordinates[y][x].color;
// 			fdf->segment.final.x = x;
// 			fdf->segment.final.y = y;
// 			fdf->segment.final.z = fdf->map.coordinates[y][x].z;
// 			fdf->segment.final.color = fdf->map.coordinates[y][x].color;
// 			if (x < fdf->map.width - 1)
// 			{
// 				fdf->segment.final.x = x + 1;
// 				draw_line(fdf);
// 			}
// 			if (y < fdf->map.height - 1)
// 			{
// 				fdf->segment.final.x = x;
// 				fdf->segment.final.y = y + 1;
// 				draw_line(fdf);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }
