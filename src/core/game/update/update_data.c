/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 00:32:56 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/06 23:33:24 by migarrid         ###   ########.fr       */
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
static void	update_doors(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->n_doors)
	{
		update_single_door(map, &map->doors[i]);
		i++;
	}
}

/**
 * Updates the player's dynamic camera variables.
 * Combines the vertical camera tilt with the walking head bounce offset
 * to calculate the final vertical pixel shift for the rendering horizon.
 *
 * @param player  The player struct.
 */
static void	update_player(t_plyr *player)
{
	player->head[POS] = player->head[TILT] + player->head[BOUNCE];
}

void	update_data(t_data *data)
{
	update_player(&data->player);
	update_doors(&data->map);
}
