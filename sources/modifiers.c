/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/14 22:33:10 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_isometric_projection(int *x, int *y, int z, float z_scale)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (previous_x + previous_y) * sin(0.523599) - z * z_scale;
}

void	apply_zoom(t_line *line, t_fdf *fdf)
{
	line->x0 *= fdf->factors.x_zoom;
	line->y0 *= fdf->factors.y_zoom;
	line->x1 *= fdf->factors.x_zoom;
	line->y1 *= fdf->factors.y_zoom;
}

void	apply_offset(t_line *line, t_fdf *fdf)
{
	line->x0 += fdf->factors.x_offset;
	line->y0 += fdf->factors.y_offset;
	line->x1 += fdf->factors.x_offset;
	line->y1 += fdf->factors.y_offset;
}

void	apply_rotation(int *x, int *y, t_fdf *fdf)
{
	int		x_new;
	int		y_new;
	double	x_rad;
	double	y_rad;

	x_rad = fdf->factors.x_rotation * M_PI / 180.0;
	y_rad = fdf->factors.y_rotation * M_PI / 180.0;
	x_new = *x * cos(x_rad) - *y * sin(x_rad);
	y_new = *x * sin(y_rad) + *y * cos(y_rad);
	*x = x_new;
	*y = y_new;
}
