/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:01:49 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/08 00:07:14 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * Updates the physical and logical state of a single door per frame.
 * 1. Animation: Modifies the `open_percent` (0.0 to 1.0) by animation speed.
 * 2. Clamping: Ensures the percentage never overflows bounds.
 * 3. Logic: Once fully open (1.0), it updates the map grid to 'O' so the
 * Raycaster treats it as empty space. Otherwise, it remains 'D' (obstacle).
 *
 * @param map   The map struct for grid manipulation.
 * @param door  The specific door to update.
 */
static void	update_single_door(t_map *map, t_door *door)
{
	if (door->needs_to_open)
		door->open_percent += DOOR_ANIM_SPEED;
	else
		door->open_percent -= DOOR_ANIM_SPEED;
	if (door->open_percent > 1.0)
		door->open_percent = 1.0;
	if (door->open_percent < 0.0)
		door->open_percent = 0.0;
	if (door->open_percent >= 1.0)
		map->map_grid[(int)door->pos[Y]][(int)door->pos[X]] = 'O';
	else
		map->map_grid[(int)door->pos[Y]][(int)door->pos[X]] = 'D';
}

/**
 * Orchestrates the state updates for all door entities in the map.
 * Executed every single frame during the engine's logic phase. This guarantees
 * that door animations (opening or closing) progress continuously in the
 * background, maintaining a persistent game world even if the doors are
 * currently outside the player's field of view.
 *
 * @param map  The map structure containing the array of doors.
 */
void	update_doors(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->n_doors)
	{
		update_single_door(map, &map->doors[i]);
		i++;
	}
}
