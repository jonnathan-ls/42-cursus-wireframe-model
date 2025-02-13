/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:26:55 by jlacerda          #+#    #+#             */
/*   Updated: 2025/02/12 21:56:15 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	on_key_press(int keycode, t_fdf	*fdf)
{
	printf("Key pressed: %d\n", keycode);
	if (fdf != NULL)
	{
		if (keycode == ESC_KEY)
		{
			free_mallocs(fdf);
			exit(EXIT_SUCCESS);
		}
	}
	return (0);
}
