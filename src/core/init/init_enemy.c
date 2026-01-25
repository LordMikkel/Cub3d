/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 04:56:47 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/25 06:52:40 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	init_enemy(t_data *data, int x, int y, char type)
{
	static int	i = 0;

	if (!data->map.enemies)
		data->map.enemies = allocator(data, data->map.n_enemy, sizeof(t_enemy));
	data->map.enemies[i].pos[X] = x;
	data->map.enemies[i].pos[Y] = y;
	if (type == 'X')
		data->map.enemies[i].type = ENEMY_ONE;
	else if (type == 'Y')
		data->map.enemies[i].type = ENEMY_TWO;
	else if (type == 'Z')
		data->map.enemies[i].type = ENEMY_THREE;
	i++;
}
