/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/12 02:29:07 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	print_map(t_fdf *fdf)
// {
// 	unsigned int	i;
// 	unsigned int	j;

// 	i = 0;
// 	while (i < fdf->map.height)
// 	{
// 		j = 0;
// 		while (j < fdf->map.width)
// 		{
// 			ft_printf("%3d ", fdf->map.coordinates[i][j].z);
// 			j++;
// 		}
// 		ft_printf("\n");
// 		i++;
// 	}
// }

// void	draw_map(t_fdf *fdf)
// {
// 	unsigned int	x;
// 	unsigned int	y;
// 	t_draw_params	p;

// 	x = 0;
// 	y = 0;
// 	while (y < fdf->map.height)
// 	{
// 		x = 0;
// 		while (x < fdf->map.width)
// 		{
// 			p = (t_draw_params){
// 				.initial_x = x,
// 				.initial_y = y,
// 				.final_x = x,
// 				.final_y = y,
// 			};
// 			if (x < fdf->map.width - 1)
// 			{
// 				p.final_y = y;
// 				p.final_x = x + 1;
// 				draw_line(p, fdf);
// 			}
// 			if (y < fdf->map.height - 1)
// 			{
// 				p.final_x = x;
// 				p.final_y = y + 1;
// 				draw_line(p, fdf);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	fdf.map.image = NULL;
	fdf.map.values = NULL;
	fdf.error_flag = false;
	fdf.map.coordinates = NULL;
	if (argc != 2)
	{
		ft_putstr_fd(INVALID_ARGS_ERROR, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	fdf.file_path = argv[1];
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	fdf.map.image = (t_image *)malloc(sizeof(t_image));
	fdf.map.image->img_ptr = mlx_new_image(
			fdf.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	fdf.map.image->addr = mlx_get_data_addr(
			fdf.map.image->img_ptr, &fdf.map.image->bits_per_pixel,
			&fdf.map.image->line_length, &fdf.map.image->endian);
	config_map_dimensions(&fdf);
	if (!config_map_values(&fdf))
		exit_with_error(MAP_DATA_ERROR, &fdf);
	if (fdf.map.height == 0 || fdf.map.width == 0)
		exit_with_error(MAP_EMPTY_ERROR, &fdf); // Precisa corrigir aqui da segment fault
	if (!validates_map_values(&fdf))
		exit_with_error(INVALID_MAP_VALUES, &fdf);
	config_coordinates(&fdf);
	draw_map(&fdf);
	mlx_put_image_to_window(fdf.mlx_ptr,
		fdf.win_ptr, fdf.map.image->img_ptr, 0, 0);
	mlx_loop(fdf.mlx_ptr);
	free_mallocs(&fdf);
	return (EXIT_SUCCESS);
}

// PRECISA CORRIGIR GET_NEXT_LINE quando nao é lido até o final, para liberar memoria

