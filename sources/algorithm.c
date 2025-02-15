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

t_color_factor get_color_factor(float num)
{
	t_color_factor factor;

	factor.integer = (int)num;
	if (num > 0.f)
		factor.fractional = num - factor.integer;
	else
		factor.fractional = num - (factor.integer + 1.f);
	factor.complement = 1.f - factor.fractional;
	return factor;
}

static int	interpolate_color(int color1, int color2, t_segment segment)
{
	double	factor;

	factor = segment.color.opacity;
	if (color1 == color2)
		return (color1);
	return ((int)((double)color1 + (color2 - color1) * factor));
}

static int	ft_get_color(int x, float factor, t_segment segment)
{
	segment.color.opacity = absolute(x - segment.initial.x)
		/ absolute(segment.final.x - segment.initial.x);
	if (segment.reverse)
	{
		segment.color.red = interpolate_color((segment.final.color >> 16)
				& 0xFF, (segment.initial.color >> 16) & 0xFF, segment);
		segment.color.green = interpolate_color((segment.final.color >> 8)
				& 0xFF, (segment.initial.color >> 8) & 0xFF, segment);
		segment.color.blue = interpolate_color(segment.final.color & 0xFF,
				segment.initial.color & 0xFF, segment);
	}
	else
	{
		segment.color.red = interpolate_color((segment.initial.color >> 16)
				& 0xFF, (segment.final.color >> 16) & 0xFF, segment);
		segment.color.green = interpolate_color((segment.initial.color >> 8)
				& 0xFF, (segment.final.color >> 8) & 0xFF, segment);
		segment.color.blue = interpolate_color(segment.initial.color & 0xFF,
				segment.final.color & 0xFF, segment);
	}
	segment.color.red *= factor;
	segment.color.green *= factor;
	segment.color.blue *= factor;
	return ((segment.color.red << 16) | (segment.color.green << 8)
		| segment.color.blue);
}

static void	draw_line_segment(t_segment segment, t_fdf *fdf)
{
	int				x_segment;
	float			y_segment;

	x_segment = segment.initial.x;
	y_segment = (float)segment.initial.y;
	while (x_segment <= segment.final.x)
	{
		segment.color.factor = get_color_factor(y_segment);
		if (segment.is_vertical)
		{
			custom_mlx_pixel_put(fdf, segment.color.factor.integer, x_segment,
				ft_get_color(x_segment, segment.color.factor.complement, segment));
			custom_mlx_pixel_put(fdf, segment.color.factor.integer + 1, x_segment,
				ft_get_color(x_segment, segment.color.factor.fractional, segment));
		}
		else
		{
			custom_mlx_pixel_put(fdf, x_segment, segment.color.factor.integer,
				ft_get_color(x_segment, segment.color.factor.complement, segment));
			custom_mlx_pixel_put(fdf, x_segment, segment.color.factor.integer + 1,
				ft_get_color(x_segment, segment.color.factor.fractional, segment));
		}
		y_segment += segment.slope;
		x_segment++;
	}
}

void	xiaolin_wu_algorithm(t_fdf *fdf)
{
	t_segment	*segment;
	int			abs_y;
	int			abs_x;

	segment = &fdf->segment;
	abs_y = absolute(segment->final.y - segment->initial.y);
	abs_x = absolute(segment->final.x - segment->initial.x);
	segment->is_vertical = abs_y > abs_x;
	if (fdf->segment.is_vertical)
	{
		swap(&segment->initial.x, &segment->initial.y);
		swap(&segment->final.x, &segment->final.y);
	}
	if (segment->initial.x > segment->final.x)
	{
		swap(&segment->initial.x, &segment->final.x);
		swap(&segment->initial.y, &segment->final.y);
		segment->reverse = 1;
	}
	segment->slope = get_slope(segment);
	draw_line_segment(fdf->segment, fdf);
}
