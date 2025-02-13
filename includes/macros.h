/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/12 22:07:44 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define WINDOW_TITLE "FdF"
# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 800
# define WHITE 0xFFFFFF
# define DEFAULT_COLOR	WHITE
# define SPACE_CHAR ' '
# define COMMA_CHAR ','
# define EMPTY_STRING ""
# define NULL_CHAR '\0'
# define BREAK_LINE_CHAR '\n'

# define ESC_KEY	65307

# define INT_SIZE_DIGITS	10
# define INT_MAX_STR	"2147483647"
# define INT_MIN_STR	"-2147483648"

# define MLX_INIT_ERROR	"Mlx initialization error"
# define WINDOW_CREATION_ERROR	"Window creation error"
# define IMAGE_CREATION_ERROR	"Image creation error"

# define MAP_EMPTY_ERROR "Empty map"
# define FILE_OPEN_ERROR	"Error opening file"
# define INVALID_MAP_VALUES	"Invalid map values"
# define FILE_NOT_FOUND_ERROR "File not found: %s"
# define INVALID_FILE_PATH_ERROR "Invalid file path"
# define INVALID_MAP_DIMENSIONS "Invalid map dimensions"
# define INVALID_ARGS_ERROR "Invalid number of arguments"
# define MAP_DATA_ERROR "Error while configuring map values"
# define DATA_FILE_ERROR "Error reading data from the file"



#endif
