/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/11 21:23:25 by jlacerda         ###   ########.fr       */
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
	void	*img_ptr;
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

typedef struct s_window
{
	int		width;
	int		height;
	char	*title;
	t_map	map;
}	t_window;

typedef struct s_factors
{
	int	zoom;
	int	displacement;
}	t_factors;

typedef struct s_draw_params
{
	float	initial_x;
	float	initial_y;
	float	final_x;
	float	final_y;
	int	initial_z;
	int	final_z;
	float	step_x;
	float	step_y;
	int color;
}	t_draw_params;

typedef struct s_fdf
{
	t_map		map;
	t_window	window;
	char		*file_path;
	bool		error_flag;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_factors	factors;
}	t_fdf;

#endif
