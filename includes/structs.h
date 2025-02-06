/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/05 21:14:45 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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

typedef struct s_draw_params
{
	t_point	initialPoint;
	t_point	finalPoint;
	int		delta_x;
	int		delta_y;
	float	slope;
	t_image	*img;
}	t_draw_params;


// typedef struct s_draw_params
// {
// 	t_point	initialPoint;
// 	t_point	finalPoint;
// 	int		delta_x;
// 	int		delta_y;
// 	int		int_x;
// 	int		int_y;
// 	int		range;
// 	int		color;
// 	int		index_control;
// 	float	temp_x;
// 	float	temp_y;
// 	float	slope;
// 	float	distance;
// 	int		is_vertical;
// 	t_image	*img;
// }	t_draw_params;

typedef struct s_config
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				width;
	int				height;
	t_image			img;
	t_point			**points;
	t_draw_params	draw_params;
}	t_config;

typedef struct s_map {
	int shift_factor_in_x;
	int shift_factor_in_y;
	double rotate_factor_in_x;
	double rotate_factor_in_y;
	int     width;     // Número de colunas
	int     height;    // Número de linhas
	t_point **points;  // Matriz de pontos com altitude e cor
	int     lowest_point;     // Valor mínimo de altitude
	int     highest_point;     // Valor maximo de altitude
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	t_image			*image;
} t_map;

typedef struct s_line {
	int ix;
	int iy;
	int fx;
	int fy;
	float slope;
	int is_vertical;
} t_line;

#endif
