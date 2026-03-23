/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 20:21:01 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 23:12:29 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

static void	load_gun_txtr(t_data *data, t_txtr *txtr, char *path)
{
	txtr->path = path;
	txtr->txtr = mlx_load_png(path);
	if (!txtr->txtr)
		exit_error(data, ERR_TEX_INVALID, EXIT_FAILURE);
	check_valid_texture(data, txtr, GUN_TXTR_WIDTH_FHD, GUN_TXTR_HEIGH_FHD
		+ 30);
}

static void	load_frames(t_data *data, t_txtr *frames, char **paths, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		load_gun_txtr(data, &frames[i], paths[i]);
		i++;
	}
}

void	init_gun_frames_ii(t_data *data, t_gun *gun)
{
	static char	*aim[] = {GUN_AIM_0, GUN_AIM_1, GUN_AIM_2, GUN_AIM_3, GUN_AIM_4,
		GUN_AIM_5, GUN_AIM_6, GUN_AIM_7, GUN_AIM_8, GUN_AIM_9, NULL};
	static char	*shoot[] = {GUN_SHOOT_0, GUN_SHOOT_1, GUN_SHOOT_2, GUN_SHOOT_3,
		GUN_SHOOT_4, GUN_SHOOT_5, GUN_SHOOT_6, GUN_SHOOT_7, GUN_SHOOT_8,
		GUN_SHOOT_9, NULL};
	static char	*melee[] = {GUN_MELEE_0, GUN_MELEE_1, GUN_MELEE_2, GUN_MELEE_3,
		GUN_MELEE_4, GUN_MELEE_5, GUN_MELEE_6, GUN_MELEE_7, GUN_MELEE_8,
		GUN_MELEE_9, GUN_MELEE_10, GUN_MELEE_11, GUN_MELEE_12, GUN_MELEE_13,
		GUN_MELEE_14, GUN_MELEE_15, GUN_MELEE_16, GUN_MELEE_17, GUN_MELEE_18,
		GUN_MELEE_19, GUN_MELEE_20, GUN_MELEE_21, GUN_MELEE_22,
		GUN_MELEE_23, NULL};
	static char	*reload[] = {GUN_RELOAD_0, GUN_RELOAD_1, GUN_RELOAD_2,
		GUN_RELOAD_3, GUN_RELOAD_4, GUN_RELOAD_5, GUN_RELOAD_6,
		GUN_RELOAD_7, GUN_RELOAD_8, GUN_RELOAD_9, GUN_RELOAD_10,
		GUN_RELOAD_11, GUN_RELOAD_12, GUN_RELOAD_13, GUN_RELOAD_14,
		GUN_RELOAD_15, GUN_RELOAD_16, GUN_RELOAD_17, GUN_RELOAD_18,
		GUN_RELOAD_19, GUN_RELOAD_20, GUN_RELOAD_21, GUN_RELOAD_22,
		GUN_RELOAD_23, GUN_RELOAD_24, NULL};

	load_frames(data, gun->aim_frames, aim, TOTAL_GUN_AIM_FRAMES);
	load_frames(data, gun->shoot_frames, shoot, TOTAL_GUN_SHOOT_FRAMES);
	load_frames(data, gun->melee_frames, melee, TOTAL_GUN_MELEE_FRAMES);
	load_frames(data, gun->reload_frames, reload, TOTAL_GUN_RELOAD_FRAMES);
}

void	init_gun_frames_i(t_data *data, t_gun *gun)
{
	static char	*idle[] = {GUN_IDLE_0, GUN_IDLE_1, GUN_IDLE_2, GUN_IDLE_1,
		GUN_IDLE_0, NULL};
	static char	*empty[] = {GUN_EMPTY_0, GUN_EMPTY_1, GUN_EMPTY_2, GUN_EMPTY_1,
		GUN_EMPTY_0, NULL};

	load_frames(data, gun->idle_frames, idle, TOTAL_GUN_IDLE_FRAMES);
	load_frames(data, gun->empty_frames, empty, TOTAL_GUN_IDLE_FRAMES);
}

