/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/12 22:40:07 by jlacerda         ###   ########.fr       */
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
int		on_key_press(int keycode, t_fdf	*fdf);
void	exit_with_error(char *str, t_fdf *fdf);
int		interpolate_color( t_fdf *fdf, float opacity);
void	draw_line(int x0, int y0, int x1, int y1, t_fdf *fdf);
void	custom_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);

#endif
