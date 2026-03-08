/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_gun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 20:16:03 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/08 16:22:00 by migarrid         ###   ########.fr       */
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
	if (gun->state == GUN_IDLE)
		return (&gun->idle_frames[gun->current_frame]);
	if (gun->state == GUN_AIM)
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
	static t_txtr	*prev_frame = NULL;
	t_txtr			*frame;
	double			brightness;
	int				coord[AXIS];

	frame = select_frame(gun);
	if (!frame || !frame->img)
		return ;
	if (is_different_to_prev_frame(prev_frame, frame))
		prev_frame->img->instances[0].enabled = FALSE;
	brightness = calc_player_brightness(&data->map, &data->player);
	coord[X] = data->vars.gun_pos[X];
	coord[Y] = data->vars.gun_pos[Y];
	frame->img->instances[0].x = coord[X];
	frame->img->instances[0].y = coord[Y];
	frame->img->instances[0].enabled = TRUE;
	apply_light_to_gun(frame->img, frame->original_pixels, brightness);
	prev_frame = frame;
}
