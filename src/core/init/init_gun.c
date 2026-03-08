/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 20:21:01 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/08 02:02:55 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

static void	load_gun_txtr(t_data *data, t_txtr *txtr, char *path)
{
	size_t	size;

	txtr->path = path;
	txtr->txtr = mlx_load_png(path);
	if (!txtr->txtr)
		exit_error(data, ERR_TEX_INVALID, EXIT_FAILURE);
	txtr->img = mlx_texture_to_image(data->mlx, txtr->txtr);
	if (!txtr->img)
		exit_error(data, ERR_MLX_IMG, EXIT_FAILURE);
	size = txtr->img->width * txtr->img->height * 4;
	txtr->original_pixels = malloc(size);
	if (!txtr->original_pixels)
		exit_error(data, ERR_MALLOC, EXIT_FAILURE);
	ft_memcpy(txtr->original_pixels, txtr->img->pixels, size);
	if (mlx_image_to_window(data->mlx, txtr->img, 0, 0) == ERROR)
		exit_error(data, ERR_MLX_WIN, EXIT_FAILURE);
	txtr->img->instances[0].enabled = FALSE;
	txtr->extracted = TRUE;
}

static void	init_gun_frames(t_data *data, t_gun *gun)
{
	load_gun_txtr(data, &gun->idle_frames[0], GUN_IDLE_0);
	load_gun_txtr(data, &gun->idle_frames[1], GUN_IDLE_1);
	load_gun_txtr(data, &gun->idle_frames[2], GUN_IDLE_2);
	load_gun_txtr(data, &gun->idle_frames[4], GUN_IDLE_1);
	load_gun_txtr(data, &gun->idle_frames[5], GUN_IDLE_0);
	// load_gun_txtr(data, &gun->aim_frames[0], GUN_AIM_0);
	// load_gun_txtr(data, &gun->aim_frames[1], GUN_AIM_1);
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
	gun->state = GUN_IDLE;
	gun->prev_state = GUN_IDLE;
	gun->ammo = GUN_MAX_AMMO;
	gun->max_ammo = GUN_MAX_AMMO;
	gun->shoot_damage = INIT_CROSSBOW_DAMAGE;
	gun->melee_damage = INIT_CROSSBOW_DAMAGE / 2;
	gun->current_frame = 0;
	gun->frame_timer = mlx_get_time();
	gun->frame_duration = FRAME_GUN_DURATION;
	gun->anim_done = FALSE;
	gun->last_hit = HIT_NONE;
	init_gun_frames(data, gun);
}
