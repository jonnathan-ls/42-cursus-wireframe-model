/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2024/12/29 20:16:09 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_file_path_not_provided_error(void)
{
	ft_printf(FILE_PATH_NOT_PROVIDED_ERROR, FD_STDERR);
	ft_putstr_fd(FILE_ARGC_EXPECTED, FD_STDERR);
	return (EXIT_FAILURE);
}

int	fdf_mlx_init_error(void)
{
	ft_putstr_fd(MLX_INIT_ERROR, FD_STDERR);
	return (EXIT_FAILURE);
}

int	fdf_mlx_window_creation_error(void *mlx_ptr)
{
	mlx_destroy_display(mlx_ptr);
	ft_putstr_fd(WINDOW_CREATION_ERROR, FD_STDERR);
	return (EXIT_FAILURE);
}

int	fdf_set_points_error(void *mlx_ptr, void *win_ptr)
{
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	ft_putstr_fd(FILE_DATA_ERROR, FD_STDERR);
	return (EXIT_FAILURE);
}
