/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/08 22:40:03 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	fdf.map.image = NULL;
	fdf.map.values = NULL;
	fdf.map.points = NULL;
	fdf.error_flag = false;

	if (argc != 2)
	{
		ft_putstr_fd(INVALID_ARGS_ERROR, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	fdf.file_path = argv[1];
	config_map_dimensions(&fdf);
	if (!config_map_values(&fdf))
		exit_with_error(MAP_DATA_ERROR, &fdf);
	if (fdf.map.height == 0 || fdf.map.width == 0)
		exit_with_error(MAP_EMPTY_ERROR, &fdf);
	if (!validates_map_values(&fdf))
		exit_with_error(INVALID_MAP_VALUES, &fdf);
	free_mallocs(&fdf);
}

// PRECISA CORRIGIR GET_NEXT_LINE quando nao é lido até o final, para liberar memoria

