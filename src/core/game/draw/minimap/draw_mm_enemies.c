/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 23:40:03 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/21 23:40:13 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

void	draw_minimap_enemies(t_data *data, t_plyr *player, t_mm *minimap)
{
	int		i;
	int		pixel[AXIS];
	double	dist[AXIS];

	i = 0;
	while (i < data->map.n_enemies)
	{
		if (!data->enemies[i].is_dead)
		{
			dist[X] = data->enemies[i].pos[X] - player->pos[X];
			dist[Y] = data->enemies[i].pos[Y] - player->pos[Y];
			pixel[X] = minimap->center[X] + (int)(dist[X] * minimap->cell_size);
			pixel[Y] = minimap->center[Y] + (int)(dist[Y] * minimap->cell_size);
			pixel[X] -= minimap->player_center;
			pixel[Y] -= minimap->player_center;
			draw_square(data, pixel, MINIMAP_PLAYER_SIZE, 0xFF0000FF);
		}
		i++;
	}
}
