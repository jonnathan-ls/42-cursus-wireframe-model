/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/09/02 21:34:19 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# include "fdf.h"

# define PLUS 61
# define MINUS 45
# define SPACE 32
# define RESET 114
# define ZOOM_IN 105
# define ZOOM_OUT 111
# define ARROW_UP 65362
# define INVERT_COLOR 99
# define ZOOM_IN 105
# define ZOOM_OUT 111
# define ROTATE_LEFT 97
# define ROTATE_RIGHT 100
# define MAX_ANGLE M_PI
# define MIN_ANGLE -M_PI
# define ARROW_LEFT 65361
# define ARROW_DOWN 65364
# define ARROW_RIGHT 65363
# define INCREASE_Z_SCALE 122
# define DECREASE_Z_SCALE 120

void	redraw_map(t_fdf *fdf);
int		close_handler(t_fdf *fdf);
void	reset_handler(t_fdf *fdf);
void	hook_handlers(t_fdf *fdf);
void	draw_instructions(t_fdf *fdf);
void	projection_handler(t_fdf *fdf);
void	zoom_handler(int keycode, t_fdf *fdf);
void	offset_handler(int keycode, t_fdf *fdf);
void	rotate_handler(int keycode, t_fdf *fdf);
void	z_scale_handler(int keycode, t_fdf *fdf);
int		key_press_handler(int keycode, t_fdf *fdf);

#endif
