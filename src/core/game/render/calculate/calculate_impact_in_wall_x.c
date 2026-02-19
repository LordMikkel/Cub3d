/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_impact_in_wall_x.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 04:52:42 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/19 19:55:26 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

static double	get_impact_coordinate(t_plyr *player, t_ray *ray)
{
	if (ray->wall_side == WEST || ray->wall_side == EAST)
		return (player->pos[Y] + (ray->perp_dist * ray->dir[Y]));
	else
		return (player->pos[X] + (ray->perp_dist * ray->dir[X]));
}

void	calculate_impact_in_wall_x(t_plyr *player, t_ray *ray)
{
	double	absolute_impact;

	absolute_impact = get_impact_coordinate(player, ray);
	ray->wall[X] = absolute_impact - floor(absolute_impact);
}
