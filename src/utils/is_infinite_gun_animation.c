/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_infinite_gun_animation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 23:38:39 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 18:46:22 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

/**
 * Determines if the current weapon state is meant to loop indefinitely.
 * Idle states and the active aiming hold state do not trigger a reset to a
 * different state once their frame counter maxes out; they repeat.
 *
 * @param gun  The weapon structure to check.
 * @return     TRUE if the state loops (IDLE_A, AIM),
 *             FALSE for one-shot states (SHOOT, RELOAD).
 */
bool	is_infinite_gun_animation(t_gun *gun)
{
	if (gun->state == GUN_IDLE_A || gun->state == GUN_IDLE_E
		|| gun->state == GUN_AIM)
		return (TRUE);
	return (FALSE);
}
