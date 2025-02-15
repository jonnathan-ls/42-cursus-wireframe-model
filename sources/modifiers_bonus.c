/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/14 22:38:08 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	invert_colors(t_fdf *fdf)
{
	unsigned int	x;
	unsigned int	y;
	int				color;

	y = 0;
	while (y < fdf->map.height)
	{
		x = 0;
		while (x < fdf->map.width)
		{
			color = fdf->map.coordinates[y][x].color;
			fdf->map.coordinates[y][x].color = color ^ 0x00FFFFFF;
			x++;
		}
		y++;
	}
}

void	offset_handler(int keycode, t_fdf *fdf)
{
	if (keycode == OFFSET_LEFT)
		(offset('l', fdf), redraw_map(fdf));
	else if (keycode == OFFSET_RIGHT)
		(offset('r', fdf), redraw_map(fdf));
	else if (keycode == OFFSET_UP)
		(offset('u', fdf), redraw_map(fdf));
	else if (keycode == OFFSET_DOWN)
		(offset('d', fdf), redraw_map(fdf));
}

void	rotate_handler(int keycode, t_fdf *fdf)
{
	if (keycode == ROTATE_LEFT)
		(rotate('l', fdf), redraw_map(fdf));
	else if (keycode == ROTATE_RIGHT)
		(rotate('r', fdf), redraw_map(fdf));
	else if (keycode == ROTATE_UP)
		(rotate('u', fdf), redraw_map(fdf));
	else if (keycode == ROTATE_DOWN)
		(rotate('d', fdf), redraw_map(fdf));
}

void	apply_conic_projection(int *x, int *y, int z, t_fdf	*fdf)
{
	int	previous_x;
	int	previous_y;
	int	previous_z;

	previous_x = *x;
	previous_y = *y;
	previous_z = z * fdf->factors.z_scale;
	*x = (previous_x * fdf->factors.focal_length)
		/ (fdf->factors.focal_length + previous_z);
	*y = (previous_y * fdf->factors.focal_length)
		/ (fdf->factors.focal_length + previous_z);
}
