/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2024/12/29 20:11:41 by jlacerda         ###   ########.fr       */
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
# define DEFAULT_COLOR	0xFFFFFF

# define SPACE_CHAR ' '
# define EMPTY_STRING ""
# define BREAK_LINE_CHAR '\n'

# define FILE_PATH_NOT_PROVIDED_ERROR "File path not provided\n"
# define FILE_ARGC_EXPECTED "The correct format is: ./fdf <path/file>\n"

# define FILE_NOT_FOUND_ERROR "File not found: %s\n"

# define FILE_DATA_ERROR	"Error reading data from the file to create \
points and their respective coordinates\n"
# define WINDOW_CREATION_ERROR	"Window creation error\n"
# define MLX_INIT_ERROR	"Mlx initialization error\n"

#endif
