/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_brightness.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:47:37 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/23 18:41:43 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

double	get_brightness(t_map *map, int x, int y)
{
	int	max_light_x;
	int	max_light_y;

	max_light_x = map->map_limit[X] * LIGHT_RESOLUTION;
	max_light_y = map->map_limit[Y] * LIGHT_RESOLUTION;
	if (x < 0 || y < 0 || x >= max_light_x || y >= max_light_y)
		return (AMBIENT_LIGHT);
	return (map->lightmap[y][x]);
}
