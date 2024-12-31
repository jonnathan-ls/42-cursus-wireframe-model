/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2024/12/31 17:33:10 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void swap_points(t_draw_params *params) {
    t_point tmp;

    tmp = params->initialPoint;
    params->initialPoint = params->finalPoint;
    params->finalPoint = tmp;
}

void calculate_slope(t_draw_params *params) {
    params->delta_x = params->finalPoint.x - params->initialPoint.x;
    params->delta_y = params->finalPoint.y - params->initialPoint.y;
    if (params->delta_x != 0)
        params->slope = (float)params->delta_y / (float)params->delta_x;
    else
        params->slope = 1;
}

int interpolate_color(int color1, int color2, float factor) {
    int red = ((color1 >> 16) & 0xFF) + factor * (((color2 >> 16) & 0xFF) - ((color1 >> 16) & 0xFF));
    int green = ((color1 >> 8) & 0xFF) + factor * (((color2 >> 8) & 0xFF) - ((color1 >> 8) & 0xFF));
    int blue = (color1 & 0xFF) + factor * ((color2 & 0xFF) - (color1 & 0xFF));
    return (red << 16) | (green << 8) | blue;
}

void draw_endpoint(t_draw_params *params, int x, int y, int is_vertical) {
    float overlap = 1 - ((x + 0.5) - (int)(x + 0.5));
    float dist = y - (int)(y);
    int color = interpolate_color(params->initialPoint.color, params->finalPoint.color, (float)(x - params->initialPoint.x) / params->delta_x);
    if (is_vertical) {
        custom_mlx_pixel_put(params->img, x, (y + 0.5), color * overlap * (1 - dist));
        custom_mlx_pixel_put(params->img, x + 1, (y + 0.5), color * overlap * dist);
    } else {
        custom_mlx_pixel_put(params->img, (x + 0.5), y, color * overlap * (1 - dist));
        custom_mlx_pixel_put(params->img, (x + 0.5), y + 1, color * overlap * dist);
    }
}

void draw_line_segment(t_draw_params *params, int is_vertical) {
    int i = 1;
    int range = round((is_vertical ? params->delta_y : params->delta_x) + 0.5);
    while (i < range) {
        float x = params->initialPoint.x + (is_vertical ? i * params->slope : i);
        float y = params->initialPoint.y + (is_vertical ? i : i * params->slope);
        int ix = floor(x);
        int iy = floor(y);
        float distance = is_vertical ? x - ix : y - iy;
        int color = interpolate_color(params->initialPoint.color, params->finalPoint.color, (float)(ix - params->initialPoint.x) / params->delta_x);
        custom_mlx_pixel_put(params->img, ix, iy, color * (1 - distance));
        custom_mlx_pixel_put(params->img, is_vertical ? ix + 1 : ix, is_vertical ? iy : iy + 1, color * distance);
        i++;
    }
}

void draw_line(t_draw_params *params) {
    int is_vertical = abs(params->finalPoint.y - params->initialPoint.y) >= abs(params->finalPoint.x - params->initialPoint.x);
    if (is_vertical) {
        if (params->finalPoint.y < params->initialPoint.y)
            swap_points(params);
        calculate_slope(params);
        draw_endpoint(params, params->initialPoint.x, params->initialPoint.y, is_vertical);
        draw_endpoint(params, params->finalPoint.x, params->finalPoint.y, is_vertical);
        draw_line_segment(params, is_vertical);
    } else {
        if (params->finalPoint.x < params->initialPoint.x)
            swap_points(params);
        calculate_slope(params);
        draw_endpoint(params, params->initialPoint.x, params->initialPoint.y, is_vertical);
        draw_endpoint(params, params->finalPoint.x, params->finalPoint.y, is_vertical);
        draw_line_segment(params, is_vertical);
    }
}