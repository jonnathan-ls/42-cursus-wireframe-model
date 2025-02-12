/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/12 01:36:09 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_projection(int *x, int *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

// void draw_line(int x0, int y0, int x1, int y1, t_fdf *fdf)
// {
// 	int dx;
// 	int dy;
// 	float m;
// 	int iz = fdf->map.coordinates[y0][x0].z;
// 	int fz = fdf->map.coordinates[y1][x1].z;
// 	int color = fdf->map.coordinates[y0][x0].color;
// 	int zoom = 25;
// 	x0 *= zoom;
// 	y0 *= zoom;
// 	x1 *= zoom;
// 	y1 *= zoom;
// 	isometric_projection(&x0, &y0, iz);
// 	isometric_projection(&x1, &y1, fz);
// 	int displacement = 300;
// 	x0 += displacement;
// 	y0 += displacement;
// 	x1 += displacement;
// 	y1 += displacement;

// 	if (abs(y1	- y0) < abs(x1 - x0))
// 	{
// 		if (x1	< x0)
// 		{
// 			int tmp = x0;
// 			x0 = x1;
// 			x1 = tmp;
// 			tmp = y0;
// 			y0 = y1;
// 			y1 = tmp;
// 		}

// 		dx = x1 - x0;
// 		dy = y1 - y0;
// 		if (dx != 0)
// 			m = (float)dy / (float)dx;
// 		else
// 			m = 1;

// 		float overlap = 1 - ((x0 + 0.5) - (int)(x0 + 0.5));
// 		float distStart = y0 - (int)(y0);
// 		custom_mlx_pixel_put(fdf, (x0 + 0.5), y0, color * overlap * (1 - distStart));
// 		custom_mlx_pixel_put(fdf, (x0 + 0.5), y0 + 1, color * overlap * distStart);

// 		overlap	= 1 - ((x1 + 0.5) - (int)(x1 + 0.5));
// 		float distEnd = y1 - (int)(y1);
// 		custom_mlx_pixel_put(fdf, (x1 + 0.5), y1, color * overlap * (1 - distEnd));
// 		custom_mlx_pixel_put(fdf, (x1 + 0.5), y1 + 1, color * overlap * distEnd);

// 		int i = 1;
// 		int range = round(dx + 0.5);
// 		while (i < range)
// 		{
// 			float x = x0 + i;
// 			float y = y0 + i * m;
// 			int ix = floor(x);
// 			int iy = floor(y);
// 			float distance = y	- iy;
			
// 			custom_mlx_pixel_put(fdf, ix, iy, color * (1 - distance));
// 			custom_mlx_pixel_put(fdf, ix, iy + 1, color * distance);
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		if (y1 < y0)
// 		{
// 			int tmp = x0;
// 			x0 = x1;
// 			x1 = tmp;
// 			tmp = y0;
// 			y0 = y1;
// 			y1 = tmp;
// 		}

// 		dx = x1 - x0;
// 		dy = y1 - y0;
// 		if (dy != 0)
// 			m = (float)dx / (float)dy;
// 		else
// 			m = 1;

// 		float overlap = 1 - ((y0 + 0.5) - (int)(y0 + 0.5));
// 		float distStart = x0 - (int)(x0);
// 		custom_mlx_pixel_put(fdf, x0, (y0 + 0.5), color * overlap * (1 - distStart));
// 		custom_mlx_pixel_put(fdf, x0 + 1, (y0 + 0.5), color * overlap * distStart);

// 		overlap	= 1 - ((y1 + 0.5) - (int)(y1 + 0.5));
// 		float distEnd = x1 - (int)(x1);
// 		custom_mlx_pixel_put(fdf, x1, (y1 + 0.5), color * overlap * (1 - distEnd));
// 		custom_mlx_pixel_put(fdf, x1 + 1, (y1 + 0.5), color * overlap * distEnd);

// 		int i = 1;
// 		int range = round(dy + 0.5);
// 		while (i < range)
// 		{
// 			float x = x0 + i * m;
// 			float y = y0 + i;
// 			int ix = floor(x);
// 			int iy = floor(y);
// 			float distance = x	- ix;
// 			custom_mlx_pixel_put(fdf, ix, iy, color * (1 - distance));
// 			custom_mlx_pixel_put(fdf, ix + 1, iy, color * distance);
// 			i++;
// 		}
// 	}
// }


void draw_line(int x0, int y0, int x1, int y1, t_fdf *fdf)
{
	int iz = fdf->map.coordinates[y0][x0].z;
	int fz = fdf->map.coordinates[y1][x1].z;
	int color = fdf->map.coordinates[y0][x0].color;
	int zoom = 25;
	x0 *= zoom;
	y0 *= zoom;
	x1 *= zoom;
	y1 *= zoom;
	isometric_projection(&x0, &y0, iz);
	isometric_projection(&x1, &y1, fz);
	int displacement = 300;
	x0 += displacement;
	y0 += displacement;
	x1 += displacement;
	y1 += displacement;

	fdf->segment.initial = (t_coordinate){x0, y0, iz, color};
	fdf->segment.final = (t_coordinate){x1, y1, fz, color};
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
