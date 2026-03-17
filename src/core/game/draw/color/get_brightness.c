/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_brightness.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:47:37 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/17 19:59:09 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

double	get_brightness(t_map *map, int x, int y)
{
	int	max_light_x;
	int	max_light_y;

	if (map->n_lights == 0)
		return (1.0);
	max_light_x = map->lightmap_limit[X];
	max_light_y = map->lightmap_limit[Y];
	if (x < 0 || y < 0 || x >= max_light_x || y >= max_light_y)
		return (AMBIENT_LIGHT);
	return (map->lightmap[y][x]);
}
