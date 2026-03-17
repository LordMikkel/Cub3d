/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_gun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 20:16:03 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/17 20:21:57 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

static t_txtr	*get_shoot_frame(t_gun *gun)
{
	if (gun->current_frame <= SHOT_FRAMES)
		return (&gun->shoot_frames[gun->current_frame]);
	if (gun->last_hit == HIT_DAMAGE)
		return (&gun->shoot_frames[HIT_DAMAGE_FRAME]);
	return (&gun->shoot_frames[HIT_NONE_FRAME]);
}

static t_txtr	*get_melee_frame(t_gun *gun)
{
	if (gun->current_frame <= SHOT_FRAMES)
		return (&gun->melee_frames[gun->current_frame]);
	if (gun->last_hit == HIT_DAMAGE)
		return (&gun->melee_frames[HIT_DAMAGE_FRAME]);
	return (&gun->melee_frames[HIT_NONE_FRAME]);
}

static t_txtr	*select_frame(t_gun *gun)
{
	if (gun->state == GUN_IDLE_A)
		return (&gun->idle_frames[gun->current_frame]);
	if (gun->state == GUN_IDLE_E)
		return (&gun->idle_frames[gun->current_frame]);
	if (gun->state == GUN_AIM || gun->state == GUN_UNAIM)
		return (&gun->aim_frames[gun->current_frame]);
	if (gun->state == GUN_SHOOT)
		return (get_shoot_frame(gun));
	if (gun->state == GUN_MELEE)
		return (get_melee_frame(gun));
	if (gun->state == GUN_RELOAD)
		return (&gun->reload_frames[gun->current_frame]);
	return (&gun->idle_frames[0]);
}

void	render_gun(t_data *data, t_gun *gun)
{
	t_txtr	*frame;

	frame = select_frame(gun);
	if (!frame || !frame->txtr)
		return ;
	draw_gun(data, frame->txtr);
}
