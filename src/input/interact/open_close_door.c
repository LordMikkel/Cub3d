/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close_door.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:54:50 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/05 21:39:02 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

static double	get_door_dist_sq(t_plyr *player, t_door *door, int out_of_bound)
{
	double	dx;
	double	dy;

	dx = player->pos[X] - door->pos[X];
	if (dx > DOOR_INTERACT_DIST || dx < -DOOR_INTERACT_DIST)
		return (out_of_bound + 1.0);
	dy = player->pos[Y] - door->pos[Y];
	if (dy > DOOR_INTERACT_DIST || dx < -DOOR_INTERACT_DIST)
		return (out_of_bound + 1.0);
	return ((dx * dx) + (dy * dy));
}

t_door	*get_nearest_door(t_data *data, t_map *map)
{
	t_door	*nearest;
	double	min_dist_sq;
	double	dist_sq;
	int		i;

	i = 0;
	nearest = NULL;
	min_dist_sq = DOOR_INTERACT_DIST * DOOR_INTERACT_DIST;
	while (i < map->n_doors)
	{
		dist_sq = get_door_dist_sq(&data->player, &map->doors[i], min_dist_sq);
		if (dist_sq <= min_dist_sq)
		{
			min_dist_sq = dist_sq;
			nearest = &map->doors[i];
		}
		i++;
	}
	return (nearest);
}

void	open_close_door(t_data *data, t_map *map, bool *key_held)
{
	t_door *door;

	if (*key_held)
		return;
	door = get_nearest_door(data, map);
	if (door)
		door->is_open = !door->is_open;
	*key_held = TRUE;
}
