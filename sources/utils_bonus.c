/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/15 16:03:50 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	close_handler(t_fdf *fdf)
{
	free_mallocs(fdf);
	exit(EXIT_SUCCESS);
	return (0);
}

void	redraw_map(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw_map(fdf);
	draw_instructions(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
		fdf->image.pointer, 0, 0);
}

void	invert_colors(t_fdf *fdf)
{
	int	x;
	int	y;
	int	color;

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

void	hook_handlers(t_fdf *fdf)
{
	mlx_key_hook(fdf->win_ptr, on_key_press, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, close_handler, fdf);
}
