/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 04:56:47 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/07 02:32:40 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	init_enemy(t_data *data, int x, int y, char type)
{
	static int	i = 0;

	if (!data->enemies)
		data->enemies = alloc(data, data->map.n_enemies, sizeof(t_enemy));
	data->enemies[i].pos[X] = (double)x + PRECISE_CENTER_CELL;
	data->enemies[i].pos[Y] = (double)y + PRECISE_CENTER_CELL;
	if (type == 'X')
		data->enemies[i].type = ENEMY_ONE;
	else if (type == 'Y')
		data->enemies[i].type = ENEMY_TWO;
	else if (type == 'Z')
		data->enemies[i].type = ENEMY_THREE;
	i++;
}
