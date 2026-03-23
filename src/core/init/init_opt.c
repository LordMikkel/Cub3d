/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 19:40:02 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/23 01:00:40 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

static void	load_enemy_txtr(t_data *data, t_txtr *txtr, char *path)
{
	txtr->path = path;
	txtr->txtr = mlx_load_png(path);
	if (!txtr->txtr)
		exit_error(data, ERR_TEX_INVALID, EXIT_FAILURE);
	check_valid_texture(data, txtr, ENEMY_TXTR_HEIGH_FHD, ENEMY_TXTR_HEIGH_FHD);
}

static void	load_frames(t_data *data, t_txtr *frames, char **paths, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		load_enemy_txtr(data, &frames[i], paths[i]);
		i++;
	}
}

static void	init_enemy_x_frames(t_data *data, t_opt *vars)
{
	static char	*f[] = {ENEMY_X_FRONT_0, ENEMY_X_FRONT_1, ENEMY_X_FRONT_2,
		ENEMY_X_FRONT_3, ENEMY_X_FRONT_4, ENEMY_X_FRONT_5, ENEMY_X_FRONT_6,
		NULL};
	static char	*b[] = {ENEMY_X_BACK_0, ENEMY_X_BACK_1, ENEMY_X_BACK_2,
		ENEMY_X_BACK_3, ENEMY_X_BACK_4, ENEMY_X_BACK_5, ENEMY_X_BACK_6,
		ENEMY_X_BACK_7, ENEMY_X_BACK_8, ENEMY_X_BACK_9, NULL};
	static char	*l[] = {ENEMY_X_LEFT_0, ENEMY_X_LEFT_1, ENEMY_X_LEFT_2,
		ENEMY_X_LEFT_3, ENEMY_X_LEFT_4, ENEMY_X_LEFT_5, ENEMY_X_LEFT_6,
		ENEMY_X_LEFT_7, ENEMY_X_LEFT_8, ENEMY_X_LEFT_9, ENEMY_X_LEFT_10,
		NULL};
	static char	*r[] = {ENEMY_X_RIGHT_0, ENEMY_X_RIGHT_1, ENEMY_X_RIGHT_2,
		ENEMY_X_RIGHT_3, ENEMY_X_RIGHT_4, ENEMY_X_RIGHT_5, ENEMY_X_RIGHT_6,
		ENEMY_X_RIGHT_7, ENEMY_X_RIGHT_8, ENEMY_X_RIGHT_9, ENEMY_X_RIGHT_10,
		NULL};

	load_frames(data, vars->enemy_x_front, f, TOTAL_ENEMY_FRONT_FRAMES);
	load_frames(data, vars->enemy_x_back, b, TOTAL_ENEMY_BACK_FRAMES);
	load_frames(data, vars->enemy_x_left, l, TOTAL_ENEMY_LEFT_FRAMES);
	load_frames(data, vars->enemy_x_right, r, TOTAL_ENEMY_RIGHT_FRAMES);
}

