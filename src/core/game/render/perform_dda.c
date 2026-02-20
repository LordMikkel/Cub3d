/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 23:27:18 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/19 23:15:48 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * Evaluates if the ray has hit a solid wall or left the map boundaries.
 * 1. Out of Bounds: Acts as an invisible security wall to prevent the program
 * from reading memory outside the 2D array (Segmentation Fault).
 * 2. Grid Check: Looks at the current map cell to see if it's a '1' (Wall).
 *
 * @param map  The main map structure containing the grid and its limits.
 * @param ray  The current ray containing the (X, Y) grid position.
 * @return     TRUE if a collision happened, FALSE if the path is clear.
 */
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

/**
 * Takes a "jump" with the ray to the next grid cell on the horizontal axis (X).
 *
 * 1. Position: Moves the ray to the next map column (+1 right or -1 left).
 * 2. Next Target: Updates `side_dist` by adding `delta_dist`
 * (the length of one block). This calculates the exact distance
 * the ray must travel to reach the *next* Y grid line.
 * 3. Orientation: Decides which texture to draw based on our viewing direction.
 * - If moving right (positive step), we are facing EAST.
 * - If moving left (negative step), we are facing WEST.
 *
 * @param ray  The current ray being cast.
 */
static void	move_y_side(t_ray *ray)
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
 * the ray must travel to reach the *next* X grid line.
 * 3. Orientation: Decides which texture to draw based on our viewing direction.
 * - If moving right (positive step), we are facing EAST.
 * - If moving left (negative step), we are facing WEST.
 *
 * @param ray  The current ray being cast.
 */
static void	move_x_side(t_ray *ray)
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
 * through walls. It loops infinitely until it crashes into a wall.
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
		if (is_hit_wall(map, ray))
			hit = TRUE;
	}
}
