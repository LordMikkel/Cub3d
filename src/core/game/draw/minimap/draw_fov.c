/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:55:44 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/06 21:09:28 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

/**
 * Helper function for Bresenham's line algorithm.
 * Evaluates the accumulated error to decide whether the next pixel of the
 * line should be incremented along the X axis, the Y axis, or both.
 * Separated to comply with strict line-count limits per function.
 *
 * @param current  The current [X, Y] pixel being evaluated.
 * @param delta    The absolute difference between start and end points.
 * @param step     The direction of the step (-1 or 1) for each axis.
 * @param error    Pointer to the accumulated error value.
 */
static void	update_pos(int *current, int *delta, int *step, int *error)
{
	int	error_double;

	error_double = 2 * (*error);
	if (error_double >= delta[Y])
	{
		*error += delta[Y];
		current[X] += step[X];
	}
	if (error_double <= delta[X])
	{
		*error += delta[X];
		current[Y] += step[Y];
	}
}

/**
 * Draws a single Field of View (FOV) ray using Bresenham's algorithm.
 * Casts a line from the start point to the end point, stopping early if
 * the ray exits the circular boundary of the minimap.
 *
 * @param data     Main data struct for the image buffer.
 * @param mm       Minimap struct for circular clipping checks.
 * @param current  The starting [X, Y] pixel coordinates (usually the center).
 * @param end      The target [X, Y] pixel coordinates where the ray hit a wall.
 */
static void	draw_bresenham_ray(t_data *data, t_mm *mm, int *current, int *end)
{
	int	delta[AXIS];
	int	step[AXIS];
	int	error;

	init_bresenham(delta, step, current, end);
	error = delta[X] + delta[Y];
	while (42)
	{
		if (is_inside_circle(mm, current[X], current[Y]))
			mlx_put_pixel(data->img, current[X], current[Y], MINIMAP_RAY_COLOR);
		if (current[X] == end[X] && current[Y] == end[Y])
			break ;
		update_pos(current, delta, step, &error);
	}
}

/**
 * Renders the Field of View (FOV) cone on the minimap.
 * Uses the ray hit coordinates previously calculated by the main 3D Raycaster.
 * Iterates through these hits (skipping some based on MINIMAP_RAY_STRIDE for
 * performance), converts their world positions to relative minimap pixels,
 * and draws the connecting lines from the player.
 *
 * @param data     Main data struct.
 * @param player   Player struct for the origin point of the rays.
 * @param minimap  Minimap struct holding the array of raycast hits.
 */
void	draw_minimap_fov(t_data *data, t_plyr *player, t_mm *minimap)
{
	int		col;
	int		start[AXIS];
	int		end[AXIS];
	double	ray_diff[AXIS];

	col = 0;
	while (col < (int)data->img->width)
	{
		ray_diff[X] = minimap->ray_hits[col][X] - player->pos[X];
		ray_diff[Y] = minimap->ray_hits[col][Y] - player->pos[Y];
		start[X] = minimap->center[X];
		start[Y] = minimap->center[Y];
		end[X] = start[X] + (int)(ray_diff[X] * minimap->cell_size);
		end[Y] = start[Y] + (int)(ray_diff[Y] * minimap->cell_size);
		draw_bresenham_ray(data, minimap, start, end);
		col += MINIMAP_RAY_STRIDE;
	}
}
