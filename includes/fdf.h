/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2024/12/25 20:56:35 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>

# define EMPTY_STRING ""
# define SPACE_CHAR ' '
# define BREAK_LINE_CHAR '\n'

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

char	***ft_get_data(char *file);
t_point	**ft_set_points(char ***data);

#endif
