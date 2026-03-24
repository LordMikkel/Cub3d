/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:09:21 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/24 16:51:31 by migarrid         ###   ########.fr       */
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
 * Liberates all preloaded memory allocated during init_opt.
 * Specifically targets the arrays of textures loaded for enemies.
 *
 * @param vars  The options struct.
 */
void	clean_opt(t_opt *vars)
{
	if (!vars)
		return ;
	clean_txtr_frames(vars->enemy_x_front, TOTAL_ENEMY_FRONT_FRAMES);
	clean_txtr_frames(vars->enemy_x_back, TOTAL_ENEMY_BACK_FRAMES);
	clean_txtr_frames(vars->enemy_x_left, TOTAL_ENEMY_LEFT_FRAMES);
	clean_txtr_frames(vars->enemy_x_right, TOTAL_ENEMY_RIGHT_FRAMES);
	clean_txtr_frames(vars->enemy_x_attack, TOTAL_ENEMY_ATTACK_FRAMES);
	clean_txtr_frames(vars->enemy_x_death, TOTAL_ENEMY_DEATH_FRAMES);
}
