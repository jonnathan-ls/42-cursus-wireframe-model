/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/11 21:33:17 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int get_abs_max(float a, float b)
{
	if (fabs(a) > fabs(b))
		return ((int)fabs(a));
	return ((int)fabs(b));
}

void	isometric_projection(float *x, float *y, float z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void brasenham_line(float ix, float iy, float fx, float fy, t_fdf *fdf)
{
	float	x_step;
	float	y_step;
	int		max;
	int		zoom;
	int		color;

	int iz = fdf->map.coordinates[(int)iy][(int)ix].z;
	int fz = fdf->map.coordinates[(int)fy][(int)fx].z;
	// ---------- ZOOM ----------------
	zoom = 15;
	ix = ix * zoom;
	iy = iy * zoom;
	fx = fx * zoom;
	fy = fy * zoom;
	// ---------- Color ----------------
	color = (iz) ? 0xe80c0c : 0xffffff;
	// ---------- 3D ----------------
	isometric_projection(&ix, &iy, iz);
	isometric_projection(&fx, &fy, fz);
	// ---------- Shift ---------------
	int shift = 200;
	ix += shift;
	iy += shift;
	fx += shift;
	fy += shift;
	// ---------- Bresenham ---------------
	x_step = fx - ix;
	y_step = fy - iy;
	max = get_abs_max(x_step, y_step);
	if (max == 0)
		max = 1;
	x_step /= max;
	y_step /= max;
	while ((int)(ix - fx) || (int)(iy - fy))
	{
		custom_mlx_pixel_put(fdf, ix, iy, color);
		ix += x_step;
		iy += y_step;
	}
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
				brasenham_line(x, y, x + 1, y, fdf);
			if (y < fdf->map.height - 1)
				brasenham_line(x, y, x, y + 1, fdf);
			x++;
		}
		y++;
	}
}
