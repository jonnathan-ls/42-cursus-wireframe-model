/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_errors.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2024/12/29 20:17:04 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_ERRORS_H
# define FDF_ERRORS_H

int	fdf_mlx_init_error(void);
int	fdf_file_path_not_provided_error(void);
int	fdf_mlx_window_creation_error(void *mlx_ptr);
int	fdf_set_points_error(void *mlx_ptr, void *win_ptr);

#endif
