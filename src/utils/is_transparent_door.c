/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_transparent_door.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:06:33 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/17 20:23:49 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

/**
 * Validates if a specific [X, Y] grid coordinate is safely inside the map.
 * Used to prevent reading out of bounds before checking cell contents.
 *
 * @param map   The map structure with defined limits.
 * @param cell  The [X, Y] coordinate array to evaluate.
 * @return      TRUE if inside the map array, FALSE otherwise.
 */
bool	is_transparent_door(t_map *map, t_ray *ray)
{
	if (!is_inside_map_cells(map, ray->pos))
		return (FALSE);
	if (!is_door(map->map_grid[ray->pos[Y]][ray->pos[X]]))
		return (FALSE);
	return (TRUE);
}
