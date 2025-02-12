/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/12 01:40:31 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void swap_coordinates(t_fdf *fdf)
{
	int 			tmp;
	t_coordinate	*initial;
	t_coordinate	*final;

	initial = &fdf->segment.initial;
	final = &fdf->segment.final;
	tmp = initial->x;
	initial->x = final->x;
	final->x = tmp;
	tmp = initial->y;
	initial->y = final->y;
	final->y = tmp;
}

static float	get_slope(t_segment *p)
{
	p->delta_x = p->final.x - p->initial.x;
	p->delta_y = p->final.y - p->initial.y;
	if (!p->is_vertical && p->delta_x != 0)
		return (float)p->delta_y / (float)p->delta_x;
	if (p->is_vertical && p->delta_y != 0)
		return (float)p->delta_x / (float)p->delta_y;
	return 1;
}

static void	draw_point(t_fdf *fdf, float x, float y, int color)
{
	t_segment *p;

	p = &fdf->segment;
	if (p->is_vertical)
	{
		p->overlap = 1 - (y + 0.5 - (int)(y + 0.5));
		p->initial_distance = x - (int)x;
		custom_mlx_pixel_put(fdf, x, (y + 0.5),
			color * p->overlap * (1 - p->distance));
		custom_mlx_pixel_put(fdf, x + 1, (y + 0.5),
			color * p->overlap * p->distance);
	}
	else
	{
		p->overlap = 1 - (x + 0.5 - (int)(x + 0.5));
		p->initial_distance = y - (int)y;
		custom_mlx_pixel_put(fdf, (x + 0.5), y,
			color * p->overlap * (1 - p->distance));
		custom_mlx_pixel_put(fdf, (x + 0.5), y + 1,
			color * p->overlap * p->distance);
	}
}

static void	draw_line_segment(t_fdf *fdf, int color)
{
	float 		x;
	float 		y;
	t_segment	*p;
	int			index;

	index = 1;
	p = &fdf->segment;
	if (p->is_vertical)
	{
		p->range = round(p->delta_y + 0.5);
		while (index < p->range)
		{
			x = p->initial.x + index * p->slope;
			y = p->initial.y + index;
			int x_int = floor(x);
			int y_int = floor(y);
			p->distance = x - x_int;
			custom_mlx_pixel_put(fdf, x_int, y_int, color * (1 - p->distance));
			custom_mlx_pixel_put(fdf, x_int + 1, y_int, color * p->distance);
			index++;
		}
	}
	else
	{
		p->range = round(p->delta_x + 0.5);
		while (index < p->range)
		{
			x = p->initial.x + index;
			y = p->initial.y + index * p->slope;
			int x_int = floor(x);
			int y_int = floor(y);
			p->distance = y - y_int;
			custom_mlx_pixel_put(fdf, x_int, y_int, color * (1 - p->distance));
			custom_mlx_pixel_put(fdf, x_int, y_int + 1, color * p->distance);
			index++;
		}
	}
}

void	xiaolin_wu_algorithm(t_fdf *fdf)
{
	t_segment	*p;
	
	p = &fdf->segment;
	p->is_vertical = (p->final.y - p->initial.y) > abs(p->final.x - p->initial.x);

	if (!p->is_vertical && p->final.x < p->initial.x)
		swap_coordinates(fdf);
	if (p->is_vertical && p->final.y < p->initial.y)
		swap_coordinates(fdf);
	p->slope = get_slope(p);
	draw_point(fdf, p->initial.x, p->initial.y, p->initial.color);
	draw_point(fdf, p->final.x, p->final.y, p->final.color);
	draw_line_segment(fdf, p->initial.color);
}


// void swap_points(t_segment *p) {
//     t_coordinate tmp;

//     tmp = p->initial;
//     p->initial = p->final;
//     p->final = tmp;
// }

// void calculate_slope(t_segment *p) {
//     p->delta_x = p->final.x - p->initial.x;
//     p->delta_y = p->final.y - p->initial.y;
//     if (p->delta_x != 0)
//         p->slope = (float)p->delta_y / (float)p->delta_x;
//     else
//         p->slope = 1;
// }

