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
	int		index;
	char	*dst;
	t_image	*img;

	dst = NULL;
	img = &fdf->image;
	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		index = (x * img->bits_per_pixel / 8) + (y * img->line_length);
		dst = img->addr + index;
		*(unsigned int *)dst = color;
	}
}

float	absolute(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

float	get_slope(t_segment *segment)
{
	segment->delta_x = (float)(segment->final.x - segment->initial.x);
	segment->delta_y = (float)(segment->final.y - segment->initial.y);
	if (segment->delta_x != 0)
		return (segment->delta_y / segment->delta_x);
	return (1);
}
