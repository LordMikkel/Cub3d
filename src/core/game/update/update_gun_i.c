/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_gun_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:02:15 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/19 21:13:45 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

static void	decide_idle_state(t_gun *gun)
{
	if (gun->ammo > 0)
		gun->state = GUN_IDLE_A;
	else
		gun->state = GUN_IDLE_E;
}

static void	handle_animation_end(t_gun *gun)
{
	gun->current_frame = 0;
	gun->anim_done = TRUE;
	gun->prev_state = gun->state;
	if (gun->state == GUN_SHOOT)
		set_last_aim_frame(gun);
	if (!is_infinite_gun_animation(gun))
		decide_idle_state(gun);
	check_reload_gun_finish(gun);
}

static void	handle_rollback_animation(t_gun *gun)
{
	int	skip_frames;

	skip_frames = 4;
	if (gun->current_frame >= TOTAL_GUN_AIM_FRAMES - 1)
		gun->current_frame -= skip_frames;
	if (gun->current_frame > 0)
		gun->current_frame--;
	else
		decide_idle_state(gun);
}

static char	*advance_gun_frame(t_data *data, t_gun *gun)
{
	int	max_frames;

	if (gun->state == GUN_UNAIM)
		return (handle_rollback_animation(gun), NULL);
	if (is_last_aim_frame(gun))
		return (gun->anim_done = TRUE, NULL);
	max_frames = get_max_frames(data, gun);
	gun->current_frame++;
	if (gun->current_frame >= max_frames)
		handle_animation_end(gun);
	else
		gun->anim_done = FALSE;
	return (NULL);
}

void	update_gun(t_data *data, t_gun *gun)
{
	double	now;

	now = mlx_get_time();
	gun->frame_duration = get_frame_duration(gun);
	if (is_frame_not_finished(gun, now))
		return ;
	if (is_player_not_moving(&data->player, gun))
	{
		gun->current_frame = 0;
		return ;
	}
	gun->frame_timer = now;
	advance_gun_frame(data, gun);
	// dbg_print_gun_state(gun, STDOUT);
}
