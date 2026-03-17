/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_door.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 23:59:42 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/16 23:31:52 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

/**
 * Verifies coordinates are within the grid bounds.
 * Prevents segmentation faults by ensuring X and Y are valid indices.
 *
 * @param map  The map struct with dimensions.
 * @param x    X coordinate.
 * @param y    Y coordinate.
 */
static bool	is_inside_limits(t_map *map, int x, int y)
{
	if (x < map->map_limit[X] && y < map->map_limit[Y])
		return (TRUE);
	return (FALSE);
}

/**
 * Enforces structural rules for door placement.
 * A door requires a "corridor" setup to be functional:
 * It must have walls on one axis (frame) and open space on the other (path).
 *
 * @param map_grid  The 2D map array.
 * @param x         X coordinate of the door.
 * @param y         Y coordinate of the door.
 * @return          TRUE if the geometry is valid.
 */
static bool	is_between_walls_and_can_open_door(char **map_grid, int x, int y)
{
	bool	walls_x;
	bool	walls_y;
	bool	open_x;
	bool	open_y;

	walls_x = (map_grid[y][x - 1] == '1' && map_grid[y][x + 1] == '1');
	walls_y = (map_grid[y - 1][x] == '1' && map_grid[y + 1][x] == '1');
	open_x = (map_grid[y][x - 1] == '0' && map_grid[y][x + 1] == '0');
	open_y = (map_grid[y - 1][x] == '0' && map_grid[y + 1][x] == '0');
	if (walls_x && open_y)
		return (TRUE);
	if (walls_y && open_x)
		return (TRUE);
	return (FALSE);
}

/**
 * Validates a door entity.
 * Checks both boundary limits and the corridor geometry requirement.
 *
 * @param map  The map struct.
 * @param x    X coordinate.
 * @param y    Y coordinate.
 * @return     TRUE if the door is valid.
 */
bool	is_valid_door(t_map *map, int x, int y)
{
	if (!is_inside_limits(map, x, y))
		return (FALSE);
	if (!is_between_walls_and_can_open_door(map->map_grid, x, y))
		return (FALSE);
	return (TRUE);
}
