/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_transparent_door.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:06:33 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/06 21:25:39 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Retrieves the specific opening state of a door hit by the ray.
 * Iterates through the active doors array to find a match with the current
 * ray coordinates and returns how open it is from 0.0 closed to 1.0 fully open.
 *
 * @param map  The map containing the dynamic door entities.
 * @param ray  The ray containing the impact coordinates.
 * @return     A double representing the open percentage.
 */
static double	get_door_open_percent(t_map *map, t_ray *ray)
{
	int	i;

	i = 0;
	while (i < map->n_doors)
	{
		if (is_ray_door(&map->doors[i], ray))
			return (map->doors[i].open_percent);
		i++;
	}
	return (0.0);
}

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
	return (get_door_open_percent(map, ray) > 0.0);
}
