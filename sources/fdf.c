/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2024/12/29 20:28:46 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_map(t_map *map);

int on_key_press(int keycode, t_map	*map)
{
	printf("Key pressed: %d\n", keycode);
	if (map != NULL)
	{
		if (keycode == 65362)
			map->shift_y -= 10;
		else if (keycode == 65364)
			map->shift_x += 10;
		else if (keycode == 65363)
			map->shift_y += 10;
		else if (keycode == 65361)
			map->shift_x -= 10;
		else if (keycode == 65307)
			exit(EXIT_SUCCESS);
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		draw_map(map);
	}
	return (0);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void set_sizes(t_map *map, char *file_path)
{
	int fd;
	char *line;
	char **words;

	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	words = ft_split(line, SPACE_CHAR);
	map->width = ft_strslen(words);
	map->height = 0;
	while (line)
	{
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	free_split(words);
	close(fd);
}

void set_points(t_point *line_points, char *line)
{
	int index;
	char **points;
	char *comma_ptr;
	bool has_color;

	index = 0;
	points = ft_split(line, SPACE_CHAR);
	while (points[index])
	{
		comma_ptr = ft_strchr(points[index], COMMA_CHAR);
		has_color = comma_ptr != NULL;
		line_points[index].value = ft_atoi(points[index]);
		if (has_color)
			line_points[index].color = ft_strtol(comma_ptr + 1);
		else
			line_points[index].color = DEFAULT_COLOR;
		free(points[index]);
		index++;
	}
	free(points);
}
void set_map(t_map *map, char *file_path)
{
	int fd;
	char *line;
	int index;

	map->points = (t_point **)malloc(sizeof(t_point *) * (map->height + 1));
	set_sizes(map, file_path);
	index = 0;
	while (index < map->height)
		map->points[index++] = (t_point *)malloc(sizeof(t_point) * (map->width + 1));
	fd = open(file_path, O_RDONLY);

	index = 0;
	line = NULL;
	while (index < map->height)
	{
		line = get_next_line(fd);
		set_points(map->points[index], line);
		free(line);
		index++;
	}
	map->points[index] = NULL;
	close(fd);
}

unsigned int get_abs_max(float a, float b)
{
	if (fabs(a) > fabs(b))
		return ((int)fabs(a));
	return ((int)fabs(b));
}

void isometric_projection(float *x, float *y, float z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void brasenham_line(float ix, float iy, float fx, float fy, t_map *map)
{
	float x_step;
	float y_step;
	int max;
	int zoom;
	int color;
	
	int iz = map->points[(int)iy][(int)ix].value;
	int fz = map->points[(int)fy][(int)fx].value;


	// ---------- ZOOM ----------------
	zoom = 20;
	ix = ix * zoom;
	iy = iy * zoom;
	fx = fx * zoom;
	fy = fy * zoom;
	// ---------- Color ----------------
	color = (iz) ? 0xe80c0c : 0xffffff;
	// ---------- 3D ----------------
	isometric_projection(&ix, &iy, iz);
	isometric_projection(&fx, &fy, fz);
	// ---------- Shift ---------------
	ix += map->shift_x;
	iy += map->shift_y;
	fx += map->shift_x;
	fy += map->shift_y;
	// ---------- Bresenham ---------------
	x_step = fx - ix;
	y_step = fy - iy;
	max = get_abs_max(x_step, y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(ix - fx) || (int)(iy - fy))

	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, ix, iy, color);
		ix += x_step;
		iy += y_step;
	}
}

void draw_map(t_map *map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				brasenham_line(x, y, x + 1, y, map);
			if (y < map->height - 1)
				brasenham_line(x, y, x, y + 1, map);
			x++;
		}
		y++;
	}
}


int main(int argc, char **argv)

{
 t_map map;


	if (argc != 2)
	{
		ft_printf("Error: Invalid number of arguments\n");
		return (EXIT_FAILURE);
	}
	set_map(&map, argv[1]);
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, 1000, 1000, "FDF");
	map.img_ptr = mlx_new_image(map.mlx_ptr, 1000, 1000);
	
	// map.mlx_ptr = mlx_init();
	// map.win_ptr = mlx_new_window(map.mlx_ptr, WIDTH, HEIGHT, "FDF");
	// map.img_ptr = mlx_new_image(map.mlx_ptr, WIDTH, HEIGHT);
	// map.image->addr = mlx_get_data_addr(map.image->img_ptr, &map.image->bits_per_pixel, &map.image->line_length, &map.image->endian);
	// map.image->width = map.width;
	// map.image->height = map.height;

	map.shift_x = 150;
	map.shift_y = 150;
	draw_map(&map);
	mlx_key_hook(map.win_ptr, on_key_press, &map);
	mlx_loop(map.mlx_ptr);

	return (EXIT_SUCCESS);
}
