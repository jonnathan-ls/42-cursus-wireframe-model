/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/09 14:28:55 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Checks if a number is greater than the integer.
 *
 * This function checks if a number is greater than the integer.
 *
 * @param num The number to check.
 * @return true if the number is greater than the integer, false otherwise.
 */
static bool	is_greater_than_integer(t_num_str num)
{
	int		index;
	char	*str_to_compare;

	index = 0;
	if (num.has_signal)
		index++;
	if (num.is_negative)
		str_to_compare = INT_MIN_STR;
	else
		str_to_compare = INT_MAX_STR;
	while (num.value[index])
	{
		if (num.value[index] < str_to_compare[index])
			return (false);
		if (num.value[index] > str_to_compare[index])
			return (true);
		index++;
	}
	return (false);
}

/**
 * @brief Checks if a string is a valid integer.
 *
 * This function checks if a string is a valid integer.
 *
 * @param number_str The string to check.
 * @return true if the string is a valid integer, false otherwise.
 */
static bool	is_valid_integer(const char *number_str)
{
	int			index;
	t_num_str	num_str;

	index = 0;
	num_str.value = number_str;
	num_str.size = ft_strlen(number_str);
	num_str.is_negative = number_str[index] == '-';
	num_str.has_signal = (num_str.is_negative || (number_str[index] == '+'));
	if (num_str.size == 0 || (num_str.has_signal && num_str.size == 1))
		return (false);
	if (num_str.has_signal)
		index++;
	while (number_str[index] && number_str[index] != BREAK_LINE_CHAR)
	{
		if (!ft_isdigit(number_str[index]))
			return (false);
		index++;
	}
	if (num_str.is_negative)
		index--;
	if (index > INT_SIZE_DIGITS)
		return (false);
	if (index == INT_SIZE_DIGITS && is_greater_than_integer(num_str))
		return (false);
	return (true);
}

static char	*get_num_str(char *value_str)
{
	char			*comma_ptr;

	comma_ptr = ft_strchr(value_str, COMMA_CHAR);
	if (comma_ptr != NULL)
		return (ft_substr(value_str, 0, comma_ptr - value_str));
	else
		return (ft_strdup(value_str));
}

bool	validates_map_values(t_fdf *fdf)
{
	char			*num_str;
	char			*value_str;
	unsigned int	line;
	unsigned int	column;

	line = 0;
	while (fdf->map.values[line] != NULL)
	{
		column = 0;
		while (fdf->map.values[line][column] != NULL)
		{
			value_str = fdf->map.values[line][column];
			num_str = get_num_str(value_str);
			if (!is_valid_integer(num_str))
				return (free(num_str), false);
			free(num_str);
			column++;
		}
		line++;
	}
	return (true);
}
