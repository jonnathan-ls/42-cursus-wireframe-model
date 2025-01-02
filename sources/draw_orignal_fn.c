/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/01/02 00:01:13 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_line(int x0, int y0, int x1, int y1, int color, t_image *img)
{
	int dx;
	int dy;
	float m;

	if (abs(y1	- y0) < abs(x1 - x0))
	{
		if (x1	< x0)
		{
			int tmp = x0;
			x0 = x1;
			x1 = tmp;
			tmp = y0;
			y0 = y1;
			y1 = tmp;
		}

		dx = x1 - x0;
		dy = y1 - y0;
		if (dx != 0)
			m = (float)dy / (float)dx;
		else
			m = 1;

		float overlap = 1 - ((x0 + 0.5) - (int)(x0 + 0.5));
		float distStart = y0 - (int)(y0);
		custom_mlx_pixel_put(img, (x0 + 0.5), y0, color * overlap * (1 - distStart));
		custom_mlx_pixel_put(img, (x0 + 0.5), y0 + 1, color * overlap * distStart);

		overlap	= 1 - ((x1 + 0.5) - (int)(x1 + 0.5));
		float distEnd = y1 - (int)(y1);
		custom_mlx_pixel_put(img, (x1 + 0.5), y1, color * overlap * (1 - distEnd));
		custom_mlx_pixel_put(img, (x1 + 0.5), y1 + 1, color * overlap * distEnd);

		int i = 1;
		int range = round(dx + 0.5);
		while (i < range)
		{
			float x = x0 + i;
			float y = y0 + i * m;
			int ix = floor(x);
			int iy = floor(y);
			float distance = y	- iy;
			printf("ix: %d, iy: %d, distance: %f range: %d overlap: %f\n", ix, iy, distance, range, overlap);
			custom_mlx_pixel_put(img, ix, iy, color * (1 - distance));
			custom_mlx_pixel_put(img, ix, iy + 1, color * distance);
			i++;
		}
	}
	else
	{
		if (y1 < y0)
		{
			int tmp = x0;
			x0 = x1;
			x1 = tmp;
			tmp = y0;
			y0 = y1;
			y1 = tmp;
		}

		dx = x1 - x0;
		dy = y1 - y0;
		if (dy != 0)
			m = (float)dx / (float)dy;
		else
			m = 1;

		float overlap = 1 - ((y0 + 0.5) - (int)(y0 + 0.5));
		float distStart = x0 - (int)(x0);
		custom_mlx_pixel_put(img, x0, (y0 + 0.5), color * overlap * (1 - distStart));
		custom_mlx_pixel_put(img, x0 + 1, (y0 + 0.5), color * overlap * distStart);

		overlap	= 1 - ((y1 + 0.5) - (int)(y1 + 0.5));
		float distEnd = x1 - (int)(x1);
		custom_mlx_pixel_put(img, x1, (y1 + 0.5), color * overlap * (1 - distEnd));
		custom_mlx_pixel_put(img, x1 + 1, (y1 + 0.5), color * overlap * distEnd);

		int i = 1;
		int range = round(dy + 0.5);
		while (i < range)
		{
			float x = x0 + i * m;
			float y = y0 + i;
			int ix = floor(x);
			int iy = floor(y);
			float distance = x	- ix;
			printf("ix: %d, iy: %d, distance: %f range: %d overlap: %f\n", ix, iy, distance, range, overlap);
			custom_mlx_pixel_put(img, ix, iy, color * (1 - distance));
			custom_mlx_pixel_put(img, ix + 1, iy, color * distance);
			i++;
		}
	}
}

