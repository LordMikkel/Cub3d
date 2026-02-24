/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 04:26:53 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/23 04:40:48 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Prepares the first "jump" of the light ray (Y-axis).
 * 1. Step: Decides if the light ray travels Up (-1) or Down (+1).
 * 2. SideDist: Calculates the distance from the light's exact position
 * to the very first horizontal grid line it will touch.
 *
 * @param light   The light source struct.
 * @param ray     The ray struct.
 */
static void	set_light_y_step_and_side_dist(t_light *light, t_ray *ray)
{
	double	next_grid_line_y;
	double	distance_to_line_y;

	if (ray->dir[Y] < 0)
	{
		ray->step[Y] = -1;
		next_grid_line_y = ray->pos[Y];
		distance_to_line_y = light->pos[Y] - next_grid_line_y;
	}
	else
	{
		ray->step[Y] = 1;
		next_grid_line_y = ray->pos[Y] + 1.0;
		distance_to_line_y = next_grid_line_y - light->pos[Y];
	}
	ray->side_dist[Y] = distance_to_line_y * ray->delta_dist[Y];
}

/**
 * Prepares the first "jump" of the light ray (X-axis).
 * 1. Step: Decides if the light ray travels Left (-1) or Right (+1).
 * 2. SideDist: Calculates the distance from the light's exact position
 * to the very first vertical grid line it will touch.
 *
 * @param light   The light source struct.
 * @param ray     The ray struct.
 */
static void	set_light_x_step_and_side_dist(t_light *light, t_ray *ray)
{
	double	next_grid_line_x;
	double	distance_to_line_x;

	if (ray->dir[X] < 0)
	{
		ray->step[X] = -1;
		next_grid_line_x = ray->pos[X];
		distance_to_line_x = light->pos[X] - next_grid_line_x;
	}
	else
	{
		ray->step[X] = 1;
		next_grid_line_x = ray->pos[X] + 1.0;
		distance_to_line_x = next_grid_line_x - light->pos[X];
	}
	ray->side_dist[X] = distance_to_line_x * ray->delta_dist[X];
}

/**
 * Prepares the ray for both dimensions.
 * It acts as a wrapper, triggering the calculations for X and then Y axis.
 * By the end of this function, the ray knows where to start and in which
 * direction to move on the grid.
 *
 * @param light   The light source struct.
 * @param ray     The ray struct to update.
 */
static void	init_light_step_and_side_dist(t_light *light, t_ray *ray)
{
	set_light_x_step_and_side_dist(light, ray);
	set_light_y_step_and_side_dist(light, ray);
}

/**
 * Calculates the travel distance for one grid square.
 * If the ray is straight, this distance is short (1.0). If it is diagonal,
 * the ray has to travel further to cross the square.
 * If the ray is perfectly parallel to an axis (direction is 0), it will
 * theoretically NEVER cross a grid line on that axis.
 *
 * @param ray  The ray struct to update.
 */
static void	init_light_delta_dist(t_ray *ray)
{
	if (ray->dir[X] == 0.0)
		ray->delta_dist[X] = MAX_NUMBER;
	else
		ray->delta_dist[X] = fabs(1.0 / ray->dir[X]);
	if (ray->dir[Y] == 0.0)
		ray->delta_dist[Y] = MAX_NUMBER;
	else
		ray->delta_dist[Y] = fabs(1.0 / ray->dir[Y]);
}

/**
 * Sets up the shadow-casting ray (the light ray).
 * Think of this as shooting a laser pointer from the light bulb directly
 * towards the exact spot on the wall we will be drawing. Instead of
 * scanning the screen like the camera ray, this ray has a specific destination.
 * We calculate the direct vector from the light to the target to see if any
 * walls block the path, which would mean the target is in shadow.
 *
 * @param ray     The ray struct to initialize for DDA traversal.
 * @param light   The light source (the starting point of our laser).
 * @param target  The exact 2D map coordinates (the hit point) we want to light.
 */
void	init_light_ray(t_ray *ray, t_light *light, double *target)
{
	*ray = (t_ray){0};
	ray->dir[X] = target[X] - light->pos[X];
	ray->dir[Y] = target[Y] - light->pos[Y];
	ray->pos[X] = (int)light->pos[X];
	ray->pos[Y] = (int)light->pos[Y];
	init_light_delta_dist(ray);
	init_light_step_and_side_dist(light, ray);
}
