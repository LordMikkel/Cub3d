/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 04:27:57 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/28 04:36:47 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	init_textures(t_map *map)
{
	int	i;

	i = 0;
	while (i < TOTAL_TEXTURE)
	{
		map->textures[i].format = COLOR;
		if (i == CEILING || i == FLOOR)
			map->textures[i].hex_color = DEFAULT_COLOR_CF;
		else
			map->textures[i].hex_color = DEFAULT_COLOR_WALL;
		i++;
	}
}
