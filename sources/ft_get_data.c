/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:44:44 by jlacerda          #+#    #+#             */
/*   Updated: 2024/12/25 20:42:05 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	***ft_extract_data(char *data)
{
	int		i;
	char	**lines;
	char	***matrix;

	lines = ft_split(data, BREAK_LINE_CHAR);
	if (!lines)
		return (NULL);
	i = 0;
	while (lines[i])
		i++;
	matrix = (char ***)malloc(sizeof(char **) * (i + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	while (lines[i])
	{
		matrix[i] = ft_split(lines[i], SPACE_CHAR);
		if (!matrix[i])
			return (NULL);
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

char	***ft_get_data(char *file)
{
	int		fd;
	char	*temp;
	char	*line;
	char	*data;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	data = ft_strdup(EMPTY_STRING);
	if (!data)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		temp = data;
		data = ft_strjoin(temp, line);
		free(temp);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (ft_extract_data(data));
}
