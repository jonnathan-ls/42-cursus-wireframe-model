/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:44:44 by jlacerda          #+#    #+#             */
/*   Updated: 2024/12/25 20:48:47 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_count_points(char ***data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (data[i])
	{
		j = 0;
		while (data[i][j])
		{
			count++;
			j++;
		}
		i++;
	}
	return (count);
}

static t_point	*create_point(int x, int y, int z, int color)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	point->color = color;
	return (point);
}

static void	free_points(t_point **points, int points_index)
{
	while (points_index-- > 0)
		free(points[points_index]);
	free(points);
}

static void	assign_points(t_point **points, char ***data, int *index)
{
	int	i;
	int	j;
	int	color;
	int	has_color;

	i = 0;
	j = 0;
	has_color = 0;
	while (data[i])
	{
		j = 0;
		while (data[i][j])
		{
			color = -1;
			has_color = ft_strchr(data[i][j], ',') != NULL;
			if (has_color)
				color = ft_strtol(ft_strchr(data[i][j], ',') + 1);
			points[*index] = create_point(i, j, ft_atoi(data[i][j]), color);
			if (!points[*index])
				return (free_points(points, *index));
			(*index)++;
			j++;
		}
		i++;
	}
}

t_point	**ft_set_points(char ***data)
{
	int		count;
	t_point	**points;
	int		points_index;

	count = ft_count_points(data);
	points = (t_point **)malloc(sizeof(t_point *) * (count + 1));
	if (!points)
		return (NULL);
	points_index = 0;
	assign_points(points, data, &points_index);
	points[points_index] = NULL;
	return (points);
}
