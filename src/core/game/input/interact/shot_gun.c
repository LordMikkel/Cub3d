/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shot_gun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 19:28:51 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/19 21:14:59 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

static void	shoot_ammo(t_data *data, t_gun *gun)
{
	gun->ammo--;
	gun->state = GUN_SHOOT;
	gun->current_frame = 0;
	gun->frame_timer = 0.0;
	gun_apply_hit(data, gun, gun->shoot_damage, MAX_DISTANCE_SHOT);
}

static void	shoot_melee(t_data *data, t_gun *gun)
{
	gun->state = GUN_MELEE;
	gun->current_frame = 0;
	gun->frame_timer = 0.0;
	gun_apply_hit(data, gun, gun->melee_damage, MAX_DISTANCE_MELEE);
}

static bool	is_already_doing_a_damage_gun_action(t_gun *gun)
{
	if (gun->state == GUN_SHOOT || gun->state == GUN_MELEE)
		return (TRUE);
	return (FALSE);
}

static bool	is_gun_charged_but_not_aiming(t_gun *gun)
{
	if ((gun->state != GUN_AIM || !is_last_aim_frame(gun)) && gun->ammo)
		return (TRUE);
	return (FALSE);
}

void	shot_gun(t_data *data, t_gun *gun)
{
	if (is_gun_charged_but_not_aiming(gun))
		return ;
	if (is_already_doing_a_damage_gun_action(gun))
		return ;
	if (gun->ammo > 0)
		shoot_ammo(data, gun);
	else
		shoot_melee(data, gun);
}
