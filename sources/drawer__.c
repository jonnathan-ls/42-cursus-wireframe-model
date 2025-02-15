/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/15 03:03:35 by jlacerda         ###   ########.fr       */
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
	t_coordinate	point;

	point.z	= fdf->map.coordinates[y][x].z;
	point.color = fdf->map.coordinates[y][x].color;
	point.x = x * fdf->factors.zoom;
	point.y = y * fdf->factors.zoom;
	point.z *= fdf->factors.zoom / fdf->factors.z_height;
	point.x -= (fdf->map.width * fdf->factors.zoom) / 2;
	point.y -= (fdf->map.height * fdf->factors.zoom) / 2;
	ft_rotate_x(&point.y, &point.z, fdf->factors.x_angle);
	ft_rotate_y(&point.x, &point.z, fdf->factors.y_angle);
	ft_rotate_z(&point.x, &point.y, fdf->factors.z_angle);
	point.x += WINDOW_WIDTH / 2 + fdf->factors.x_offset;
	point.y += (WINDOW_HEIGHT + fdf->map.height / 2 * fdf->factors.zoom) / 2
		+ fdf->factors.y_offset;
	point.reverse = 0;
	return (point);
}

float	ft_abs(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_ipart(float n)
{
	return ((int)n);
}

float	ft_fpart(float n)
{
	if (n > 0.f)
		return (n - ft_ipart(n));
	return (n - (ft_ipart(n) + 1.f));
}

float	ft_rfpart(float n)
{
	return (1.f - ft_fpart(n));
}

static int	ft_lerp(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

static int	ft_get_color(int x, t_coordinate s, t_coordinate e, float factor)
{
	int		r;
	int		g;
	int		b;
	float	percent;

	percent = ft_abs(x - s.x) / ft_abs(e.x - s.x);
	if (s.reverse)
	{
		r = ft_lerp((e.color >> 16) & 0xFF, (s.color >> 16) & 0xFF, percent);
		g = ft_lerp((e.color >> 8) & 0xFF, (s.color >> 8) & 0xFF, percent);
		b = ft_lerp(e.color & 0xFF, s.color & 0xFF, percent);
	}
	else
	{
		r = ft_lerp((s.color >> 16) & 0xFF, (e.color >> 16) & 0xFF, percent);
		g = ft_lerp((s.color >> 8) & 0xFF, (e.color >> 8) & 0xFF, percent);
		b = ft_lerp(s.color & 0xFF, e.color & 0xFF, percent);
	}
	r *= factor;
	g *= factor;
	b *= factor;
	return ((r << 16) | (g << 8) | b);
}

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	ft_draw_line_loop(t_coordinate s, t_coordinate e, float gradient, t_fdf *env)
{
	float	inter_y;
	int		x;

	inter_y = (float)s.y;
	x = s.x;
	while (x <= e.x)
	{
		if (env->segment.is_vertical)
		{
			custom_mlx_pixel_put(env, ft_ipart(inter_y), x,
				ft_get_color(x, s, e, ft_rfpart(inter_y)));
			custom_mlx_pixel_put(env, ft_ipart(inter_y) + 1, x,
				ft_get_color(x, s, e, ft_fpart(inter_y)));
		}
		else
		{
			custom_mlx_pixel_put(env, x, ft_ipart(inter_y),
				ft_get_color(x, s, e, ft_rfpart(inter_y)));
			custom_mlx_pixel_put(env, x, ft_ipart(inter_y) + 1,
				ft_get_color(x, s, e, ft_fpart(inter_y)));
		}
		inter_y += gradient;
		x++;
	}
}

void	ft_draw_line(t_coordinate s, t_coordinate e, t_fdf *env)
{
	float	dy;
	float	dx;
	float	gradient;

	env->segment.is_vertical = ft_abs(e.y - s.y) > ft_abs(e.x - s.x);
	if (env->segment.is_vertical)
	{
		ft_swap(&s.x, &s.y);
		ft_swap(&e.x, &e.y);
	}
	if (s.x > e.x)
	{
		ft_swap(&s.x, &e.x);
		ft_swap(&s.y, &e.y);
		s.reverse = 1;
	}
	dx = (float)(e.x - s.x);
	dy = (float)(e.y - s.y);
	gradient = dy / dx;
	if (dx == 0.0f)
		gradient = 1.f;
	ft_draw_line_loop(s, e, gradient, env);
}

void	draw_map(t_fdf *fdf)
{
	int	x;
	int	y;

	ft_bzero(fdf->map.image->addr, WINDOW_WIDTH * WINDOW_HEIGHT * (fdf->map.image->bits_per_pixel / 8));
	y = 0;
	if (fdf->factors.x_angle > 0)
		y = fdf->map.height - 1;
	while (y < fdf->map.height && y >= 0)
	{
		x = 0;
		if (fdf->factors.y_angle > 0)
			x = fdf->map.width - 1;
		while (x < fdf->map.width && x >= 0)
		{
			if (x != fdf->map.width - 1)
				ft_draw_line(config_point(x, y, fdf), config_point(x + 1, y, fdf), fdf);
			if (y != fdf->map.height - 1)
				ft_draw_line(config_point(x, y, fdf), config_point(x, y + 1, fdf), fdf);
			x += -2 * (fdf->factors.y_angle > 0) + 1;
		}
		y += -2 * (fdf->factors.x_angle > 0) + 1;
	}
}
