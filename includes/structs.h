/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/15 06:26:31 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include <stdbool.h>

typedef struct s_coordinate
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_coordinate;

typedef struct s_image
{
	char	*addr;
	void	*pointer;
	int		width;
	int		endian;
	int		height;
	int		line_length;
	int		bits_per_pixel;
}	t_image;

typedef struct s_map
{
	int				width;
	int				height;
	t_image			*image;
	char			***values;
	t_coordinate	**coordinates;
}	t_map;

typedef struct s_num_str
{
	int			size;
	const char	*value;
	bool		has_signal;
	bool		is_negative;
}	t_num_str;

typedef struct s_factors
{
	int		iso;
	int		zoom;
	double	x_angle;
	double	y_angle;
	double	z_angle;
	float	z_scale;
	int		x_offset;
	int		y_offset;
}	t_factors;

typedef struct s_color_factor
{
	int		integer;
	float	fractional;
	float	complement;
}	t_color_factor;

typedef struct s_color
{
	int				red;
	int				green;
	int				blue;
	double			opacity;
	t_color_factor	factor;
}	t_color;

typedef struct s_segment
{
	float			slope;
	t_color			color;
	t_coordinate	final;
	t_coordinate	initial;
	float			delta_x;
	float			delta_y;
	bool			reverse;
	bool			is_vertical;
}	t_segment;

typedef struct s_fdf
{
	t_map		map;
	t_factors	factors;
	t_segment	segment;
	void		*win_ptr;
	void		*mlx_ptr;
	char		*file_path;
	bool		error_flag;
}	t_fdf;

#endif