void	init_gun(t_data *data, t_gun *gun)
{
	gun->state = GUN_IDLE_A;
	gun->prev_state = GUN_IDLE_A;
	gun->ammo = GUN_CROSSBOW_MAX_AMMO;
	gun->max_ammo = GUN_CROSSBOW_MAX_AMMO;
	gun->shoot_damage = CROSSBOW_DAMAGE;
	gun->melee_damage = CROSSBOW_MELEE_DAMAGE;
	gun->current_frame = 0;
	gun->frame_timer = mlx_get_time();
	gun->frame_duration = FRAME_GUN_IDLE_DURATION;
	gun->anim_done = FALSE;
	gun->last_hit = HIT_NONE;
	init_gun_frames_i(data, gun);
	init_gun_frames_ii(data, gun);
}

// static void	init_gun_frames(t_data *data, t_gun *gun)
// {
// 	load_gun_txtr(data, &gun->idle_frames[0], GUN_IDLE_0);
// 	load_gun_txtr(data, &gun->idle_frames[1], GUN_IDLE_1);
// 	load_gun_txtr(data, &gun->idle_frames[2], GUN_IDLE_2);
// 	load_gun_txtr(data, &gun->idle_frames[3], GUN_IDLE_1);
// 	load_gun_txtr(data, &gun->idle_frames[4], GUN_IDLE_0);
// 	load_gun_txtr(data, &gun->aim_frames[0], GUN_AIM_0);
// 	load_gun_txtr(data, &gun->aim_frames[1], GUN_AIM_1);
// 	load_gun_txtr(data, &gun->aim_frames[2], GUN_AIM_2);
// 	load_gun_txtr(data, &gun->aim_frames[3], GUN_AIM_3);
// 	load_gun_txtr(data, &gun->aim_frames[4], GUN_AIM_4);
// 	load_gun_txtr(data, &gun->aim_frames[5], GUN_AIM_5);
// 	load_gun_txtr(data, &gun->aim_frames[6], GUN_AIM_6);
// 	load_gun_txtr(data, &gun->aim_frames[7], GUN_AIM_7);
// 	load_gun_txtr(data, &gun->aim_frames[8], GUN_AIM_8);
// 	load_gun_txtr(data, &gun->aim_frames[9], GUN_AIM_9);
// 	load_gun_txtr(data, &gun->shoot_frames[0], GUN_SHOOT_0);
// 	load_gun_txtr(data, &gun->shoot_frames[1], GUN_SHOOT_1);
// 	load_gun_txtr(data, &gun->shoot_frames[2], GUN_SHOOT_2);
// 	load_gun_txtr(data, &gun->shoot_frames[3], GUN_SHOOT_3);
// 	load_gun_txtr(data, &gun->shoot_frames[4], GUN_SHOOT_4);
// 	load_gun_txtr(data, &gun->shoot_frames[5], GUN_SHOOT_5);
// 	load_gun_txtr(data, &gun->shoot_frames[6], GUN_SHOOT_6);
// 	load_gun_txtr(data, &gun->shoot_frames[7], GUN_SHOOT_7);
// 	load_gun_txtr(data, &gun->shoot_frames[8], GUN_SHOOT_8);
// 	load_gun_txtr(data, &gun->shoot_frames[9], GUN_SHOOT_9);
// 	load_gun_txtr(data, &gun->empty_frames[0], GUN_EMPTY_0);
// 	load_gun_txtr(data, &gun->empty_frames[1], GUN_EMPTY_1);
// 	load_gun_txtr(data, &gun->empty_frames[2], GUN_EMPTY_2);
// 	load_gun_txtr(data, &gun->empty_frames[3], GUN_EMPTY_1);
// 	load_gun_txtr(data, &gun->empty_frames[4], GUN_EMPTY_0);
// 	load_gun_txtr(data, &gun->melee_frames[0], GUN_MELEE_0);
// 	load_gun_txtr(data, &gun->melee_frames[1], GUN_MELEE_1);
// 	load_gun_txtr(data, &gun->melee_frames[2], GUN_MELEE_2);
// 	load_gun_txtr(data, &gun->melee_frames[3], GUN_MELEE_3);
// 	load_gun_txtr(data, &gun->melee_frames[4], GUN_MELEE_4);
// 	load_gun_txtr(data, &gun->melee_frames[5], GUN_MELEE_5);
// 	load_gun_txtr(data, &gun->melee_frames[6], GUN_MELEE_6);
// 	load_gun_txtr(data, &gun->melee_frames[7], GUN_MELEE_7);
// 	load_gun_txtr(data, &gun->melee_frames[8], GUN_MELEE_8);
// 	load_gun_txtr(data, &gun->melee_frames[9], GUN_MELEE_9);
// 	load_gun_txtr(data, &gun->melee_frames[10], GUN_MELEE_10);
// 	load_gun_txtr(data, &gun->melee_frames[11], GUN_MELEE_11);
// 	load_gun_txtr(data, &gun->melee_frames[12], GUN_MELEE_12);
// 	load_gun_txtr(data, &gun->melee_frames[13], GUN_MELEE_13);
// 	load_gun_txtr(data, &gun->melee_frames[14], GUN_MELEE_14);
// 	load_gun_txtr(data, &gun->melee_frames[15], GUN_MELEE_15);
// 	load_gun_txtr(data, &gun->melee_frames[16], GUN_MELEE_16);
// 	load_gun_txtr(data, &gun->melee_frames[17], GUN_MELEE_17);
// 	load_gun_txtr(data, &gun->melee_frames[18], GUN_MELEE_18);
// 	load_gun_txtr(data, &gun->melee_frames[19], GUN_MELEE_19);
// 	load_gun_txtr(data, &gun->melee_frames[20], GUN_MELEE_20);
// 	load_gun_txtr(data, &gun->melee_frames[21], GUN_MELEE_21);
// 	load_gun_txtr(data, &gun->melee_frames[22], GUN_MELEE_22);
// 	load_gun_txtr(data, &gun->melee_frames[23], GUN_MELEE_23);
// 	load_gun_txtr(data, &gun->reload_frames[0], GUN_RELOAD_0);
// 	load_gun_txtr(data, &gun->reload_frames[1], GUN_RELOAD_1);
// 	load_gun_txtr(data, &gun->reload_frames[2], GUN_RELOAD_2);
// 	load_gun_txtr(data, &gun->reload_frames[3], GUN_RELOAD_3);
// 	load_gun_txtr(data, &gun->reload_frames[4], GUN_RELOAD_4);
// 	load_gun_txtr(data, &gun->reload_frames[5], GUN_RELOAD_5);
// 	load_gun_txtr(data, &gun->reload_frames[6], GUN_RELOAD_6);
// 	load_gun_txtr(data, &gun->reload_frames[7], GUN_RELOAD_7);
// 	load_gun_txtr(data, &gun->reload_frames[8], GUN_RELOAD_8);
// 	load_gun_txtr(data, &gun->reload_frames[9], GUN_RELOAD_9);
// 	load_gun_txtr(data, &gun->reload_frames[10], GUN_RELOAD_10);
// 	load_gun_txtr(data, &gun->reload_frames[11], GUN_RELOAD_11);
// 	load_gun_txtr(data, &gun->reload_frames[12], GUN_RELOAD_12);
// 	load_gun_txtr(data, &gun->reload_frames[13], GUN_RELOAD_13);
// 	load_gun_txtr(data, &gun->reload_frames[14], GUN_RELOAD_14);
// 	load_gun_txtr(data, &gun->reload_frames[15], GUN_RELOAD_15);
// 	load_gun_txtr(data, &gun->reload_frames[16], GUN_RELOAD_16);
// 	load_gun_txtr(data, &gun->reload_frames[17], GUN_RELOAD_17);
// 	load_gun_txtr(data, &gun->reload_frames[18], GUN_RELOAD_18);
// 	load_gun_txtr(data, &gun->reload_frames[19], GUN_RELOAD_19);
// 	load_gun_txtr(data, &gun->reload_frames[20], GUN_RELOAD_20);
// 	load_gun_txtr(data, &gun->reload_frames[21], GUN_RELOAD_21);
// 	load_gun_txtr(data, &gun->reload_frames[22], GUN_RELOAD_22);
// 	load_gun_txtr(data, &gun->reload_frames[23], GUN_RELOAD_23);
// 	load_gun_txtr(data, &gun->reload_frames[24], GUN_RELOAD_24);
// }
