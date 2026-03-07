/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close_door.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:54:50 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/06 23:33:24 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Calculates the squared distance between the player and a door.
 * Applies an AABB optimization (Axis-Aligned Bounding Box) check first.
 * If the absolute distance on either the X or Y axis is strictly greater
 * than the interaction limit, it immediately aborts the calculation,
 * returning an "out of bounds" value.
 *
 * @param player        The player struct.
 * @param door          The door to check.
 * @param out_of_bound  The fallback value to return if the door is too far.
 * @return              The squared distance, or (out_of_bound + 1) if too far.
 */
static double	get_door_dist_sq(t_plyr *player, t_door *door, int out_of_bound)
{
	double	dx;
	double	dy;

	dx = player->pos[X] - door->pos[X];
	if (dx > DOOR_INTERACT_DIST || dx < -DOOR_INTERACT_DIST)
		return (out_of_bound + 1.0);
	dy = player->pos[Y] - door->pos[Y];
	if (dy > DOOR_INTERACT_DIST || dx < -DOOR_INTERACT_DIST)
		return (out_of_bound + 1.0);
	return ((dx * dx) + (dy * dy));
}

/**
 * Scans the map to find the closest interactable door to the player.
 * Iterates through all doors, calculating their squared distances,
 * and tracks the one with the minimum distance.
 *
 * @param data  Main program struct.
 * @param map   The map containing the doors array.
 * @return      A pointer to the nearest door, or NULL if none are in range.
 */
t_door	*get_nearest_door(t_data *data, t_map *map)
{
	t_door	*nearest;
	double	min_dist_sq;
	double	dist_sq;
	int		i;

	i = 0;
	nearest = NULL;
	min_dist_sq = data->vars.initial_min_dist_sq;
	while (i < map->n_doors)
	{
		dist_sq = get_door_dist_sq(&data->player, &map->doors[i], min_dist_sq);
		if (dist_sq <= min_dist_sq)
		{
			min_dist_sq = dist_sq;
			nearest = &map->doors[i];
		}
		i++;
	}
	return (nearest);
}

/**
 * Processes the player's interaction with the nearest door.
 * Uses a debounce mechanism (`key_held`) to prevent rapid-fire toggling.
 * Includes anti-clipping logic. If the player is currently standing inside
 * the door's map cell, it forces the door to stay open, preventing the player
 * from getting physically trapped inside a wall block.
 *
 * @param data      Main program struct.
 * @param map       The map containing the doors.
 * @param key_held  Pointer to the debounce boolean flag.
 */
void	open_close_door(t_data *data, t_map *map, bool *key_held)
{
	t_door	*door;

	if (*key_held)
		return ;
	door = get_nearest_door(data, map);
	if (!door)
		return ;
	if (is_player_inside_door(&data->player, door))
		door->needs_to_open = TRUE;
	else
		door->needs_to_open = !door->needs_to_open;
	*key_held = TRUE;
}
