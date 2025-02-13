/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/12 02:28:44 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	remove_breakline_char(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return ;
	while (line[i])
	{
		if (line[i] == BREAK_LINE_CHAR)
			line[i] = NULL_CHAR;
		i++;
	}
}

void	custom_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;
	t_image	*img;

	img = fdf->map.image;
	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	interpolate_color( t_fdf *fdf, float opacity)
{
	t_segment	*p;
	int			red;
	int			green;
	int			blue;
	int			factor;

	p = &fdf->segment;
	if (p->is_vertical)
		factor = (float)(p->final.y - p->initial.y) / p->delta_y;
	else
		factor = (float)(p->final.x - p->initial.x) / p->delta_x;
	red = ((p->initial.color >> 16) & 0xFF) + factor
		* (((p->final.color >> 16) & 0xFF) - ((p->initial.color >> 16) & 0xFF));
	green = ((p->initial.color >> 8) & 0xFF) + factor
		* (((p->final.color >> 8) & 0xFF) - ((p->initial.color >> 8) & 0xFF));
	blue = (p->initial.color & 0xFF) + factor
		* ((p->final.color & 0xFF) - (p->initial.color & 0xFF));
	red = (int)(red * opacity);
	green = (int)(green * opacity);
	blue = (int)(blue * opacity);
	return ((red << 16) | (green << 8) | blue);
}

void	swap_coordinates(t_fdf *fdf)
{
	t_coordinate	*initial;
	t_coordinate	*final;
	int				tmp;

	initial = &fdf->segment.initial;
	final = &fdf->segment.final;
	tmp = initial->x;
	initial->x = final->x;
	final->x = tmp;
	tmp = initial->y;
	initial->y = final->y;
	final->y = tmp;
}

float	get_slope(t_segment *p)
{
	p->delta_x = p->final.x - p->initial.x;
	p->delta_y = p->final.y - p->initial.y;
	if (!p->is_vertical && p->delta_x != 0)
		return ((float)p->delta_y / (float)p->delta_x);
	if (p->is_vertical && p->delta_y != 0)
		return ((float)p->delta_x / (float)p->delta_y);
	return (1);
}
