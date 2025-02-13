/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/12 02:22:26 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_point(t_fdf *fdf, float x, float y)
{
	t_segment	*p;

	p = &fdf->segment;
	if (p->is_vertical)
	{
		p->overlap = 1 - (y + 0.5 - (int)(y + 0.5));
		p->initial_distance = x - (int)x;
		custom_mlx_pixel_put(fdf, x, (y + 0.5),
			interpolate_color(fdf, p->overlap * (1 - p->distance)));
		custom_mlx_pixel_put(fdf, x + 1, (y + 0.5),
			interpolate_color(fdf, p->overlap * p->distance));
	}
	else
	{
		p->overlap = 1 - (x + 0.5 - (int)(x + 0.5));
		p->initial_distance = y - (int)y;
		custom_mlx_pixel_put(fdf, (x + 0.5), y,
			interpolate_color(fdf, p->overlap * (1 - p->distance)));
		custom_mlx_pixel_put(fdf, (x + 0.5), y + 1,
			interpolate_color(fdf, p->overlap * p->distance));
	}
}

static void	draw_horizontal_segment(t_fdf *fdf)
{
	float		x;
	float		y;
	int			int_x;
	int			int_y;
	int			index;

	index = 1;
	fdf->segment.range = round(fdf->segment.delta_x + 0.5);
	while (index < fdf->segment.range)
	{
		x = fdf->segment.initial.x + index;
		y = fdf->segment.initial.y + index * fdf->segment.slope;
		int_x = floor(x);
		int_y = floor(y);
		fdf->segment.distance = y - int_y;
		custom_mlx_pixel_put(fdf, int_x, int_y,
			interpolate_color(fdf, (1 - fdf->segment.distance)));
		custom_mlx_pixel_put(fdf, int_x, int_y + 1,
			interpolate_color(fdf, fdf->segment.distance));
		index++;
	}
}

static void	draw_vertical_segment(t_fdf *fdf)
{
	float		x;
	float		y;
	int			int_x;
	int			int_y;
	int			index;

	index = 1;
	fdf->segment.range = round(fdf->segment.delta_y + 0.5);
	while (index < fdf->segment.range)
	{
		x = fdf->segment.initial.x + index * fdf->segment.slope;
		y = fdf->segment.initial.y + index;
		int_x = floor(x);
		int_y = floor(y);
		fdf->segment.distance = x - int_x;
		custom_mlx_pixel_put(fdf, int_x, int_y,
			interpolate_color(fdf, (1 - fdf->segment.distance)));
		custom_mlx_pixel_put(fdf, int_x + 1, int_y,
			interpolate_color(fdf, fdf->segment.distance));
		index++;
	}
}

static void	draw_line_segment(t_fdf *fdf)
{
	if (fdf->segment.is_vertical)
		draw_vertical_segment(fdf);
	else
		draw_horizontal_segment(fdf);
}

void	xiaolin_wu_algorithm(t_fdf *fdf)
{
	t_segment	*p;
	int			abs_y;
	int			abs_x;

	p = &fdf->segment;
	abs_y = abs(p->final.y - p->initial.y);
	abs_x = abs(p->final.x - p->initial.x);
	p->is_vertical = abs_y > abs_x;
	if (!p->is_vertical && p->final.x < p->initial.x)
		swap_coordinates(fdf);
	if (p->is_vertical && p->final.y < p->initial.y)
		swap_coordinates(fdf);
	p->slope = get_slope(p);
	draw_point(fdf, p->initial.x, p->initial.y);
	draw_point(fdf, p->final.x, p->final.y);
	draw_line_segment(fdf);
}
