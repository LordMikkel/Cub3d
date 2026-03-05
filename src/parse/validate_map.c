/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 22:06:09 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/02 18:41:03 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/**
 * Calculates the map dimensions.
 * We store the maximum X and Y coordinates to define the valid bounds
 * of the grid. This allows us to perform safe boundary checks later
 * without recalculating lengths repeatedly.
 *
 * @param map  The map struct to update.
 */
static void	get_limits_map(t_map *map)
{
	map->map_limit[X] = map->map_max_len - 1;
	map->map_limit[Y] = (int)ft_arraylen(map->map_grid) - 1;
}

/**
 * Scans the grid to register game entities.
 * It iterates through every cell to locate the player, enemies, and doors.
 * This step transforms raw map characters into playable game objects
 * and initializes their specific data (position, direction, state).
 *
 * @param data  The main struct.
 * @param map   The map struct containing the grid.
 */
static void	get_elements(t_data *data, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map_grid[y])
	{
		x = 0;
		while (map->map_grid[y][x])
		{
			if (is_player(map->map_grid[y][x]))
				init_player(data, x, y, map->map_grid[y][x]);
			else if (is_enemy(map->map_grid[y][x]))
				init_enemy(data, x, y, map->map_grid[y][x]);
			else if (is_light(map->map_grid[y][x]))
				init_light(data, x, y, map->map_grid[y][x]);
			else if (is_door(map->map_grid[y][x]))
			{
				if (!is_valid_door(map, x, y))
					exit_error(data, ERR_MAP_DOOR, EXIT_USE);
				init_door(data, x, y, map->map_grid[y][x]);
			}
			x++;
		}
		y++;
	}
}

/**
 * Recursive Flood Fill algorithm.
 * It traverses the map starting from the player to verify two things:
 * 1. Closure: If the flood reaches a space (' ') or the array bounds,
 * the map is not closed by walls (it has a "leak").
 * 2. Reachability: It counts how many enemies are reachable by the player.
 * We mark visited cells with 'V' to prevent infinite recursion loops.
 *
 * @param data  Main struct for error exits.
 * @param map   A COPY of the map grid to modify safely.
 * @param max   The map dimensions.
 * @param pos   Current position in the recursion.
 * @param n     Pointer to count reachable enemies.
 */
static void	close_bounds(t_data *data, char **map, t_p2d max, t_p2d pos, int *n)
{
	if (pos.x < 0 || pos.y < 0 || pos.x > max.x || pos.y > max.y)
		exit_error(data, ERR_MAP_WALLS, EXIT_USE);
	if (map[pos.y][pos.x] == ' ')
		exit_error(data, ERR_MAP_WALLS, EXIT_USE);
	if (map[pos.y][pos.x] == '1' || map[pos.y][pos.x] == 'V')
		return ;
	if (is_enemy(map[pos.y][pos.x]))
		(*n)++;
	map[pos.y][pos.x] = 'V';
	close_bounds(data, map, max, (t_p2d){pos.x + 1, pos.y}, n);
	close_bounds(data, map, max, (t_p2d){pos.x - 1, pos.y}, n);
	close_bounds(data, map, max, (t_p2d){pos.x, pos.y + 1}, n);
	close_bounds(data, map, max, (t_p2d){pos.x, pos.y - 1}, n);
}

/**
 * Final map verification logic.
 * Performs high-level checks (player count) and runs the Flood Fill algorithm.
 * Crucially, we work on a COPY of the map grid. This allows us to "paint"
 * the path with 'V' characters to check for leaks without corrupting the
 * actual game map that will be used for rendering and for debuging purpose.
 *
 * @param data  The main struct.
 * @param map   The map struct to validate.
 */
void	validate_map(t_data *data, t_map *map)
{
	t_p2d	start;
	t_p2d	limits;
	int		reachable_enemies;

	if (map->n_players != 1)
		exit_error(data, ERR_MAP_PLAYER, EXIT_USE);
	if (map->n_enemies > MAX_ENEMIES)
		exit_error(data, ERR_MAP_PLAYER, EXIT_USE);
	get_limits_map(map);
	get_elements(data, map);
	reachable_enemies = 0;
	map->map_copy = ft_arraydup(map->map_grid);
	if (!map->map_copy)
		exit_error(data, ERR_MALLOC, EXIT_FAILURE);
	start = (t_p2d){data->player.pos[X], data->player.pos[Y]};
	limits = (t_p2d){map->map_limit[X], map->map_limit[Y]};
	close_bounds(data, map->map_copy, limits, start, &reachable_enemies);
	// dbg_print_map_grid(map->map_copy, STDOUT);
	if (reachable_enemies != map->n_enemies)
		exit_error(data, ERR_MAP_REACHABLE, EXIT_USE);
}
