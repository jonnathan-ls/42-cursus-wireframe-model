/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/15 17:24:07 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "mlx.h"
# include "libft.h"
# include "macros.h"
# include "structs.h"
# include "get_next_line.h"

float	absolute(float n);
void	swap(int *a, int *b);
void	draw_map(t_fdf *fdf);
int		get_min(int a, int b);
void	config_map(t_fdf *fdf);
void	free_split(char **split);
void	free_mallocs(t_fdf *fdf);
void	invert_colors(t_fdf *fdf);
void	config_factors(t_fdf	*fdf);
void	config_windown(t_fdf *fdf);
void	init_fdf_values(t_fdf *fdf);
bool	config_map_values(t_fdf *fdf);
float	get_slope(t_segment *segment);
void	config_coordinates(t_fdf *fdf);
void	xiaolin_wu_algorithm(t_fdf *fdf);
bool	validates_map_values(t_fdf *fdf);
void	remove_breakline_char(char *line);
void	exit_with_error(char *str, t_fdf *fdf);
void	apply_isometric_projection(t_coordinate *coord, t_fdf *fdf);
void	custom_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);

#endif
