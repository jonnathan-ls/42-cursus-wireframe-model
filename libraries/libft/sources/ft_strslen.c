/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strslen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:52:42 by jlacerda          #+#    #+#             */
/*   Updated: 2025/01/25 19:59:58 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strslen(char **strs)
{
	int	index;

	index = 0;
	if (!strs)
		return (0);
	if (!strs[index])
		return (0);
	while (strs[index])
		index++;
	return (index);
}
