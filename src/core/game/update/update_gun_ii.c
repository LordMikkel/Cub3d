/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_gun_ii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 23:43:07 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/18 22:27:51 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

void set_last_aim_frame(t_gun *gun)
{
	if (gun->ammo)
	{
		gun->state = GUN_AIM;
		gun->current_frame = TOTAL_GUN_AIM_FRAMES - 1;
	}
	else
		gun->state = GUN_IDLE_E;
}

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
	return (exit_error(data, ERR_GUN_INVAL_STATE, EXIT_FAIL), ERROR);
}

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
