/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/08 22:18:46 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include	<stdbool.h>

typedef struct s_point
{
	int	value;
	int	color;
}	t_point;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_map {
	unsigned int	width;
	unsigned int	height;
	int				shift_factor_in_x;
	int				shift_factor_in_y;
	double			rotate_factor_in_x;
	double			rotate_factor_in_y;
	t_point			**points;
	int				lowest_point;
	int				highest_point;
	t_image			*image;
	char			***values;
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

typedef struct s_fdf
{
	t_map		map;
	t_window	window;
	char		*file_path;
	bool		error_flag;
}	t_fdf;

#endif
