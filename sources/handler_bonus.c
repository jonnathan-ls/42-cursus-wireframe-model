/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/15 18:29:49 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	zoom_handler(int keycode, t_fdf *fdf)
{
	if (keycode == ZOOM_IN)
		fdf->factors.zoom += 3;
	else if (keycode == ZOOM_OUT)
		fdf->factors.zoom -= 3;
	if (fdf->factors.zoom < 1)
		fdf->factors.zoom = 1;
}

void	projection_handler(t_fdf *fdf)
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

void	z_scale_handler(int keycode, t_fdf *fdf)
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

void	offset_handler(int keycode, t_fdf *fdf)
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

void	rotate_handler(int keycode, t_fdf *fdf)
{
	if (keycode == ROTATE_LEFT)
		fdf->factors.z_angle -= 0.2;
	else if (keycode == ROTATE_RIGHT)
		fdf->factors.z_angle += 0.2;
	if (fdf->factors.z_angle > MAX_ANGLE)
		fdf->factors.z_angle = MIN_ANGLE;
	else if (fdf->factors.z_angle < MIN_ANGLE)
		fdf->factors.z_angle = MAX_ANGLE;
}
