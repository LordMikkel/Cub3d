/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_inside_map_cells.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:56:34 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 17:43:42 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

/**
 * Validates whether a specific grid coordinate is safely within the map bounds.
 * Prevents array out-of-bounds errors (Segfaults) when checking neighboring
 * cells or casting rays near the edges of the parsed map grid.
 *
 * @param map   The map structure containing the strict X/Y limits.
 * @param cell  An array of 2 integers [X, Y] representing the grid cell.
 * @return      TRUE if the cell is inside the map, FALSE if out of bounds.
 */
bool	is_inside_map_cells(t_map *map, int *cell)
{
	if (cell[X] >= 0 && cell[X] < map->map_limit[X] + 1
		&& cell[Y] >= 0 && cell[Y] < map->map_limit[Y] + 1)
		return (TRUE);
	return (FALSE);
}
