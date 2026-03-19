/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 23:27:18 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/18 01:08:06 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

/**
 * Evaluates if the ray has hit a solid wall, door or left the map boundaries.
 * Acts as the collision sensor for the DDA loop. It does not decide if the
 * ray stops; it only reports that an entity occupying a full grid cell has
 * been detected. Also acts as a security check against Out of Bounds memory.
 *
 * @param map  The main map structure containing the grid and its limits.
 * @param ray  The current ray containing the (X, Y) grid position.
 * @return     TRUE if an obstacle was found, FALSE if the path is clear.
 */
bool	is_hit_wall_or_door(t_map *map, t_ray *ray)
{
	if (ray->pos[Y] < 0 || ray->pos[Y] >= map->map_limit[Y])
		return (TRUE);
	if (ray->pos[X] < 0 || ray->pos[X] >= map->map_limit[X])
		return (TRUE);
	if (is_wall(map->map_grid[ray->pos[Y]][ray->pos[X]]))
		return (TRUE);
	if (is_door(map->map_grid[ray->pos[Y]][ray->pos[X]]))
		return (TRUE);
	return (FALSE);
}

/**
 * Takes a "jump" with the ray to the next grid cell on the vertical axis (Y).
 *
 * 1. Position: Moves the ray to the next map row (+1 down or -1 up).
 * 2. Next Target: Updates `side_dist` by adding `delta_dist`
 * (the length of one block). This calculates the exact distance
 * the ray must travel to reach the next Y grid line.
 * 3. Orientation: Decides which texture to draw based on our viewing direction.
 * - If moving down (positive step), we are facing SOUTH.
 * - If moving up (negative step), we are facing NORTH.
 *
 * @param ray  The current ray being cast.
 */
void	move_y_side(t_ray *ray)
{
	ray->pos[Y] += ray->step[Y];
	ray->side_dist[Y] += ray->delta_dist[Y];
	if (ray->step[Y] > 0)
		ray->wall_side = SOUTH;
	else
		ray->wall_side = NORTH;
}

/**
 * Takes a "jump" with the ray to the next grid cell on the horizontal axis (X).
 *
 * 1. Position: Moves the ray to the next map column (+1 right or -1 left).
 * 2. Next Target: Updates `side_dist` by adding `delta_dist'
 * (the length of one block). This calculates the exact distance
 * the ray must travel to reach the next X grid line.
 * 3. Orientation: Decides which texture to draw based on our viewing direction.
 * - If moving right (positive step), we are facing EAST.
 * - If moving left (negative step), we are facing WEST.
 *
 * @param ray  The current ray being cast.
 */
void	move_x_side(t_ray *ray)
{
	ray->pos[X] += ray->step[X];
	ray->side_dist[X] += ray->delta_dist[X];
	if (ray->step[X] > 0)
		ray->wall_side = EAST;
	else
		ray->wall_side = WEST;
}

/**
 * The core loop of the Digital Differential Analyzer (DDA) algorithm.
 * Think of the ray as a blind person walking through the map grid.
 * At every step, it asks: "Which grid line is closer right now?
 * An X line or a Y line?" It ALWAYS takes the shortest possible jump.
 * This "staircase" movement guarantees that the ray perfectly intersects
 * every single grid cell without skipping corners or passing diagonally
 * through walls. It loops infinitely until it crashes into a wall or door.
 * - If it is a transparent door, it records the hit data and CONTINUES
 * traveling. The ray "pierces" the transparent object.
 * - If it is a solid wall, the loop breaks and the final distance is set.
 *
 * @param map  The parsed map data.
 * @param ray  The ray to cast through the grid.
 */
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
		if (is_hit_wall_or_door(map, ray))
		{
			if (is_transparent_door(map, ray))
				init_transparent_hit(ray);
			else
				hit = TRUE;
		}
	}
}
