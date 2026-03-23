/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aim_gun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 19:20:33 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/23 02:33:47 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../../inc/cube.h"

/**
 * Initiates the Aim Down Sights transition.
 * If the gun is currently in its standard idle state, it switches the
 * state machine to GUN_AIM, resets the animation frame to 0, and captures
 * the current time to ensure proper animation pacing.
 *
 * @param gun  The weapon structure being aimed.
 */
void	aim_gun(t_gun *gun)
{
	if (gun->state == GUN_IDLE_A)
	{
		gun->state = GUN_AIM;
		gun->current_frame = 0;
		gun->frame_timer = mlx_get_time();
	}
}

/**
 * Triggers a rollback animation to return the gun from Aim Down Sights to idle.
 * Changes the state to GUN_UNAIM and flags the animation as incomplete,
 * allowing the frame advancement logic to play the aiming animation in reverse.
 *
 * @param gun  The weapon structure to unaim.
 */
void	unaim_gun(t_gun *gun)
{
	if (gun->state == GUN_AIM)
	{
		gun->state = GUN_UNAIM;
		gun->anim_done = FALSE;
	}
}
