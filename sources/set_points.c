/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:44:44 by jlacerda          #+#    #+#             */
/*   Updated: 2024/12/29 19:59:35 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point *create_point(int x, int y, int z, int color) {
    t_point *point;

    point = (t_point *)malloc(sizeof(t_point));
    if (!point)
        return (NULL);
    point->x = x;
    point->y = y;
    point->z = z;
    point->color = color;
    return (point);
}

static void free_points(t_point **points, int points_index) {
    while (points_index-- > 0)
        free(points[points_index]);
    free(points);
}

static void assign_point(t_config *config, char *data, int i, int j) {
    int color = DEFAULT_COLOR;
    int has_color = ft_strchr(data, ',') != NULL;
    if (has_color)
        color = ft_strtol(ft_strchr(data, ',') + 1);
    config->points[config->draw_params.delta_x] = create_point(i, j, ft_atoi(data), color);
    if (!config->points[config->draw_params.delta_x])
        return (free_points(config->points, config->draw_params.delta_x));
    config->draw_params.delta_x++;
}

static void assign_points(t_config *config, char ***data) {
    int i = 0;
    int j = 0;

    while (data[i]) {
        j = 0;
        while (data[i][j]) {
            assign_point(config, data[i][j], i, j);
            j++;
        }
        i++;
    }
    config->width = j;
    config->height = i;
}

void set_points(t_config *config, char ***data) {
    int num_points = 0;
    int i = 0;

    while (data[i]) {
        int j = 0;
        while (data[i][j]) {
            num_points++;
            j++;
        }
        i++;
    }

    config->points = (t_point **)malloc(sizeof(t_point *) * num_points);
    if (!config->points) {
        perror("Failed to allocate memory for points");
        return;
    }

    config->draw_params.delta_x = 0;
    assign_points(config, data);
}