/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/15 17:32:13 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	reset_handler(t_fdf *fdf)
{
	fdf->factors.x_offset = 0;
	fdf->factors.y_offset = 0;
	if (fdf->factors.iso)
	{
		fdf->factors.x_angle = -0.615472907;
		fdf->factors.y_angle = -0.523599;
		fdf->factors.z_angle = 0.615472907;
	}
	else
	{
		fdf->factors.x_angle = -0.523599;
		fdf->factors.y_angle = -0.261799;
		fdf->factors.z_angle = 0;
	}
	fdf->factors.z_scale = 1;
	fdf->factors.zoom = get_min(WINDOW_WIDTH / fdf->map.width / 2,
			WINDOW_HEIGHT / fdf->map.height / 2);
}

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
	mlx_key_hook(fdf->win_ptr, key_press_handler, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, close_handler, fdf);
}
