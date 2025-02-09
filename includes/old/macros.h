/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/08 20:22:55 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define ZERO_VALUE 0
# define FD_STDOUT 1
# define FD_STDERR 2

# define WIDTH 1920
# define HEIGHT 1080
# define WINDOW_TITLE "FdF"
# define WHITE 0xFFFFFF
# define DEFAULT_COLOR	WHITE
# define SPACE_CHAR ' '
# define COMMA_CHAR ','
# define EMPTY_STRING ""
# define BREAK_LINE_CHAR '\n'


#define ANGLE_ISO 0.5235988  // 30° em radianos
#define ZOOM 20
#define WIN_WIDTH 1000
#define WIN_HEIGHT 1000

# define SHIFT_FACTOR 100
# define ROTATE_FACTOR 0.3
# define ESC_KEY 65307
# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
#	define RIGHT_KEY 65363
# define PLUS_KEY 65451
# define MINUS_KEY 61
# define PLUS_KEY_1 65451
# define PLUS_KEY_2 61
# define MINUS_KEY_1 65453
# define MINUS_KEY_2 45


# define INVALID_ARGS_ERROR "Error: Invalid number of arguments\n"
# define INVALID_FILE_PATH_ERROR "Error: Invalid file path\n"
# define DATA_FILE_ERROR "Error reading data from the file\n"
# define INVALID_MAP_DIMENSIONS "Error: Invalid map dimensions\n"
# define MAP_EMPTY_ERROR "Error: Empty map\n"
# define FILE_NOT_FOUND_ERROR "File not found: %s\n"
# define INVALID_MAP_VALUES	"Error: Invalid map values\n"
# define FILE_DATA_ERROR	"Error reading data from the file to create \
points and their respective coordinates\n"
# define WINDOW_CREATION_ERROR	"Window creation error\n"
# define MLX_INIT_ERROR	"Mlx initialization error\n"

# define INT_SIZE_DIGITS	10
# define	INT_MAX_STR	"2147483647"
# define	INT_MIN_STR	"-2147483648"
# define FILE_OPEN_ERROR	"Error opening file\n"

#endif
