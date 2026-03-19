/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_gun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 21:27:02 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/18 22:47:36 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

static void	clean_txtr_frames(t_txtr *frames, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (frames[i].txtr)
			mlx_delete_texture(frames[i].txtr);
		i++;
	}
}

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
