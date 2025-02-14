/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/14 02:07:53 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define DOT_CHAR '.'
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
# define MAP_MIDDLE 2
# define DEFAULT_ROTATION_ANGLE -90

# define ESC	65307
# define INT_SIZE_DIGITS	10
# define ZOOM_IN	105
# define ZOOM_OUT	111
# define OFFSET_LEFT	65361
# define OFFSET_RIGHT	65363
# define OFFSET_UP	65362
# define OFFSET_DOWN	65364
# define ROTATE_LEFT	97
# define ROTATE_RIGHT	100
# define ROTATE_UP	119
# define ROTATE_DOWN	115
# define TRANSLATE_X	44
# define TRANSLATE_Y	46
# define INCREASE_Z_SCALE	122
# define DECREASE_Z_SCALE	120

// # define KEY_TRANSLATE_LEFT	115
// # define KEY_TRANSLATE_RIGHT	119
// # define KEY_RANDOM_COLOR	99

# define INT_MAX_STR	"2147483647"
# define INT_MIN_STR	"-2147483648"
# define MAP_EMPTY_ERROR "Empty map"
# define INVALID_MAP_VALUES	"Invalid map values"
# define MLX_INIT_ERROR	"Mlx initialization error"
# define IMAGE_CREATION_ERROR	"Image creation error"
# define WINDOW_CREATION_ERROR	"Window creation error"
# define INVALID_ARGS_ERROR "Invalid number of arguments"
# define FILE_OPEN_ERROR "Error while opening file"
# define MAP_DATA_ERROR "Error while configuring map values"
# define INVALID_FILE_EXTENSION	"Invalid file extension"

#endif
