/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 05:35:11 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/05 03:00:33 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Prepares the first "jump" of the ray (Y-axis).
 * 1. Step: Decides if we are looking Up (-1) or Down (+1).
 * 2. SideDist: Calculates the distance from the player's exact position
 * to the very first horizontal grid line we will touch.
 *
 * @param player  The player's position.
 * @param ray     The ray struct.
 */
static void	set_y_step_and_side_dist(t_plyr player, t_ray *ray)
{
	double	next_grid_line_y;
	double	distance_to_line_y;

	if (ray->dir[Y] < 0)
	{
		ray->step[Y] = -1;
		next_grid_line_y = ray->pos[Y];
		distance_to_line_y = player.pos[Y] - next_grid_line_y;
	}
	else
	{
		ray->step[Y] = 1;
		next_grid_line_y = ray->pos[Y] + 1.0;
		distance_to_line_y = next_grid_line_y - player.pos[Y];
	}
	ray->side_dist[Y] = distance_to_line_y * ray->delta_dist[Y];
}

/**
 * Prepares the first "jump" of the ray (X-axis).
 * 1. Step: Decides if we are looking Left (-1) or Right (+1).
 * 2. SideDist: Calculates the distance from the player's exact position
 * to the very first vertical grid line we will touch.
 *
 * @param player  The player's position.
 * @param ray     The ray struct.
 */
static void	set_x_step_and_side_dist(t_plyr player, t_ray *ray)
{
	double	next_grid_line_x;
	double	distance_to_line_x;

	if (ray->dir[X] < 0)
	{
		ray->step[X] = -1;
		next_grid_line_x = ray->pos[X];
		distance_to_line_x = player.pos[X] - next_grid_line_x;
	}
	else
	{
		ray->step[X] = 1;
		next_grid_line_x = ray->pos[X] + 1.0;
		distance_to_line_x = next_grid_line_x - player.pos[X];
	}
	ray->side_dist[X] = distance_to_line_x * ray->delta_dist[X];
}

/**
 * Prepares the ray for both dimensions.
 * It acts as a wrapper, triggering the calculations for X and then Y axis.
 * By the end of this function, the ray knows where to start and in which
 * direction to move on the grid.
 *
 * @param player  The player's position.
 * @param ray     The ray struct to update.
 */
static void	init_step_and_side_dist(t_plyr player, t_ray *ray)
{
	set_x_step_and_side_dist(player, ray);
	set_y_step_and_side_dist(player, ray);
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
static void	init_delta_dist(t_ray *ray)
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
 * Sets up the ray for a specific screen column.
 * Think of the screen as a window. This function calculates the angle
 * of the "laser beam" that corresponds to the current pixel column (x)
 * we are trying to draw. It combines where the player is looking with
 * the fov distributed by the offset to find the exact ray direction.
 *
 * @param data    Main struct.
 * @param player  Player info.
 * @param ray     Ray to initialize.
 * @param x       The current vertical strip of the screen (pixel column).
 */
void	init_ray(t_data *data, t_plyr player, t_ray *ray, int x)
{
	double	offset_x;

	*ray = (t_ray){0};
	offset_x = 2 * x / (double)data->img->width - 1.0;
	ray->dir[X] = player.dir[X] + player.fov[X] * offset_x;
	ray->dir[Y] = player.dir[Y] + player.fov[Y] * offset_x;
	ray->pos[X] = (int)player.pos[X];
	ray->pos[Y] = (int)player.pos[Y];
	init_delta_dist(ray);
	init_step_and_side_dist(player, ray);
}
