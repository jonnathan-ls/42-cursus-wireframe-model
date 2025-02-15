/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/15 18:17:33 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	key_press_handler(int keycode, t_fdf *fdf)
{
	printf("keycode %d\n", keycode);
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
	else if (keycode == ZOOM_IN || keycode == ZOOM_OUT)
		(zoom_handler(keycode, fdf), redraw_map(fdf));
	else if (keycode == ROTATE_LEFT || keycode == ROTATE_RIGHT)
		(rotate_handler(keycode, fdf), redraw_map(fdf));
	else if (keycode == SPACE)
		(projection_handler(fdf), redraw_map(fdf));
	return (0);
}
