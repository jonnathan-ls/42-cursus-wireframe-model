/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/05 21:18:21 by jlacerda         ###   ########.fr       */
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

# define SHIFT_FACTOR 150
# define ROTATE_FACTOR 1
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


# define FILE_PATH_NOT_PROVIDED_ERROR "File path not provided\n"
# define FILE_ARGC_EXPECTED "The correct format is: ./fdf <path/file>\n"

# define FILE_NOT_FOUND_ERROR "File not found: %s\n"

# define FILE_DATA_ERROR	"Error reading data from the file to create \
points and their respective coordinates\n"
# define WINDOW_CREATION_ERROR	"Window creation error\n"
# define MLX_INIT_ERROR	"Mlx initialization error\n"

#endif
