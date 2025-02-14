/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/14 01:26:28 by jlacerda         ###   ########.fr       */
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

int	on_close_window(t_fdf *fdf)
{
	free_mallocs(fdf);
	exit(EXIT_SUCCESS);
	return (0);
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

