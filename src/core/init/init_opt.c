/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 19:40:02 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/19 21:13:31 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

// static void	load_enemy_txtr(t_data *data, t_txtr *txtr, char *path)
// {
// 	txtr->path = path;
// 	txtr->txtr = mlx_load_png(path);
// 	if (!txtr->txtr)
// 		exit_error(data, ERR_TEX_INVALID, EXIT_FAILURE);
// 	check_valid_texture(data, txtr, GUN_TXTR_WIDTH_FHD, GUN_TXTR_HEIGH_FHD + 30);
// 	txtr->extracted = TRUE;
// }

// static void	init_enemy_frames(t_data *data, t_opt *vars)
// {
// 	load_enemy_txtr(data, &vars->enemy_idle[0], ENEMY_IDLE_0);
// 	load_enemy_txtr(data, &vars->enemy_idle[1], ENEMY_IDLE_1);
// 	load_enemy_txtr(data, &vars->enemy_idle[2], ENEMY_IDLE_2);
// }

void	init_opt(t_data *data, t_opt *vars)
{
	init_cores(data, &data->vars);
	vars->half_img_height = data->img->height / 2;
	vars->half_img_width = data->img->width / 2;
	vars->gun_max_pixels = GUN_TXTR_WIDTH_FHD * GUN_TXTR_HEIGH_FHD * 4;
	vars->initial_min_dist_sq = DOOR_INTERACT_DIST * DOOR_INTERACT_DIST;
	vars->enemy_hear_range_sq = ENEMY_HEAR_RANGE * ENEMY_HEAR_RANGE;
	vars->gun_pos[X] = (data->img->width - GUN_TXTR_WIDTH_FHD) / 2;
	vars->gun_pos[Y] = data->img->height - GUN_TXTR_HEIGH_FHD;
	// init_enemy_frames(data, vars);
}
