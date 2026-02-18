/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_height.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 01:48:09 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/18 23:48:25 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

static void	protect_zero_distance(t_ray *ray)
{
	if (ray->perp_dist < MIN_DISTANCE)
		ray->perp_dist = MIN_DISTANCE;
}

static void	define_start_and_end_pixel_wall(t_data *data, t_ray *ray)
{
	int		img_center;
	int		half_line_height;
	double	player_head_pos;

	player_head_pos = data->player.head[TILT] + data->player.head[BOUNCE];
	img_center = (data->img->height / 2) + (int)player_head_pos;
	half_line_height = ray->line_height / 2;
	ray->draw_start = img_center - half_line_height;
	ray->draw_end = img_center + half_line_height;
}

static void	protect_image_limits(t_data *data, t_ray *ray)
{
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= (int)data->img->height)
		ray->draw_end = data->img->height - 1;
}

void	calculate_line_height(t_data *data, t_ray *ray)
{
	protect_zero_distance(ray);
	ray->line_height = (int)(data->img->height / ray->perp_dist);
	define_start_and_end_pixel_wall(data, ray);
	protect_image_limits(data, ray);
}
