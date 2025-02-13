/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/12 21:40:58 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_coordinate(int line_index, int column_index, t_fdf *fdf)
{
	char			*value;
	char			*comma_ptr;
	t_coordinate	*coordinate;

	coordinate = &fdf->map.coordinates[line_index][column_index];
	value = fdf->map.values[line_index][column_index];
	coordinate->color = DEFAULT_COLOR;
	comma_ptr = ft_strchr(value, COMMA_CHAR);
	if (comma_ptr != NULL)
	{
		coordinate->color = ft_strtol(comma_ptr + 1);
	}
	coordinate->z = ft_atoi(value);
	coordinate->x = column_index;
	coordinate->y = line_index;
}

void	config_coordinates(t_fdf *fdf)
{
	unsigned int	line;
	unsigned int	column;

	line = 0;
	fdf->map.coordinates = (t_coordinate **)
		malloc(sizeof(t_coordinate *) * (fdf->map.height + 1));
	while (fdf->map.values[line] != NULL)
	{
		column = 0;
		fdf->map.coordinates[line] = (t_coordinate *)
			malloc(sizeof(t_coordinate) * (fdf->map.width + 1));
		while (fdf->map.values[line][column] != NULL)
		{
			set_coordinate(line, column, fdf);
			column++;
		}
		line++;
	}
}

bool	config_map_values(t_fdf *fdf)
{
	int				fd;
	unsigned int	index;
	char			*line_str;

	index = 0;
	line_str = NULL;
	fd = open(fdf->file_path, O_RDONLY);
	fdf->map.values = (char ***)malloc(sizeof(char **) * (fdf->map.height + 1));
	while (true)
	{
		line_str = get_next_line(fd);
		remove_breakline_char(line_str);
		if (line_str == NULL)
			break ;
		fdf->map.values[index] = ft_split(line_str, SPACE_CHAR);
		if (fdf->map.values[index] == NULL)
			return (false);
		free(line_str);
		index++;
	}
	fdf->map.values[index] = NULL;
	return (true);
}
