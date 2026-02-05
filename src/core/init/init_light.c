/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 02:42:16 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/05 03:08:37 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	init_lights(t_data *data, int x, int y, char type)
{
	static int	i = 0;

	if (!data->map.lights)
		data->map.lights = allocator(data, data->map.n_enemis, sizeof(t_enemy));
	data->map.lights[i].pos[X] = (double)x + PRECISE_CENTER_CELL;
	data->map.lights[i].pos[Y] = (double)y + PRECISE_CENTER_CELL;
	i++;
}
