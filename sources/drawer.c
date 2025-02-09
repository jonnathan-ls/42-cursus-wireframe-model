/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/10 22:15:01 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void custom_mlx_pixel_put(t_image *img, int x, int y, int color)
// {
//  char *dst;

//  if (x < 0 || x >= img->width || y < 0 || y >= img->height)
// 		return;
//  dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
//  *(unsigned int *)dst = color;
// }

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

	printf("ix: %f, iy: %f, fx: %f, fy: %f\n", ix, iy, fx, fy);
	// printf("int)iy: %d, (int)ix: %d, (int)fy: %d, (int)fx: %d\n", (int)iy, (int)ix, (int)fy, (int)fx);
	int iz = fdf->map.coordinates[(int)iy][(int)ix].z;
	int fz = fdf->map.coordinates[(int)fy][(int)fx].z;
	// printf("iz: %d, fz: %d\n", iz, fz);
	// ---------- ZOOM ----------------
	zoom = 20;
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
	int shift = 150;
	ix += shift;
	iy += shift;
	fx += shift;
	fy += shift;
	// ---------- Bresenham ---------------
	x_step = fx - ix;
	y_step = fy - iy;
	max = get_abs_max(x_step, y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(ix - fx) || (int)(iy - fy))
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, ix, iy, color);
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
