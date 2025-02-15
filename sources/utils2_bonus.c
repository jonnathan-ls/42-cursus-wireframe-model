/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/15 17:32:41 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fdf_bonus.h"

// void	zoom_handler(int button, t_fdf *fdf)
// {
// 	printf("button: %d\n", button);
// 	if (button == MOUSE_WHEEL_UP)
// 		fdf->factors.zoom += 2;
// 	else if (button == MOUSE_WHEEL_DOWN)
// 		fdf->factors.zoom -= 2;
// 	if (fdf->factors.zoom < 1)
// 		fdf->factors.zoom = 1;
// 	redraw_map(fdf);
// }

// int	ft_mouse_down(int button, int x, int y, t_fdf *fdf)
// {
// 	t_fdf	*env;

// 	env = (t_fdf *)params;
// 	if (button == MOUSE_WHEEL_UP || button == MOUSE_WHEEL_DOWN)
// 		ft_zoom(button, env);
// 	else if (button == MOUSE_CLICK_LEFT || button == MOUSE_CLICK_RIGHT
// 		|| button == MOUSE_CLICK_MIDDLE)
// 	{
// 		env->mouse->button = button;
// 		env->mouse->prev_x = x;
// 		env->mouse->prev_y = y;
// 	}
// 	return (0);
// }

// int	ft_mouse_up(int button, int x, int y, t_fdf *fdf)
// {
// 	t_fdf	*env;

// 	(void)x;
// 	(void)y;
// 	env = (t_fdf *)params;
// 	if (button == MOUSE_CLICK_LEFT || button == MOUSE_CLICK_RIGHT
// 		|| button == MOUSE_CLICK_MIDDLE)
// 		env->mouse->button = 0;
// 	return (0);
// }

// static void	ft_move_z(int x, int y, t_fdf *fdf)
// {
// 	if (x < (WIDTH / 2) + fdf->factors.x_offset)
// 		fdf->factors.z_angle -= (y - env->mouse->prev_y) * 0.002;
// 	else
// 		fdf->factors.z_angle += (y - env->mouse->prev_y) * 0.002;
// 	env->mouse->prev_x = x;
// 	env->mouse->prev_y = y;
// 	ft_draw(env->map, env);
// }

// int	ft_mouse_move(int x, int y, t_fdf *fdf)
// {
// 	t_fdf	*env;

// 	env = (t_fdf *)params;
// 	if (env->mouse->button == MOUSE_CLICK_RIGHT)
// 	{
// 		fdf->factors.x_angle += (y - env->mouse->prev_y) * 0.002;
// 		fdf->factors.y_angle += (x - env->mouse->prev_x) * 0.002;
// 		fdf->factors.x_angle = ft_reset_angles(fdf->factors.x_angle);
// 		fdf->factors.y_angle = ft_reset_angles(fdf->factors.y_angle);
// 		env->mouse->prev_x = x;
// 		env->mouse->prev_y = y;
// 		ft_draw(env->map, env);
// 	}
// 	else if (env->mouse->button == MOUSE_CLICK_LEFT)
// 	{
// 		fdf->factors.x_offset += (x - env->mouse->prev_x);
// 		fdf->factors.y_offset += (y - env->mouse->prev_y);
// 		env->mouse->prev_x = x;
// 		env->mouse->prev_y = y;
// 		ft_draw(env->map, env);
// 	}
// 	else if (env->mouse->button == MOUSE_CLICK_MIDDLE)
// 		ft_move_z(x, y, env);
// 	return (0);
// }
