/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_gun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 21:27:02 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 18:08:58 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * Safely iterates through an array of texture frames and deletes them.
 * Crucial for preventing memory leaks during program exit or map reloading.
 * Only attempts to delete the texture if the pointer is not NULL, setting
 * it back to NULL afterwards to prevent dangling pointers.
 *
 * @param frames  The array of texture structures.
 * @param count   The number of elements to process in the array.
 */
static void	clean_txtr_frames(t_txtr *frames, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (frames[i].txtr)
		{
			mlx_delete_texture(frames[i].txtr);
			frames[i].txtr = NULL;
		}
		i++;
	}
}

/**
 * Liberates all preloaded memory allocated for the weapon's animations.
 * Centralized cleanup function that iterates through every distinct state
 * array (idle, shoot, reload, etc.) to free MLX texture memory.
 *
 * @param gun  The weapon structure to clean up.
 */
void	clean_gun(t_gun *gun)
{
	if (!gun)
		return ;
	clean_txtr_frames(gun->idle_frames, TOTAL_GUN_IDLE_FRAMES);
	clean_txtr_frames(gun->empty_frames, TOTAL_GUN_IDLE_FRAMES);
	clean_txtr_frames(gun->aim_frames, TOTAL_GUN_AIM_FRAMES);
	clean_txtr_frames(gun->shoot_frames, TOTAL_GUN_SHOOT_FRAMES);
	clean_txtr_frames(gun->melee_frames, TOTAL_GUN_MELEE_FRAMES);
	clean_txtr_frames(gun->reload_frames, TOTAL_GUN_RELOAD_FRAMES);
}
