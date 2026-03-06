/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_total_perp_distance.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 01:27:47 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/06 17:35:33 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

/**
 * Finds the exact mathematical coordinate of the wall the ray just hit.
 *
 * Depending on the ray's direction (step), it hits different sides of
 * a grid cell. If moving positively, it hits the near edge (EAST or SOUTH),
 * which is the exact grid index. If moving negatively, it hits the far edge,
 * (WEST or NORTH) which mathematically requires adding 1.0 to the grid index.
 * because the size of the volume of the block itself.
 *
 * @param ray   The current ray being cast.
 * @param axis  The axis (X or Y) where the collision happened.
 * @return      The precise double-precision coordinate of the wall.
 */
static double	calculate_real_coord_wall(t_ray *ray, t_pos axis)
{
	if (ray->step[axis] > 0)
		return ((double)ray->pos[axis]);
	else
		return ((double)ray->pos[axis] + 1.0);
}

// estudiar mas esta función y su matemática
/**
 * Calculates the perpendicular distance to the wall to prevent fisheye.
 *
 * First, it gets the distance between the player and the wall on
 * the collision axis. Then, dividing by the ray's direction vector
 * mathematically projects this distance onto the camera plane. This
 * perpendicular distance ensures walls appear straight and flat.
 *
 * @param player  The player's current position and data.
 * @param ray     The ray structure to update with distance data.
 * @param axis    The axis (X or Y) of the confirmed wall hit.
 */
static void	calculate_distance(t_plyr *player, t_ray *ray, t_pos axis)
{
	double	axis_dist;
	double	wall_pos;

	wall_pos = calculate_real_coord_wall(ray, axis);
	axis_dist = wall_pos - player->pos[axis];
	ray->perp_dist = axis_dist / ray->dir[axis];
}

/**
 * Orchestrator for distance calculations after a confirmed wall hit.
 *
 * Evaluates which side of a wall was struck by the ray. If it hit the
 * East or West face, the collision happened along the X-axis. If it
 * hit North or South, it was the Y-axis. It routes to the math logic.
 *
 * @param player  The player's struct.
 * @param ray     The ray that just completed the DDA loop.
 */
void	calculate_perp_distance(t_plyr *player, t_ray *ray)
{
	if (ray->wall_side == WEST || ray->wall_side == EAST)
		calculate_distance(player, ray, X);
	else
		calculate_distance(player, ray, Y);
}