static void	init_enemy_x_frames_act(t_data *data, t_opt *vars)
{
	static char	*d[] = {ENEMY_X_DEATH_0, ENEMY_X_DEATH_1, ENEMY_X_DEATH_2,
		ENEMY_X_DEATH_3, ENEMY_X_DEATH_4, ENEMY_X_DEATH_5, ENEMY_X_DEATH_6,
		ENEMY_X_DEATH_7, ENEMY_X_DEATH_8, ENEMY_X_DEATH_9, ENEMY_X_DEATH_10,
		ENEMY_X_DEATH_11, ENEMY_X_DEATH_12, ENEMY_X_DEATH_13,
		ENEMY_X_DEATH_14, ENEMY_X_DEATH_15, ENEMY_X_DEATH_16,
		ENEMY_X_DEATH_17, ENEMY_X_DEATH_18, ENEMY_X_DEATH_19,
		ENEMY_X_DEATH_20, ENEMY_X_DEATH_21, ENEMY_X_DEATH_22,
		ENEMY_X_DEATH_23, NULL};
	static char	*a[] = {ENEMY_X_ATTACK_0, ENEMY_X_ATTACK_1, ENEMY_X_ATTACK_2,
		ENEMY_X_ATTACK_3, ENEMY_X_ATTACK_4, ENEMY_X_ATTACK_5,
		ENEMY_X_ATTACK_6, ENEMY_X_ATTACK_7, ENEMY_X_ATTACK_8,
		ENEMY_X_ATTACK_9, ENEMY_X_ATTACK_10, ENEMY_X_ATTACK_11,
		ENEMY_X_ATTACK_12, ENEMY_X_ATTACK_13, ENEMY_X_ATTACK_14,
		ENEMY_X_ATTACK_15, ENEMY_X_ATTACK_16, ENEMY_X_ATTACK_17,
		ENEMY_X_ATTACK_18, ENEMY_X_ATTACK_19, ENEMY_X_ATTACK_20,
		ENEMY_X_ATTACK_21, ENEMY_X_ATTACK_22, ENEMY_X_ATTACK_23,
		ENEMY_X_ATTACK_24, ENEMY_X_ATTACK_25, ENEMY_X_ATTACK_26,
		ENEMY_X_ATTACK_27, ENEMY_X_ATTACK_28, ENEMY_X_ATTACK_29,
		ENEMY_X_ATTACK_30, NULL};

	load_frames(data, vars->enemy_x_death, d, TOTAL_ENEMY_DEATH_FRAMES);
	load_frames(data, vars->enemy_x_attack, a, TOTAL_ENEMY_ATTACK_FRAMES);
}

void	init_opt(t_data *data, t_opt *vars)
{
	int	mm_center_offset;
	int	mm_bottom_offset;

	init_cores(data, &data->vars);
	vars->half_img_height = data->img->height / 2;
	vars->half_img_width = data->img->width / 2;
	vars->gun_max_pixels = GUN_TXTR_WIDTH_FHD * GUN_TXTR_HEIGH_FHD * 4;
	vars->initial_min_dist_sq = DOOR_INTERACT_DIST * DOOR_INTERACT_DIST;
	vars->enemy_hear_range_sq = ENEMY_HEAR_RANGE * ENEMY_HEAR_RANGE;
	if (data->player.gun.model == CROSSBOW)
		vars->enemy_hear_range_sq /= 2;
	vars->shoot_dist_sq = MAX_DISTANCE_SHOT * MAX_DISTANCE_SHOT;
	vars->enemy_sight_range_sq = ENEMY_SIGHT_RANGE * ENEMY_SIGHT_RANGE;
	vars->gun_pos[X] = (data->img->width - GUN_TXTR_WIDTH_FHD) / 2;
	vars->gun_pos[Y] = data->img->height - GUN_TXTR_HEIGH_FHD;
	vars->health_bar_width = (int)(data->minimap.size[X] * 0.8);
	mm_center_offset = (data->minimap.size[X] - vars->health_bar_width) / 2;
	mm_bottom_offset = data->minimap.size[Y] + HEALTH_BAR_Y_OFFSET;
	vars->health_bar_pos[X] = data->minimap.offset[X] + mm_center_offset;
	vars->health_bar_pos[Y] = data->minimap.offset[Y] + mm_bottom_offset;
	init_enemy_x_frames(data, vars);
	init_enemy_x_frames_act(data, vars);
}

