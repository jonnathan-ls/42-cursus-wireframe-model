/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/14 01:27:52 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	redraw_map(t_fdf *fdf)
{
	if (fdf->map.image->pointer)
		mlx_destroy_image(fdf->mlx_ptr, fdf->map.image->pointer);
	fdf->map.image->pointer = mlx_new_image(fdf->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	if (fdf->map.image->pointer == NULL)
		exit_with_error(IMAGE_CREATION_ERROR, fdf);
	fdf->map.image->addr = mlx_get_data_addr(
			fdf->map.image->pointer, &fdf->map.image->bits_per_pixel,
			&fdf->map.image->line_length, &fdf->map.image->endian);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
		fdf->map.image->pointer, 0, 0);
}

int	on_key_press(int keycode, t_fdf	*fdf)
{
	if (fdf != NULL)
	{
		if (keycode == ESC)
		{
			free_mallocs(fdf);
			exit(EXIT_SUCCESS);
		}
		else if (keycode == ZOOM_IN)
			(zoom('i', fdf), redraw_map(fdf));
		else if (keycode == ZOOM_OUT)
			(zoom('o', fdf), redraw_map(fdf));
		offset_handler(keycode, fdf);
		rotate_handler(keycode, fdf);
		if (keycode == INCREASE_Z_SCALE)
			(scale('i', fdf), redraw_map(fdf));
		else if (keycode == DECREASE_Z_SCALE)
			(scale('d', fdf), redraw_map(fdf));
		else if (keycode == 99)
			(invert_colors(fdf), redraw_map(fdf));
	}
	return (0);
}

int	on_mouse_click(int button, t_fdf *fdf)
{
	if (fdf != NULL)
	{
		printf("Mouse clicked: %d\n", button);
	}
	return (0);
}
