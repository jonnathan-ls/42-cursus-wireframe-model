/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/12 02:28:44 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	free_map_values(t_fdf *fdf)
{
	unsigned int	line;
	unsigned int	column;

	line = 0;
	while (line < fdf->map.height)
	{
		column = 0;
		while (column < fdf->map.width)
		{
			if (fdf->map.values[line][column] != NULL)
				free(fdf->map.values[line][column]);
			column++;
		}
		free(fdf->map.values[line]);
		line++;
	}
	free(fdf->map.values);
}

static void	free_coordinates(t_fdf *fdf)
{
	unsigned int	line;

	line = 0;
	while (line < fdf->map.height)
	{
		if (fdf->map.coordinates[line] != NULL)
			free(fdf->map.coordinates[line]);
		line++;
	}
	free(fdf->map.coordinates);
}

void	free_mallocs(t_fdf *fdf)
{
	if (fdf->map.values)
		free_map_values(fdf);
	if (fdf->map.coordinates)
		free_coordinates(fdf);
	if (fdf->map.image)
	{
		if (fdf->map.image->pointer)
			mlx_destroy_image(fdf->mlx_ptr, fdf->map.image->pointer);
		free(fdf->map.image);
	}
	if (fdf->win_ptr)
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	if (fdf->mlx_ptr)
	{
		mlx_destroy_display(fdf->mlx_ptr);
		free(fdf->mlx_ptr);
	}
}

void	exit_with_error(char *str, t_fdf *fdf)
{
	free_mallocs(fdf);
	if (errno == 0)
		ft_putendl_fd(str, STDERR_FILENO);
	else
		perror(str);
	exit(EXIT_FAILURE);
}

void	remove_breakline_char(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return ;
	while (line[i])
	{
		if (line[i] == BREAK_LINE_CHAR)
			line[i] = NULL_CHAR;
		i++;
	}
}

void	custom_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;
	t_image	*img;

	// printf("x: %d, y: %d, color: %d\n", x, y, color);
	img = fdf->map.image;
	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
