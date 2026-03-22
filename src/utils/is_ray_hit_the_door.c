/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ray_hit_the_door.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:29:35 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 17:40:01 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

/**
 * Checks if the current ray has intersected a specific door's grid position.
 * Compares the integer map coordinates of the door with the current grid
 * cell the ray is traversing a door.
 *
 * @param door  The door structure being evaluated.
 * @param ray   The ray currently being cast.
 * @return      TRUE if the ray's grid position matches the door's,
 *              FALSE otherwise.
 */
bool	is_ray_hit_the_door(t_door *door, t_ray *ray)
{
	if ((int)door->pos[X] == ray->pos[X] && (int)door->pos[Y] == ray->pos[Y])
		return (TRUE);
	return (FALSE);
}
