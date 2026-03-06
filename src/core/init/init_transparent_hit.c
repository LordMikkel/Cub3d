/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_transparent_hit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:07:14 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/06 17:44:23 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

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
