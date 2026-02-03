/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 05:35:11 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/03 17:09:43 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

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

static void	init_step_and_side_dist(t_plyr player, t_ray *ray)
{
	set_x_step_and_side_dist(player, ray);
	set_y_step_and_side_dist(player, ray);
}

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

void	init_ray(t_data *data, t_plyr player, t_ray *ray, int x)
{
	double	offset_x;

	*ray = (t_ray){0};
	offset_x = 2 * x / (double)data->img->height - 1.0;
	ray->dir[X] = player.dir[X] + player.fov[X] * offset_x;
	ray->dir[Y] = player.dir[Y] + player.fov[Y] * offset_x;
	ray->pos[X] = (int)player.pos[X];
	ray->pos[Y] = (int)player.pos[Y];
	init_delta_dist(ray);
	init_step_and_side_dist(player, ray);
}
