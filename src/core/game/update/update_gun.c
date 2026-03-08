/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_gun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:02:15 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/08 18:42:35 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

static int	get_max_frames(t_data *data, t_gun *gun)
{
	if (gun->state == GUN_IDLE)
		return (TOTAL_GUN_IDLE_FRAMES);
	if (gun->state == GUN_AIM)
		return (TOTAL_GUN_AIM_FRAMES);
	if (gun->state == GUN_SHOOT)
		return (TOTAL_GUN_SHOOT_FRAMES);
	if (gun->state == GUN_MELEE)
		return (TOTAL_GUN_MELEE_FRAMES);
	if (gun->state == GUN_RELOAD)
		return (TOTAL_GUN_RELOAD_FRAMES);
	return (exit_error(data, ERR_GUN_INVAL_STATE, EXIT_FAIL), ERROR);
}

static double	get_frame_duration(t_gun *gun)
{
	if (gun->state == GUN_IDLE)
		return (FRAME_GUN_IDLE_DURATION);
	if (gun->state == GUN_AIM)
		return (FRAME_GUN_AIM_DURATION);
	if (gun->state == GUN_SHOOT)
		return (FRAME_GUN_SHOOT_DURATION);
	if (gun->state == GUN_MELEE)
		return (FRAME_GUN_MELEE_DURATION);
	if (gun->state == GUN_RELOAD)
		return (FRAME_GUN_RELOAD_DURATION);
	return (FRAME_GUN_SHOOT_DURATION);
}

static bool	is_infinite_gun_animation(t_state state)
{
	if (state == GUN_IDLE || state == GUN_AIM)
		return (TRUE);
	return (FALSE);
}

static void	handle_animation_end(t_gun *gun)
{
	gun->current_frame = 0;
	gun->anim_done = TRUE;
	gun->prev_state = gun->state;
	if (!is_infinite_gun_animation(gun->state))
		gun->state = GUN_IDLE;
	check_reload_gun_finish(gun);
}

static void	advance_gun_frame(t_data *data, t_gun *gun)
{
	int	max_frames;

	max_frames = get_max_frames(data, gun);
	gun->current_frame++;
	if (gun->current_frame >= max_frames)
		handle_animation_end(gun);
	else
		gun->anim_done = FALSE;
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
}
