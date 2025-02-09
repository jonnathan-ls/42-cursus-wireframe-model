/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/08 22:38:30 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_map_height(t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		height;

	fd = open(fdf->file_path, O_RDONLY);
	height = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		height++;
		free(line);
	}
	fdf->map.height = height;
	close(fd);
}

static void	remove_breakline_char(char *line)
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

static void	read_lines(int fd, t_fdf *fdf)
{
	char	*line;
	int		length;
	char	**values;
	int		previous_width;

	line = NULL;
	values = NULL;
	previous_width = -1;
	while (true)
	{
		line = get_next_line(fd);
		remove_breakline_char(line);
		if (line == NULL)
			break ;
		values = ft_split(line, SPACE_CHAR);
		length = ft_strslen(values);
		if (previous_width != -1 && previous_width != length)
			fdf->error_flag = true;
		fdf->map.width = length;
		previous_width = length;
		free(line);
		free_split(values);
	}
}

void	set_map_width(t_fdf *fdf)
{
	int		fd;

	fd = open(fdf->file_path, O_RDONLY);
	read_lines(fd, fdf);
	if (fdf->error_flag)
		exit_with_error(INVALID_MAP_VALUES, fdf);
	close(fd);
}

void	config_map_dimensions(t_fdf *fdf)
{
	fdf->map.width = 0;
	fdf->map.height = 0;
	set_map_width(fdf);
	set_map_height(fdf);
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
