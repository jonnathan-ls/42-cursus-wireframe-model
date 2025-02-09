/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/08 20:28:10 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include "macros.h"
# include "structs.h"
# include "fdf_errors.h"
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <errno.h>

void process_points(t_config *conf);
char	***ft_get_data(char *file_path);
void draw_line(int x0, int y0, int x1, int y1, int color, t_image *img);
// void set_points(t_config *config, char ***data);
// void	custom_mlx_pixel_put(t_image *img, int x, int y, int color);

bool	is_valid_integer(const char *number_str);
void	free_split(char **split);
void	exit_with_error(char *str, t_fdf *fdf);
bool	validates_map_values(t_fdf *fdf);

#endif
