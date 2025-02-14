/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/14 01:25:50 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "macros.h"
# include "structs.h"

// Modifier functions
void	invert_colors(t_fdf *fdf);
void	apply_zoom(t_line *line, t_fdf *fdf);
void	apply_offset(t_line *line, t_fdf *fdf);
void	apply_rotation(int *x, int *y, t_fdf *fdf);
void	apply_conic_projection(int *x, int *y, int z, t_fdf	*fdf);
void	apply_isometric_projection(int *x, int *y, int z, float z_scale);

// Factor functions
void	zoom(char type, t_fdf *fdf);
void	scale(char type, t_fdf *fdf);
void	rotate(char axis, t_fdf *fdf);
void	translate(char type, t_fdf *fdf);
void	offset(char direction, t_fdf *fdf);

// Changer functions
void	redraw_map(t_fdf *fdf);
void	offset_handler(int keycode, t_fdf *fdf);
void	rotate_handler(int keycode, t_fdf *fdf);

void	draw_map(t_fdf *fdf);
void	free_split(char **split);
float	get_slope(t_segment *p);
void	free_mallocs(t_fdf *fdf);
void	init_fdf_values(t_fdf *fdf);
void	swap_coordinates(t_fdf *fdf);
bool	config_map_values(t_fdf *fdf);
void	config_coordinates(t_fdf *fdf);
void	xiaolin_wu_algorithm(t_fdf *fdf);
bool	validates_map_values(t_fdf *fdf);
void	remove_breakline_char(char *line);
int		on_close_window(t_fdf *fdf);
int		on_key_press(int keycode, t_fdf	*fdf);
int		on_mouse_click(int button, t_fdf *fdf);
void	exit_with_error(char *str, t_fdf *fdf);
int		interpolate_color( t_fdf *fdf, float opacity);
void	custom_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
#endif
