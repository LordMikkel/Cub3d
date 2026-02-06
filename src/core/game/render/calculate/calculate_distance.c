/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_distance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 01:27:47 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/06 02:30:26 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

//Study this math concepts behind
void	calculate_perp_distance(t_plyr *player, t_ray *ray)
{
	if (ray->wall_side == WEST || ray->wall_side == EAST)
	{
		ray->perp_dist = (ray->pos[X] - player->pos[X] + (1 - ray->step[X]) / 2)
			/ ray->dir[X];
	}
	else
	{
		ray->perp_dist = (ray->pos[Y] - player->pos[Y] + (1 - ray->step[Y]) / 2)
			/ ray->dir[Y];
	}
}