// static void	init_enemy_x_frames(t_data *data, t_opt *vars)
// {
// 	load_enemy_txtr(data, &vars->enemy_x_front[0], ENEMY_X_FRONT_0);
// 	load_enemy_txtr(data, &vars->enemy_x_front[1], ENEMY_X_FRONT_1);
// 	load_enemy_txtr(data, &vars->enemy_x_front[2], ENEMY_X_FRONT_2);
// 	load_enemy_txtr(data, &vars->enemy_x_front[3], ENEMY_X_FRONT_3);
// 	load_enemy_txtr(data, &vars->enemy_x_front[4], ENEMY_X_FRONT_4);
// 	load_enemy_txtr(data, &vars->enemy_x_front[5], ENEMY_X_FRONT_5);
// 	load_enemy_txtr(data, &vars->enemy_x_front[6], ENEMY_X_FRONT_6);
// 	load_enemy_txtr(data, &vars->enemy_x_back[0], ENEMY_X_BACK_0);
// 	load_enemy_txtr(data, &vars->enemy_x_back[1], ENEMY_X_BACK_1);
// 	load_enemy_txtr(data, &vars->enemy_x_back[2], ENEMY_X_BACK_2);
// 	load_enemy_txtr(data, &vars->enemy_x_back[3], ENEMY_X_BACK_3);
// 	load_enemy_txtr(data, &vars->enemy_x_back[4], ENEMY_X_BACK_4);
// 	load_enemy_txtr(data, &vars->enemy_x_back[5], ENEMY_X_BACK_5);
// 	load_enemy_txtr(data, &vars->enemy_x_back[6], ENEMY_X_BACK_6);
// 	load_enemy_txtr(data, &vars->enemy_x_back[7], ENEMY_X_BACK_7);
// 	load_enemy_txtr(data, &vars->enemy_x_back[8], ENEMY_X_BACK_8);
// 	load_enemy_txtr(data, &vars->enemy_x_back[9], ENEMY_X_BACK_9);
// 	load_enemy_txtr(data, &vars->enemy_x_left[0], ENEMY_X_LEFT_0);
// 	load_enemy_txtr(data, &vars->enemy_x_left[1], ENEMY_X_LEFT_1);
// 	load_enemy_txtr(data, &vars->enemy_x_left[2], ENEMY_X_LEFT_2);
// 	load_enemy_txtr(data, &vars->enemy_x_left[3], ENEMY_X_LEFT_3);
// 	load_enemy_txtr(data, &vars->enemy_x_left[4], ENEMY_X_LEFT_4);
// 	load_enemy_txtr(data, &vars->enemy_x_left[5], ENEMY_X_LEFT_5);
// 	load_enemy_txtr(data, &vars->enemy_x_left[6], ENEMY_X_LEFT_6);
// 	load_enemy_txtr(data, &vars->enemy_x_left[7], ENEMY_X_LEFT_7);
// 	load_enemy_txtr(data, &vars->enemy_x_left[8], ENEMY_X_LEFT_8);
// 	load_enemy_txtr(data, &vars->enemy_x_left[9], ENEMY_X_LEFT_9);
// 	load_enemy_txtr(data, &vars->enemy_x_left[10], ENEMY_X_LEFT_10);
// 	load_enemy_txtr(data, &vars->enemy_x_right[0], ENEMY_X_RIGHT_0);
// 	load_enemy_txtr(data, &vars->enemy_x_right[1], ENEMY_X_RIGHT_1);
// 	load_enemy_txtr(data, &vars->enemy_x_right[2], ENEMY_X_RIGHT_2);
// 	load_enemy_txtr(data, &vars->enemy_x_right[3], ENEMY_X_RIGHT_3);
// 	load_enemy_txtr(data, &vars->enemy_x_right[4], ENEMY_X_RIGHT_4);
// 	load_enemy_txtr(data, &vars->enemy_x_right[5], ENEMY_X_RIGHT_5);
// 	load_enemy_txtr(data, &vars->enemy_x_right[6], ENEMY_X_RIGHT_6);
// 	load_enemy_txtr(data, &vars->enemy_x_right[7], ENEMY_X_RIGHT_7);
// 	load_enemy_txtr(data, &vars->enemy_x_right[8], ENEMY_X_RIGHT_8);
// 	load_enemy_txtr(data, &vars->enemy_x_right[9], ENEMY_X_RIGHT_9);
// 	load_enemy_txtr(data, &vars->enemy_x_right[10], ENEMY_X_RIGHT_10);
// 	load_enemy_txtr(data, &vars->enemy_x_death[0], ENEMY_X_DEATH_0);
// 	load_enemy_txtr(data, &vars->enemy_x_death[1], ENEMY_X_DEATH_1);
// 	load_enemy_txtr(data, &vars->enemy_x_death[2], ENEMY_X_DEATH_2);
// 	load_enemy_txtr(data, &vars->enemy_x_death[3], ENEMY_X_DEATH_3);
// 	load_enemy_txtr(data, &vars->enemy_x_death[4], ENEMY_X_DEATH_4);
// 	load_enemy_txtr(data, &vars->enemy_x_death[5], ENEMY_X_DEATH_5);
// 	load_enemy_txtr(data, &vars->enemy_x_death[6], ENEMY_X_DEATH_6);
// 	load_enemy_txtr(data, &vars->enemy_x_death[7], ENEMY_X_DEATH_7);
// 	load_enemy_txtr(data, &vars->enemy_x_death[8], ENEMY_X_DEATH_8);
// 	load_enemy_txtr(data, &vars->enemy_x_death[9], ENEMY_X_DEATH_9);
// 	load_enemy_txtr(data, &vars->enemy_x_death[10], ENEMY_X_DEATH_10);
// 	load_enemy_txtr(data, &vars->enemy_x_death[11], ENEMY_X_DEATH_11);
// 	load_enemy_txtr(data, &vars->enemy_x_death[12], ENEMY_X_DEATH_12);
// 	load_enemy_txtr(data, &vars->enemy_x_death[13], ENEMY_X_DEATH_13);
// 	load_enemy_txtr(data, &vars->enemy_x_death[14], ENEMY_X_DEATH_14);
// 	load_enemy_txtr(data, &vars->enemy_x_death[15], ENEMY_X_DEATH_15);
// 	load_enemy_txtr(data, &vars->enemy_x_death[16], ENEMY_X_DEATH_16);
// 	load_enemy_txtr(data, &vars->enemy_x_death[17], ENEMY_X_DEATH_17);
// 	load_enemy_txtr(data, &vars->enemy_x_death[18], ENEMY_X_DEATH_18);
// 	load_enemy_txtr(data, &vars->enemy_x_death[19], ENEMY_X_DEATH_19);
// 	load_enemy_txtr(data, &vars->enemy_x_death[20], ENEMY_X_DEATH_20);
// 	load_enemy_txtr(data, &vars->enemy_x_death[21], ENEMY_X_DEATH_21);
// 	load_enemy_txtr(data, &vars->enemy_x_death[22], ENEMY_X_DEATH_22);
// 	load_enemy_txtr(data, &vars->enemy_x_death[23], ENEMY_X_DEATH_23);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[0], ENEMY_X_ATTACK_0);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[1], ENEMY_X_ATTACK_1);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[2], ENEMY_X_ATTACK_2);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[3], ENEMY_X_ATTACK_3);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[4], ENEMY_X_ATTACK_4);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[5], ENEMY_X_ATTACK_5);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[6], ENEMY_X_ATTACK_6);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[7], ENEMY_X_ATTACK_7);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[8], ENEMY_X_ATTACK_8);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[9], ENEMY_X_ATTACK_9);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[10], ENEMY_X_ATTACK_10);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[11], ENEMY_X_ATTACK_11);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[12], ENEMY_X_ATTACK_12);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[13], ENEMY_X_ATTACK_13);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[14], ENEMY_X_ATTACK_14);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[15], ENEMY_X_ATTACK_15);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[16], ENEMY_X_ATTACK_16);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[17], ENEMY_X_ATTACK_17);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[18], ENEMY_X_ATTACK_18);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[19], ENEMY_X_ATTACK_19);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[20], ENEMY_X_ATTACK_20);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[21], ENEMY_X_ATTACK_21);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[22], ENEMY_X_ATTACK_22);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[23], ENEMY_X_ATTACK_23);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[24], ENEMY_X_ATTACK_24);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[25], ENEMY_X_ATTACK_25);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[26], ENEMY_X_ATTACK_26);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[27], ENEMY_X_ATTACK_27);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[28], ENEMY_X_ATTACK_28);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[29], ENEMY_X_ATTACK_29);
// 	load_enemy_txtr(data, &vars->enemy_x_attack[30], ENEMY_X_ATTACK_30);
// }
