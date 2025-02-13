/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/13 03:25:25 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define SPACE_CHAR ' '
# define COMMA_CHAR ','
# define NULL_CHAR '\0'
# define EMPTY_STRING ""
# define WHITE 0xFFFFFF
# define ORANGE 0xFFA500
# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 720
# define WINDOW_TITLE "FdF"
# define DEFAULT_COLOR	WHITE
# define BREAK_LINE_CHAR '\n'

# define ESC_KEY	65307
# define INT_SIZE_DIGITS	10
# define KEY_ZOOM_IN	105
# define KEY_ZOOM_OUT	111
# define KEY_TRANSLATE_LEFT	115
# define KEY_TRANSLATE_RIGHT	119
# define KEY_ROTATE_LEFT	97
# define KEY_ROTATE_UP	65362
# define KEY_ROTATE_DOWN	65364
# define KEY_ROTATE_RIGHT	100
# define KEY_RANDOM_COLOR	99
# define KEY_INCREASE_Z_SCALE	122
# define KEY_DECREASE_Z_SCALE	120

# define INT_MAX_STR	"2147483647"
# define INT_MIN_STR	"-2147483648"
# define MAP_EMPTY_ERROR "Empty map"
# define INVALID_MAP_VALUES	"Invalid map values"
# define MLX_INIT_ERROR	"Mlx initialization error"
# define IMAGE_CREATION_ERROR	"Image creation error"
# define WINDOW_CREATION_ERROR	"Window creation error"
# define INVALID_ARGS_ERROR "Invalid number of arguments"
# define DATA_FILE_ERROR "Error reading data from the file"
# define MAP_DATA_ERROR "Error while configuring map values"

#endif
