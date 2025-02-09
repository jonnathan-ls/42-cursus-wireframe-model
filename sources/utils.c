/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/10 22:16:11 by jlacerda         ###   ########.fr       */
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

void	free_mallocs(t_fdf *fdf)
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
		if (fdf->map.coordinates[line] != NULL)
			free(fdf->map.coordinates[line]);
		line++;
	}
	free(fdf->map.values);
	free(fdf->map.coordinates);
}

void	exit_with_error(char *str, t_fdf *fdf)
{
	free_mallocs(fdf);
	if (errno == 0)
		ft_putstr_fd(str, STDERR_FILENO);
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
