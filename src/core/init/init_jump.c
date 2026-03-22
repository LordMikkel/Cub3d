/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_jump.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 21:49:28 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 17:53:04 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Triggers the player's jumping physics.
 * Sets the jumping flag to TRUE and applies an initial upward velocity
 * (JUMP_FORCE). The main physics loop will subsequently handle the gravity
 * application and vertical displacement.
 *
 * @param player  The player structure to modify.
 */
void	init_jump(t_plyr *player)
{
	player->jumping = TRUE;
	player->jump_vel = JUMP_FORCE;
}
