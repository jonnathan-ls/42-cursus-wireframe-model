/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/15 06:35:03 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_instructions(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 0, 0xFFFFFF,
		"Left Click:   Pan");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 20, 0xFFFFFF,
		"Right Click:  Rotate x/y");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 40, 0xFFFFFF,
		"Middle Click: Rotate z");
	if (fdf->factors.iso)
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 60, 0xFFFFFF,
			"Space:        Toggle projection (Current: Isometric)");
	else
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 60, 0xFFFFFF,
			"Space:        Toggle projection (Current: Parrallel)");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 80, 0xFFFFFF,
		"R:            Reset");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 100, 0xFFFFFF,
		"-/+:          Flatten");
}

int	close_handler(t_fdf *fdf)
{
	free_mallocs(fdf);
	exit(EXIT_SUCCESS);
	return (0);
}

void	redraw_map(t_fdf *fdf)
{
	if (fdf->map.image->pointer)
		mlx_destroy_image(fdf->mlx_ptr, fdf->map.image->pointer);
	fdf->map.image->pointer = mlx_new_image(fdf->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	if (fdf->map.image->pointer == NULL)
		exit_with_error(IMAGE_CREATION_ERROR, fdf);
	fdf->map.image->addr = mlx_get_data_addr(
			fdf->map.image->pointer, &fdf->map.image->bits_per_pixel,
			&fdf->map.image->line_length, &fdf->map.image->endian);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw_map(fdf);
	draw_instructions(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
		fdf->map.image->pointer, 0, 0);
}

void	invert_colors(t_fdf *fdf)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < fdf->map.height)
	{
		x = 0;
		while (x < fdf->map.width)
		{
			color = fdf->map.coordinates[y][x].color;
			fdf->map.coordinates[y][x].color = color ^ 0x00FFFFFF;
			x++;
		}
		y++;
	}
}

void	hook_handlers(t_fdf *fdf)
{
	mlx_key_hook(fdf->win_ptr, on_key_press, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, close_handler, fdf);
}
