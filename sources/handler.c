/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/13 01:44:26 by jlacerda         ###   ########.fr       */
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

void rotate_model(t_fdf *fdf, double angle)
{
	fdf->factors.rotation_angle += angle;
}

static void	redraw_map(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
		fdf->map.image->pointer, 0, 0);
}

void change_color(t_fdf *fdf, int color)
{
	int	factor_change;

	factor_change = 10;
	if (color == 1)
		fdf->factors.red_color += factor_change;
	else if (color == 2)
		fdf->factors.green_color += factor_change;
	else if (color == 3)
		fdf->factors.blue_color += factor_change;
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
			(rotate_model(fdf, -5), redraw_map(fdf));
		else if (keycode == KEY_ROTATE_RIGHT)
			(rotate_model(fdf, 5), redraw_map(fdf));
		else if (keycode == KEY_RED_COLOR)
			(change_color(fdf, 1), redraw_map(fdf));
		else if (keycode == KEY_GREEN_COLOR)
			(change_color(fdf, 2), redraw_map(fdf));
		else if (keycode == KEY_BLUE_COLOR)
			(change_color(fdf, 3), redraw_map(fdf));
	}
	return (0);
}
