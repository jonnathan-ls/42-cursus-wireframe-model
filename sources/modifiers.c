/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/15 03:36:54 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_isometric_projection(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (previous_x + previous_y) * sin(0.523599) - z;
}

// void	apply_zoom(t_line *line, t_fdf *fdf)
// {
// 	line->x0 *= fdf->factors.zoom;
// 	line->y0 *= fdf->factors.zoom;
// 	line->x1 *= fdf->factors.zoom;
// 	line->y1 *= fdf->factors.zoom;
// }

// void	apply_offset(t_line *line, t_fdf *fdf)
// {
// 	line->x0 += fdf->factors.x_offset;
// 	line->y0 += fdf->factors.y_offset;
// 	line->x1 += fdf->factors.x_offset;
// 	line->y1 += fdf->factors.y_offset;
// }

