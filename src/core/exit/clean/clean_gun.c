/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_gun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 21:27:02 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/08 21:37:22 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

static void	clean_txtr_frames(t_data *data, t_txtr *frames, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (frames[i].original_pixels)
			ft_free((void **)&frames[i].original_pixels);
		if (frames[i].txtr)
			mlx_delete_texture(frames[i].txtr);
		if (frames[i].img)
			mlx_delete_image(data->mlx, frames[i].img);
		i++;
	}
}

void	clean_gun(t_data *data, t_gun *gun)
{
	if (!data || !gun)
		return ;
	clean_txtr_frames(data, gun->idle_frames, TOTAL_GUN_IDLE_FRAMES);
	clean_txtr_frames(data, gun->aim_frames, TOTAL_GUN_AIM_FRAMES);
	clean_txtr_frames(data, gun->shoot_frames, TOTAL_GUN_SHOOT_FRAMES);
	clean_txtr_frames(data, gun->melee_frames, TOTAL_GUN_MELEE_FRAMES);
	clean_txtr_frames(data, gun->reload_frames, TOTAL_GUN_RELOAD_FRAMES);
}
