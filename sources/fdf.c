/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2024/12/25 20:44:54 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	char	***data;
	t_point	**points;

	if (argc != 2)
	{
		ft_printf("Error: invalid number of arguments.\n");
		return (1);
	}
	ft_printf("Reading data from file...\n");
	data = ft_get_data(argv[1]);
	if (!data)
	{
		ft_printf("Error reading data from file.\n");
		return (1);
	}
	points = ft_set_points(data);
	while (*points)
	{
		ft_printf("x: %d, y: %d, z: %d, color: %d\n", (*points)->x, (*points)->y, (*points)->z, (*points)->color);
		points++;
	}
}
