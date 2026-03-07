/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_transparent_hit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:07:14 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/06 21:25:53 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Logs the state of the ray at the exact moment it passes through a transparent
 * door. This data (position, side hit, specific wall coordinates) is saved in a
 * history array so the engine can go back and render this transparent layer
 * later, once the solid wall behind it has been drawn.
 *
 * @param ray  The ray containing the hit state to freeze and save.
 */
void	init_transparent_hit(t_ray *ray)
{
	int	i;

	i = ray->n_transparent_hits;
	if (ray->n_transparent_hits >= MAX_TRANSPARENT_HITS)
		return ;
	ray->transparent_hits[i].pos[X] = ray->pos[X];
	ray->transparent_hits[i].pos[Y] = ray->pos[Y];
	ray->transparent_hits[i].wall_side = ray->wall_side;
	ray->transparent_hits[i].wall[X] = ray->wall[X];
	ray->transparent_hits[i].wall[Y] = ray->wall[Y];
	ray->n_transparent_hits++;
}
