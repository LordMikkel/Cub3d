/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_gun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 19:21:13 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/20 02:06:48 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

void	check_reload_gun_finish(t_gun *gun)
{
	if (gun->prev_state == GUN_RELOAD && gun->anim_done)
	{
		gun->ammo++;
		gun->ammo += gun->picked_ammo;
		if (gun->ammo >= gun->max_ammo)
			gun->ammo = gun->max_ammo;
		gun->anim_done = FALSE;
	}
}

static bool	is_possible_to_reload(t_gun *gun)
{
	if (gun->state != GUN_IDLE_E)
		return (FALSE);
	if (gun->ammo >= gun->max_ammo)
		return (FALSE);
	if (gun->picked_ammo < 0)
		return (FALSE);
	return (TRUE);
}

void	reload_gun(t_gun *gun)
{
	if (is_possible_to_reload(gun))
	{
		gun->state = GUN_RELOAD;
		gun->current_frame = 0;
		gun->frame_timer = 0.0;
	}
}
