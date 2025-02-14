/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/14 02:23:28 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(char type, t_fdf *fdf)
{
	if (type == 'i')
	{
		fdf->factors.x_zoom *= 1.1;
		fdf->factors.y_zoom *= 1.1;
	}
	else
	{
		fdf->factors.x_zoom /= 1.1;
		fdf->factors.y_zoom /= 1.1;
	}
}

void	offset(char direction, t_fdf *fdf)
{
	if (direction == 'l')
		fdf->factors.x_offset -= 25;
	else if (direction == 'r')
		fdf->factors.x_offset += 25;
	else if (direction == 'u')
		fdf->factors.y_offset -= 25;
	else
		fdf->factors.y_offset += 25;
}

void	rotate(char direction,	t_fdf *fdf)
{
	printf("Rotating %c\n", direction);
	if (direction == 'l')
		fdf->factors.x_rotation -= 10;
	else if (direction == 'r')
		fdf->factors.x_rotation += 10;
	else if (direction == 'u')
		fdf->factors.y_rotation -= 10;
	else
		fdf->factors.y_rotation += 10;
}

void	scale(char type, t_fdf *fdf)
{
	if (type == 'i')
		fdf->factors.z_scale *= 1.5;
	else
		fdf->factors.z_scale /= 1.5;
}
