/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/13 00:27:35 by jlacerda         ###   ########.fr       */
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
	unsigned int	width;
	unsigned int	height;
	t_image			*image;
	char			***values;
	t_coordinate	**coordinates;
}	t_map;

/**
 * @brief Represents a number string.
 *
 * @param size The size of the number string.
 * @param value The value of the number string.
 * @param has_signal Whether the number string has a signal.
 * @param is_negative Whether the number string is negative.
 */
typedef struct s_num_str
{
	int			size;
	const char	*value;
	bool		has_signal;
	bool		is_negative;
}	t_num_str;

typedef struct s_factors
{
	int	x_zoom;
	int	y_zoom;
	int	x_displacement;
	int	y_displacement;
	int	rotation_angle;
}	t_factors;

typedef struct s_line
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}	t_line;

typedef struct s_segment
{
	int				range;
	float			slope;
	t_coordinate	final;
	t_coordinate	initial;
	float			overlap;
	int				delta_x;
	int				delta_y;
	float			distance;
	bool			is_vertical;
	float			final_distance;
	float			initial_distance;
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
