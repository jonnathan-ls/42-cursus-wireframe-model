/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/15 16:01:56 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	reset_handler(t_fdf *fdf)
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

static void	projection_handler(t_fdf *fdf)
{
	if (fdf->factors.iso)
	{
		fdf->factors.x_angle = -0.523599;
		fdf->factors.y_angle = -0.261799;
		fdf->factors.z_angle = 0;
	}
	else
	{
		fdf->factors.x_angle = -0.615472907;
		fdf->factors.y_angle = -0.523599;
		fdf->factors.z_angle = 0.615472907;
	}
	fdf->factors.iso = !fdf->factors.iso;
}

static void	z_scale_handler(int keycode, t_fdf *fdf)
{
	if (keycode == MINUS)
		fdf->factors.z_scale += 0.5;
	else if (keycode == PLUS)
		fdf->factors.z_scale -= 0.5;
	if (fdf->factors.z_scale < 0.5)
		fdf->factors.z_scale = 0.5;
	else if (fdf->factors.z_scale > 10)
		fdf->factors.z_scale = 10;
}

static void	offset_handler(int keycode, t_fdf *fdf)
{
	if (keycode == ARROW_LEFT)
		fdf->factors.x_offset -= 10;
	else if (keycode == ARROW_RIGHT)
		fdf->factors.x_offset += 10;
	else if (keycode == ARROW_DOWN)
		fdf->factors.y_offset += 10;
	else if (keycode == ARROW_UP)
		fdf->factors.y_offset -= 10;
}

int	on_key_press(int keycode, t_fdf *fdf)
{
	if (fdf == NULL)
		return (0);
	if (keycode == ESC)
		close_handler(fdf);
	else if (keycode == RESET)
		(reset_handler(fdf), redraw_map(fdf));
	else if (keycode == INVERT_COLOR)
		(invert_colors(fdf), redraw_map(fdf));
	else if (keycode == ARROW_DOWN || keycode == ARROW_LEFT
		|| keycode == ARROW_UP || keycode == ARROW_RIGHT)
		(offset_handler(keycode, fdf), redraw_map(fdf));
	else if (keycode == MINUS || keycode == PLUS)
		(z_scale_handler(keycode, fdf), redraw_map(fdf));
	else if (keycode == SPACE)
		(projection_handler(fdf), redraw_map(fdf));
	return (0);
}

	// mlx_hook(fdf->win_ptr, 4, 0, ft_mouse_down, fdf);
	// mlx_hook(fdf->win_ptr, 5, 0, ft_mouse_up, fdf);
	// mlx_hook(fdf->win_ptr, 6, 0, ft_mouse_move, fdf);
