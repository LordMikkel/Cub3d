/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_player_not_moving.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:12:12 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 17:42:23 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

/**
 * Evaluates whether the player is currently stationary and not actively using
 * the weapon. Used to activate the weapon's idle bobbing animation when the
 * player stops moving.
 *
 * @param player  The player structure containing movement flags.
 * @param gun     The weapon structure to check its current state.
 * @return        TRUE if the player is still and the gun is idle,
 *                FALSE otherwise.
 */
bool	is_player_not_moving(t_plyr *player, t_gun *gun)
{
	if ((gun->state == GUN_IDLE_A || gun->state == GUN_IDLE_E)
		&& !player->moving)
		return (TRUE);
	return (FALSE);
}
