/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/13 03:27:15 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void zoom_in(t_fdf *fdf)
{
	fdf->factors.x_zoom *= 1.1;
	fdf->factors.y_zoom *= 1.1;
}

void zoom_out(t_fdf *fdf)
{
	fdf->factors.x_zoom /= 1.1;
	fdf->factors.y_zoom /= 1.1;
}

void translate_model(t_fdf *fdf, int x_offset, int y_offset)
{
	fdf->factors.x_displacement += x_offset;
	fdf->factors.y_displacement += y_offset;
}

void rotate_model(t_fdf *fdf, double angle, bool is_x_axis)
{
	if (is_x_axis)
		fdf->factors.x_rotation += angle;
	else
		fdf->factors.y_rotation += angle;
}

void increase_z_scale(t_fdf *fdf)
{
	fdf->factors.z_scale *= 1.5;
}

void decrease_z_scale(t_fdf *fdf)
{
	fdf->factors.z_scale /= 1.5;
}

static void	redraw_map(t_fdf *fdf)
{
	printf("Redrawing map\n");
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

void invert_colors(t_fdf *fdf)
{
		for (unsigned int y = 0; y < fdf->map.height; y++)
		{
			for (unsigned int x = 0; x < fdf->map.width; x++)
			{
				int color = fdf->map.coordinates[y][x].color;
				int red = 255 - ((color >> 16) & 0xFF);
				int green = 255 - ((color >> 8) & 0xFF);
				int blue = 255 - (color & 0xFF);
				fdf->map.coordinates[y][x].color = (red << 16) | (green << 8) | blue;
			}
		}
}

int	on_key_press(int keycode, t_fdf	*fdf)
{
	printf("Key pressed: %d\n", keycode);
	if (fdf != NULL)
	{
		if (keycode == ESC_KEY)
		{
			free_mallocs(fdf);
			exit(EXIT_SUCCESS);
		}
		if (keycode == KEY_ZOOM_IN)
			(zoom_in(fdf), redraw_map(fdf));
		else if (keycode == KEY_ZOOM_OUT)
			(zoom_out(fdf), redraw_map(fdf));
		else if (keycode == KEY_TRANSLATE_LEFT)
			(translate_model(fdf, -10, 0), redraw_map(fdf));
		else if (keycode == KEY_TRANSLATE_RIGHT)
			(translate_model(fdf, 10, 0), redraw_map(fdf));
		else if (keycode == KEY_ROTATE_LEFT)
			(rotate_model(fdf, -5, true), redraw_map(fdf));
		else if (keycode == KEY_ROTATE_RIGHT)
			(rotate_model(fdf, 5, true), redraw_map(fdf));
		else if (keycode == KEY_ROTATE_UP)
			(rotate_model(fdf, -5, false), redraw_map(fdf));
		else if (keycode == KEY_ROTATE_DOWN)
			(rotate_model(fdf, 5, false), redraw_map(fdf));
		else if (keycode == KEY_RANDOM_COLOR)
			(invert_colors(fdf), redraw_map(fdf));
		else	if (keycode == KEY_INCREASE_Z_SCALE)
			(increase_z_scale(fdf), redraw_map(fdf));
		else if (keycode == KEY_DECREASE_Z_SCALE)
			(decrease_z_scale(fdf), redraw_map(fdf));
	}
	return (0);
}
