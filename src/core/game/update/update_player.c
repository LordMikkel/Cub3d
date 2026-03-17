/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:01:36 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/17 20:22:27 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * Updates the player's dynamic camera variables.
 * Combines the vertical camera tilt with the walking head bounce offset
 * to calculate the final vertical pixel shift for the rendering horizon.
 *
 * @param player  The player struct.
 */
void	update_player(t_plyr *player)
{
	player->head[POS] = player->head[TILT]
		+ player->head[BOUNCE]
		+ player->jump_offset;
}
