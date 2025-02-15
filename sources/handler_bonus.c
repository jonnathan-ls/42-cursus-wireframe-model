/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/15 00:44:28 by jlacerda         ###   ########.fr       */
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

// static void	ft_reset(t_fdf *fdf)
// {
// 	fdf->factors.x_offset = 0;
// 	fdf->factors.y_offset = 0;
// 	if (fdf->factors.iso)
// 	{
// 		fdf->factors.x_angle = -0.615472907;
// 		fdf->factors.y_angle = -0.523599;
// 		fdf->factors.z_angle = 0.615472907;
// 	}
// 	else
// 	{
// 		fdf->factors.x_angle = -0.523599;
// 		fdf->factors.y_angle = -0.261799;
// 		fdf->factors.z_angle = 0;
// 	}
// 	fdf->factors.z_height = 1;
// 	fdf->factors.zoom = ft_min(WINDOW_WIDTH / fdf->map.width / 2,
// 			WINDOW_HEIGHT / fdf->map.height / 2);
// }

// static void	ft_toggle_projection(t_fdf *fdf)
// {
// 	if (fdf->factors.iso)
// 	{
// 		fdf->factors.x_angle = -0.523599;
// 		fdf->factors.y_angle = -0.261799;
// 		fdf->factors.z_angle = 0;
// 	}
// 	else
// 	{
// 		fdf->factors.x_angle = -0.615472907;
// 		fdf->factors.y_angle = -0.523599;
// 		fdf->factors.z_angle = 0.615472907;
// 	}
// 	fdf->factors.iso = !fdf->factors.iso;
// }

// static void	ft_mod_height(int keycode, t_fdf *fdf)
// {
// 	if (keycode == MINUS)
// 		fdf->factors.z_height += 0.1;
// 	else if (keycode == PLUS)
// 		fdf->factors.z_height -= 0.1;
// 	if (fdf->factors.z_height < 0.1)
// 		fdf->factors.z_height = 0.1;
// 	else if (fdf->factors.z_height > 10)
// 		fdf->factors.z_height = 10;
// }

// static void	ft_translate(int keycode, t_fdf *fdf)
// {
// 	if (keycode == ARROW_LEFT)
// 		fdf->factors.x_offset -= 10;
// 	else if (keycode == ARROW_RIGHT)
// 		fdf->factors.x_offset += 10;
// 	else if (keycode == ARROW_DOWN)
// 		fdf->factors.y_offset += 10;
// 	else if (keycode == ARROW_UP)
// 		fdf->factors.y_offset -= 10;
// }

// int	ft_key_press(int keycode, void *params)
// {
// 	t_fdf	*env;

// 	env = (t_fdf *)params;
// 	if (keycode == ARROW_DOWN || keycode == ARROW_LEFT || keycode == ARROW_UP
// 		|| keycode == ARROW_RIGHT)
// 		ft_translate(keycode, env);
// 	else if (keycode == MINUS || keycode == PLUS)
// 		ft_mod_height(keycode, env);
// 	else if (keycode == SPACE)
// 		ft_toggle_projection(env);
// 	else if (keycode == KEY_R)
// 		ft_reset(env);
// 	else if (keycode == ESCAPE)
// 		ft_close_win(env);
// 	ft_draw(fdf->map, env);
// 	return (0);
// }