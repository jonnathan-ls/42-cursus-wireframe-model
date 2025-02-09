/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/08 20:47:58 by jlacerda         ###   ########.fr       */
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

	if (fdf->map.values != NULL)
	{
		line = 0;
		while (fdf->map.values[line] != NULL)
		{
			column = 0;
			while (fdf->map.values[line][column] != NULL)
			{
				free(fdf->map.values[line][column]);
				column++;
			}
			free(fdf->map.values[line]);
			line++;
		}
		free(fdf->map.values);
	}
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

