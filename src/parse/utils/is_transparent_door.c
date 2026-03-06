/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_transparent_door.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:06:33 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/06 17:07:54 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

static double	get_door_open_percent(t_map *map, t_ray *ray)
{
	int	i;

	i = 0;
	while (i < map->n_doors)
	{
		if (is_ray_door(&map->doors[i], ray))
			return (map->doors[i].open_percent);
		i++;
	}
	return (0.0);
}

bool	is_transparent_door(t_map *map, t_ray *ray)
{
	if (!is_inside_map_cells(map, ray->pos))
		return (FALSE);
	if (!is_door(map->map_grid[ray->pos[Y]][ray->pos[X]]))
		return (FALSE);
	return (get_door_open_percent(map, ray) > 0.0);
}
