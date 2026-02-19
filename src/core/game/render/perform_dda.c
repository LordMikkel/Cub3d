/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 23:27:18 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/19 04:47:28 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

static bool	is_hit_wall(t_map *map, t_ray *ray)
{
	if (ray->pos[Y] < 0 || ray->pos[Y] >= map->map_limit[Y])
		return (TRUE);
	if (ray->pos[X] < 0 || ray->pos[X] >= map->map_limit[X])
		return (TRUE);
	if (map->map_grid[ray->pos[Y]][ray->pos[X]] == '1')
		return (TRUE);
	return (FALSE);
}

static void	move_y_side(t_ray *ray)
{
	ray->pos[Y] += ray->step[Y];
	ray->side_dist[Y] += ray->delta_dist[Y];
	if (ray->step[Y] > 0)
		ray->wall_side = SOUTH;
	else
		ray->wall_side = NORTH;
}

static void	move_x_side(t_ray *ray)
{
	ray->pos[X] += ray->step[X];
	ray->side_dist[X] += ray->delta_dist[X];
	if (ray->step[X] > 0)
		ray->wall_side = EAST;
	else
		ray->wall_side = WEST;
}

void	perform_dda(t_map *map, t_ray *ray)
{
	bool	hit;

	hit = FALSE;
	while (!hit)
	{
		if (ray->side_dist[X] < ray->side_dist[Y])
			move_x_side(ray);
		else
			move_y_side(ray);
		if (is_hit_wall(map, ray))
			hit = TRUE;
	}
}
