/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_total_perp_distance.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 01:27:47 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/19 17:50:49 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

static double	calculate_real_coord_wall(t_ray *ray, t_pos axis)
{
	if (ray->step[axis] > 0)
		return ((double)ray->pos[axis]);
	else
		return ((double)ray->pos[axis] + 1.0);
}

static void	calculate_distances(t_plyr *player, t_ray *ray, t_pos axis)
{
	double	wall_pos;

	wall_pos = calculate_real_coord_wall(ray, axis);
	ray->total_dist = wall_pos - player->pos[axis];
	ray->perp_dist = ray->total_dist / ray->dir[axis];
}

void	calculate_total_perp_distance(t_plyr *player, t_ray *ray)
{
	if (ray->wall_side == WEST || ray->wall_side == EAST)
		calculate_distances(player, ray, X);
	else
		calculate_distances(player, ray, Y);
}
