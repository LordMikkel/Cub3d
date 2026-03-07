/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_wall_height.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 01:48:09 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/07 00:03:37 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

/**
 * Prevents division by zero and extreme integer overflows.
 *
 * If the player gets too close to a wall, the perpendicular distance
 * approaches zero. Dividing by exactly zero crashes the program, and
 * dividing by a microscopic fraction creates a wall height so massive
 * that it overflows memory limits. Clamping it ensures engine stability.
 *
 * @param ray  The ray whose distance needs to be validated.
 */
static void	protect_zero_distance(t_ray *ray)
{
	if (ray->perp_dist < MIN_DISTANCE)
		ray->perp_dist = MIN_DISTANCE;
}

/**
 * Calculates the top and bottom screen coordinates to draw the wall.
 *
 * A wall is drawn symmetrically from the center of the screen. By
 * adding the player's head tilt and walking bounce, the visual center
 * physically shifts up or down. Subtracting half the wall height from
 * this dynamic center gives the ceiling pixel, and adding it gives the
 * floor pixel, perfectly centering the wall in the player's vision.
 *
 * @param d       Main data structure containing screen dimensions.
 * @param player  Player structure containing head movement offsets.
 * @param ray     The ray structure to store the drawing boundaries.
 */
static void	get_start_end_pixel_wall(t_data *data, t_ray *ray)
{
	int		half_line_height;

	ray->screen_center[Y] = (double)data->img->height / 2.0;
	ray->screen_center[Y] = ray->screen_center[Y] + data->player.head[POS];
	half_line_height = ray->wall_height / 2;
	ray->wall_start = (int)ray->screen_center[Y] - half_line_height;
	ray->wall_end = (int)ray->screen_center[Y] + half_line_height;
}

/**
 * Clamps the drawing boundaries to the physical screen dimensions.
 *
 * When a player is very close to a wall, its calculated top and bottom
 * pixels will extend far beyond the monitor's edges. Attempting to draw
 * outside the image buffer array causes a fatal segmentation fault. This
 * safely caps the coordinates strictly within the visible window limits.
 *
 * @param data  Main structure containing the image buffer height.
 * @param ray   The ray whose drawing boundaries will be clamped.
 */
static void	protect_image_limits(t_data *data, t_ray *ray)
{
	if (ray->wall_start < 0)
		ray->wall_start = 0;
	if (ray->wall_end >= (int)data->img->height)
		ray->wall_end = data->img->height - 1;
}

/**
 * Main orchestrator for vertical wall rendering height calculations.
 *
 * Converts the mathematical perpendicular distance into a physical
 * screen pixel height using inverse proportion. It securely guards
 * against extreme close-up math errors, calculates the exact Y screen
 * coordinates using camera offsets, and clamps them to prevent crashes.
 *
 * @param data  Main program data structure.
 * @param ray   The current ray being processed.
 */
void	calc_wall_height(t_data *data, t_ray *ray)
{
	protect_zero_distance(ray);
	ray->wall_height = (int)(data->img->height / ray->perp_dist);
	get_start_end_pixel_wall(data, ray);
	protect_image_limits(data, ray);
}
