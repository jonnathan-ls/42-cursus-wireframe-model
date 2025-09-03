/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/09/02 21:53:18 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_str_in_map(char *str, t_fdf *fdf, int end_instructions)
{
	static int	x_offset = 20;
	static int	y_offset = 30;

	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
		x_offset, y_offset, 0x00FFFFFF, str);
	if (end_instructions)
	{
		y_offset = 30;
		return ;
	}
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, x_offset, y_offset + 10,
		0x00FFFFFF, "|                               |");
	y_offset += 20;
}

void	draw_instructions(t_fdf *fdf)
{
	put_str_in_map("| ----------------------------- |", fdf, 0);
	put_str_in_map("| Move Up:          Arrow Up    |", fdf, 0);
	put_str_in_map("| Move Down:        Arrow Down  |", fdf, 0);
	put_str_in_map("| Move Left:        Arrow Left  |", fdf, 0);
	put_str_in_map("| Move Right:       Arrow Right |", fdf, 0);
	put_str_in_map("| Change Isometric: Space       |", fdf, 0);
	put_str_in_map("| Invert Colors:    C           |", fdf, 0);
	put_str_in_map("| Reset Changes:    R           |", fdf, 0);
	put_str_in_map("| Turn Right:       D           |", fdf, 0);
	put_str_in_map("| Turn Left:        A           |", fdf, 0);
	put_str_in_map("| Zoom In:          I           |", fdf, 0);
	put_str_in_map("| Zoom Out:         O           |", fdf, 0);
	put_str_in_map("| ----------------------------- |", fdf, 1);
}
