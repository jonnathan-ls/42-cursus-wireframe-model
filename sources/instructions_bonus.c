/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/15 16:03:38 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_str_in_map(char *str, int x, int y, t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0x00FFFFFF, str);
}

void	draw_instructions(t_fdf *fdf)
{
	put_str_in_map("| ------- MENU ------ |", 10, 10, fdf);
}
