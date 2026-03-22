/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_brightness.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:47:37 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 21:35:55 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

/**
 * Safely fetches the light intensity from the pre-baked 2D lightmap.
 * Includes bounds checking: if a requested coordinate falls outside the mapped
 * light boundaries (or if lights are disabled), it defaults to ambient light.
 *
 * @param map  The map structure containing the light array and its limits.
 * @param x    The target X coordinate on the lightmap grid.
 * @param y    The target Y coordinate on the lightmap grid.
 * @return     The intensity float (0.0 to 1.0) at the requested cell.
 */

uint32_t	get_brightness(t_map *map, int x, int y)
{
	int	max_light_x;
	int	max_light_y;

	if (map->n_lights == 0)
		return (255);
	max_light_x = map->lightmap_limit[X];
	max_light_y = map->lightmap_limit[Y];
	if (x < 0 || y < 0 || x >= max_light_x || y >= max_light_y)
		return ((uint32_t)(AMBIENT_LIGHT * 255.0));
	return ((uint32_t)map->lightmap[y][x]);
}
