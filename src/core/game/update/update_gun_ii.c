/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_gun_ii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 23:43:07 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 17:24:16 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * Forces the weapon into the final frame of the aiming animation.
 * Used to keep the weapon aimed down sights (ADS) immediately after firing,
 * provided there is still ammunition. If the magazine is empty, it drops
 * the weapon to the empty idle state instead.
 *
 * @param gun  The gun structure to modify.
 */
void	set_last_aim_frame(t_gun *gun)
{
	if (gun->ammo)
	{
		gun->state = GUN_AIM;
		gun->current_frame = TOTAL_GUN_AIM_FRAMES - 1;
	}
	else
		gun->state = GUN_IDLE_E;
}

/**
 * Retrieves the total number of frames for the weapon's current state.
 * Maps the active animation state (idle, aim, shoot, reload, melee) to
 * its corresponding predefined frame count constant.
 *
 * @param data  Main program struct, used for safe error exiting.
 * @param gun   The gun structure whose state is being evaluated.
 * @return      The total frame count for the current animation.
 */
int	get_max_frames(t_data *data, t_gun *gun)
{
	if (gun->state == GUN_IDLE_A)
		return (TOTAL_GUN_IDLE_FRAMES);
	if (gun->state == GUN_IDLE_E)
		return (TOTAL_GUN_IDLE_FRAMES);
	if (gun->state == GUN_AIM)
		return (TOTAL_GUN_AIM_FRAMES);
	if (gun->state == GUN_UNAIM)
		return (TOTAL_GUN_UNAIM_FRAMES);
	if (gun->state == GUN_SHOOT)
		return (TOTAL_GUN_SHOOT_FRAMES);
	if (gun->state == GUN_MELEE)
		return (TOTAL_GUN_MELEE_FRAMES);
	if (gun->state == GUN_RELOAD)
		return (TOTAL_GUN_RELOAD_FRAMES);
	return (exit_error(data, ERR_GUN_STATE, EXIT_FAIL), ERROR);
}

/**
 * Determines the display duration for a single frame of the current state.
 * Different weapon actions require different playback speeds (e.g., a fast
 * muzzle flash during GUN_SHOOT vs a slow, deliberate GUN_RELOAD). Maps
 * the active state to its specific timing constant.
 *
 * @param gun  The gun structure whose state is being evaluated.
 * @return     The duration (in time units) a frame should stay on screen.
 */
double	get_frame_duration(t_gun *gun)
{
	if (gun->state == GUN_IDLE_A)
		return (FRAME_GUN_IDLE_DURATION);
	if (gun->state == GUN_IDLE_E)
		return (FRAME_GUN_IDLE_DURATION);
	if (gun->state == GUN_AIM)
		return (FRAME_GUN_AIM_DURATION);
	if (gun->state == GUN_UNAIM)
		return (FRAME_GUN_UNAIM_DURATION);
	if (gun->state == GUN_SHOOT)
		return (FRAME_GUN_SHOOT_DURATION);
	if (gun->state == GUN_MELEE)
		return (FRAME_GUN_MELEE_DURATION);
	if (gun->state == GUN_RELOAD)
		return (FRAME_GUN_RELOAD_DURATION);
	return (FRAME_GUN_SHOOT_DURATION);
}
