/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:01:36 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 17:26:15 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * Handles passive health regeneration for the player.
 * Uses the frame delta time to calculate a cooldown, ensuring the healing rate
 * is independent of the framerate. If the player is alive and below maximum
 * capacity, it incrementally restores health up to the initial limit.
 *
 * @param data    Main program struct, used to access the delta time.
 * @param player  The player structure being updated.
 */
static void	regenerative_health(t_data *data, t_plyr *player)
{
	if (player->health < INIT_PLAYER_HEALTH && !player->is_dead)
	{
		player->heal_cooldown += data->mlx->delta_time;
		if (player->heal_cooldown >= PASSIVE_HEAL_TIME)
		{
			player->health += PASSIVE_HEAL_AMOUNT;
			if (player->health > INIT_PLAYER_HEALTH)
				player->health = INIT_PLAYER_HEALTH;
			player->heal_cooldown = 0.0;
		}
	}
}

/**
 * Updates the player's dynamic camera variables.
 * Combines the vertical camera tilt with the walking head bounce offset
 * to calculate the final vertical pixel shift for the rendering horizon.
 *
 * @param player  The player struct.
 */
void	update_player(t_data *data, t_plyr *player)
{
	player->head[POS] = player->head[TILT]
		+ player->head[BOUNCE]
		+ player->jump_offset;
	regenerative_health(data, player);
}
