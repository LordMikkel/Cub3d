/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_gun_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:02:15 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 17:21:04 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * Determines the appropriate idle state for the weapon based on its ammunition.
 * If the weapon has ammo remaining, it transitions to a standard idle state.
 * If the magazine is empty, it transitions to an empty idle state.
 *
 * @param gun  The gun structure being updated.
 */
static void	decide_idle_state(t_gun *gun)
{
	if (gun->ammo > 0)
		gun->state = GUN_IDLE_A;
	else
		gun->state = GUN_IDLE_E;
}

/**
 * Finalizes the variables when a weapon's animation cycle completes.
 * Resets the frame counter, flags the animation as done, and saves the state.
 * It also handles post-shoot logic, checks if a reload just finished, and
 * transitions the weapon back to an idle state unless the animation loops.
 *
 * @param gun  The gun structure whose animation just ended.
 */
static void	handle_animation_end(t_gun *gun)
{
	gun->current_frame = 0;
	gun->anim_done = TRUE;
	gun->prev_state = gun->state;
	if (gun->state == GUN_SHOOT)
		set_last_aim_frame(gun);
	check_reload_gun_finish(gun);
	if (!is_infinite_gun_animation(gun))
		decide_idle_state(gun);
}

/**
 * Reverses the animation frames, typically used when unaiming the weapon.
 * It accelerates the start of the rollback by skipping a set number of frames,
 * then decrements sequentially. Once it reaches frame 0, it sets the idle.
 *
 * @param gun  The gun structure currently rolling back its animation.
 */
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

/**
 * Progresses the weapon's animation to the next frame.
 * Intercepts specific states like unaiming (triggering a rollback) or holding
 * the last aim frame. If the animation reaches its maximum frame count for the
 * current state, it triggers the end-of-animation handler.
 *
 * @param data  The main program structure.
 * @param gun   The gun structure to be animated.
 * @return      Always returns NULL (used for concise returns and Norminette).
 */
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

/**
 * The master update loop for the weapon system, called every frame.
 * Uses the system time to ensure animations are framerate-independent.
 * It skips animation progress if the player isn't moving (e.g., stopping
 * view bobbing) and otherwise advances the gun's current animation frame.
 * debug options:
 * dbg_print_gun_state(gun, STDOUT);
 *
 * @param data  The main program structure containing player info.
 * @param gun   The gun structure being updated.
 */
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
