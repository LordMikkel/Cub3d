/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 00:32:56 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/06 19:00:43 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

static void	update_single_door(t_map *map, t_door *door)
{
	if (door->is_open)
		door->open_percent += DOOR_ANIM_SPEED;
	else
		door->open_percent -= DOOR_ANIM_SPEED;
	if (door->open_percent > 1.0)
		door->open_percent = 1.0;
	if (door->open_percent < 0.0)
		door->open_percent = 0.0;
	if (door->open_percent >= 1.0)
		map->map_grid[(int)door->pos[Y]][(int)door->pos[X]] = 'O';
	else
		map->map_grid[(int)door->pos[Y]][(int)door->pos[X]] = 'D';
}

static void	update_doors(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->n_doors)
	{
		update_single_door(map, &map->doors[i]);
		i++;
	}
}

static void	update_player(t_plyr *player)
{
	player->head[POS] = player->head[TILT] + player->head[BOUNCE];
}

void	update_data(t_data *data)
{
	update_player(&data->player);
	update_doors(&data->map);
}