// int interpolate_color(int color1, int color2, float factor) {
//     int red = ((color1 >> 16) & 0xFF) + factor * (((color2 >> 16) & 0xFF) - ((color1 >> 16) & 0xFF));
//     int green = ((color1 >> 8) & 0xFF) + factor * (((color2 >> 8) & 0xFF) - ((color1 >> 8) & 0xFF));
//     int blue = (color1 & 0xFF) + factor * ((color2 & 0xFF) - (color1 & 0xFF));
//     return (red << 16) | (green << 8) | blue;
// }

// void draw_endpoint(t_fdf *fdf, int x, int y)
// {
// 	t_segment *p;

// 	p = &fdf->segment;
//     float overlap = 1 - ((x + 0.5) - (int)(x + 0.5));
//     float dist = y - (int)(y);
//     int color = interpolate_color(p->initial.color, p->final.color, (float)(x - p->initial.x) / p->delta_x);
//     if (p->is_vertical) {
//         custom_mlx_pixel_put(fdf, x, (y + 0.5), color * overlap * (1 - dist));
//         custom_mlx_pixel_put(fdf, x + 1, (y + 0.5), color * overlap * dist);
//     } else {
//         custom_mlx_pixel_put(fdf, (x + 0.5), y, color * overlap * (1 - dist));
//         custom_mlx_pixel_put(fdf, (x + 0.5), y + 1, color * overlap * dist);
//     }
// }
// // void draw_point(t_segment *p, int is_vertical, t_image *img) {
// // 	int x = round(p->x);
// // 	int y = round(p->y);
// // 	float distance = is_vertical ? p->x - x : p->y - y;
// // 	int color = interpolate_color(p->initial.color, p->final.color, is_vertical ? p->x - p->initial.x : p->y - p->initial.y);
// // 	custom_mlx_pixel_put(img, x, y, color * (1 - distance));
// // 	custom_mlx_pixel_put(img, is_vertical ? x + 1 : x, is_vertical ? y : y + 1, color * distance);
// // }

// void draw_line_segment(t_fdf *fdf)
// {
// 	t_segment *p;
	
//     int i = 1;
// 	p = &fdf->segment;
//     int range = round((p->is_vertical ? p->delta_y : p->delta_x) + 0.5);
//     while (i < range)
// 	{
//         float x = p->initial.x + (p->is_vertical ? i * p->slope : i);
//         float y = p->initial.y + (p->is_vertical ? i : i * p->slope);
//         int ix = floor(x);
//         int iy = floor(y);
//         float distance = p->is_vertical ? x - ix : y - iy;
//         int color = interpolate_color(p->initial.color, p->final.color, (float)(ix - p->initial.x) / p->delta_x);
//         custom_mlx_pixel_put(fdf, ix, iy, color * (1 - distance));
//         custom_mlx_pixel_put(fdf, p->is_vertical ? ix + 1 : ix, p->is_vertical ? iy : iy + 1, color * distance);
//         i++;
//     }
// }

// void draw_line(t_fdf *fdf)
// {
// 	t_segment *p;

// 	p = &fdf->segment;
//     int is_vertical = abs(p->final.y - p->initial.y) >= abs(p->final.x - p->initial.x);
//     if (is_vertical) {
//         if (p->final.y < p->initial.y)
//             swap_points(p);
//         calculate_slope(p);
//         draw_endpoint(fdf, p->initial.x, p->initial.y);
//         draw_endpoint(fdf, p->final.x, p->final.y);
//         draw_line_segment(fdf);
//     } else {
//         if (p->final.x < p->initial.x)
//             swap_points(p);
//         calculate_slope(p);
//         draw_endpoint(fdf, p->initial.x, p->initial.y);
//         draw_endpoint(fdf, p->final.x, p->final.y);
//         draw_line_segment(fdf);
//     }
// }