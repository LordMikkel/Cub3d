/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_impact_in_wall_x.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 04:52:42 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/20 00:03:42 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

// estudiar mas esta función y su matemática
/**
 * Calculates the exact global coordinate where the ray hit the wall.
 *
 * This uses the standard vector math formula: Impact = Start + (Dist * Dir).
 * If the ray hits a vertical wall (East or West), its X coordinate is
 * already fixed exactly on the grid line. Therefore, we only need to
 * calculate its exact Y position along that wall. We find this by taking
 * the player's starting Y and adding the ray's Y-direction scaled by the
 * traveled distance. For horizontal walls (North/South), we calculate X.
 *
 * @param player  The player's structure with their current position.
 * @param ray     The ray containing the distance and direction vectors.
 * @return        The exact double-precision global impact coordinate.
 */
static double	get_impact_coordinate(t_plyr *player, t_ray *ray)
{
	if (ray->wall_side == WEST || ray->wall_side == EAST)
		return (player->pos[Y] + (ray->perp_dist * ray->dir[Y]));
	else
		return (player->pos[X] + (ray->perp_dist * ray->dir[X]));
}

/**
 * Determines the exact fractional point of impact on the wall's surface.
 *
 * To know which vertical column of a texture to draw, we need to find
 * where the ray hit the wall block (from 0.0 to 1.0). By subtracting
 * the floor (integer part) from the absolute map coordinate, we isolate
 * the decimal remainder. This remainder is the exact percentage across
 * the face of the brick, which we will later multiply by texture width.
 *
 * @param player  The player's data structure.
 * @param ray     The ray whose wall impact fraction will be updated.
 */
void	calculate_impact_in_wall_x(t_plyr *player, t_ray *ray)
{
	double	absolute_impact;

	absolute_impact = get_impact_coordinate(player, ray);
	ray->wall[X] = absolute_impact - floor(absolute_impact);
}
