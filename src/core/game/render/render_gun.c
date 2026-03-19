/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_gun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 20:16:03 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/19 20:55:32 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

static t_txtr	*select_frame(t_gun *gun)
{
	if (gun->state == GUN_IDLE_A)
		return (&gun->idle_frames[gun->current_frame]);
	if (gun->state == GUN_IDLE_E)
		return (&gun->empty_frames[gun->current_frame]);
	if (gun->state == GUN_AIM || gun->state == GUN_UNAIM)
		return (&gun->aim_frames[gun->current_frame]);
	if (gun->state == GUN_SHOOT)
		return (&gun->shoot_frames[gun->current_frame]);
	if (gun->state == GUN_MELEE)
		return (&gun->melee_frames[gun->current_frame]);
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
