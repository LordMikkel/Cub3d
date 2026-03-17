/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 20:21:01 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/17 20:19:15 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

static void	load_gun_txtr(t_data *data, t_txtr *txtr, char *path)
{
	txtr->path = path;
	txtr->txtr = mlx_load_png(path);
	if (!txtr->txtr)
		exit_error(data, ERR_TEX_INVALID, EXIT_FAILURE);
	check_valid_texture(data, txtr, 1929, WIN_HEIGHT);
	txtr->extracted = TRUE;
}

static void	init_gun_frames(t_data *data, t_gun *gun)
{
	load_gun_txtr(data, &gun->idle_frames[0], GUN_IDLE_0);
	load_gun_txtr(data, &gun->idle_frames[1], GUN_IDLE_1);
	load_gun_txtr(data, &gun->idle_frames[2], GUN_IDLE_2);
	load_gun_txtr(data, &gun->idle_frames[3], GUN_IDLE_1);
	load_gun_txtr(data, &gun->idle_frames[4], GUN_IDLE_0);
	load_gun_txtr(data, &gun->aim_frames[0], GUN_AIM_0);
	load_gun_txtr(data, &gun->aim_frames[1], GUN_AIM_1);
	load_gun_txtr(data, &gun->aim_frames[2], GUN_AIM_2);
	load_gun_txtr(data, &gun->aim_frames[3], GUN_AIM_3);
	load_gun_txtr(data, &gun->aim_frames[4], GUN_AIM_4);
	load_gun_txtr(data, &gun->aim_frames[5], GUN_AIM_5);
	load_gun_txtr(data, &gun->aim_frames[6], GUN_AIM_6);
	load_gun_txtr(data, &gun->aim_frames[7], GUN_AIM_7);
	load_gun_txtr(data, &gun->aim_frames[8], GUN_AIM_8);
	load_gun_txtr(data, &gun->aim_frames[9], GUN_AIM_9);
	load_gun_txtr(data, &gun->aim_frames[10], GUN_AIM_10);
	load_gun_txtr(data, &gun->aim_frames[11], GUN_AIM_11);
	load_gun_txtr(data, &gun->aim_frames[12], GUN_AIM_12);
	load_gun_txtr(data, &gun->aim_frames[13], GUN_AIM_13);
	// load_gun_txtr(data, &gun->shoot_frames[0], GUN_SHOOT_0);
	// load_gun_txtr(data, &gun->shoot_frames[1], GUN_SHOOT_1);
	// load_gun_txtr(data, &gun->shoot_frames[2], GUN_SHOOT_2);
	// load_gun_txtr(data, &gun->shoot_frames[3], GUN_SHOOT_3);
	// load_gun_txtr(data, &gun->melee_frames[0], GUN_MELEE_0);
	// load_gun_txtr(data, &gun->melee_frames[1], GUN_MELEE_1);
	// load_gun_txtr(data, &gun->melee_frames[2], GUN_MELEE_2);
	// load_gun_txtr(data, &gun->melee_frames[3], GUN_MELEE_3);
	// load_gun_txtr(data, &gun->reload_frames[0], GUN_RELOAD_0);
	// load_gun_txtr(data, &gun->reload_frames[1], GUN_RELOAD_1);
	// load_gun_txtr(data, &gun->reload_frames[2], GUN_RELOAD_2);
	// load_gun_txtr(data, &gun->reload_frames[3], GUN_RELOAD_3);
}

void	init_gun(t_data *data, t_gun *gun)
{
	gun->state = GUN_IDLE_A;
	gun->prev_state = GUN_IDLE_A;
	gun->ammo = GUN_MAX_AMMO;
	gun->max_ammo = GUN_MAX_AMMO;
	gun->shoot_damage = INIT_CROSSBOW_DAMAGE;
	gun->melee_damage = INIT_CROSSBOW_DAMAGE / 2;
	gun->current_frame = 0;
	gun->frame_timer = mlx_get_time();
	gun->frame_duration = FRAME_GUN_IDLE_DURATION;
	gun->anim_done = FALSE;
	gun->last_hit = HIT_NONE;
	init_gun_frames(data, gun);
}
