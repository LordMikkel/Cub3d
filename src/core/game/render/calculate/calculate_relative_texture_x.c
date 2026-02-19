/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_relative_texture_x.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:59:52 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/19 17:52:50 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

static bool should_invert_texture(t_ray *ray)
{
	if ((ray->wall_side == WEST || ray->wall_side == EAST) && ray->dir[X] > 0)
		return (TRUE);
	if ((ray->wall_side == NORTH || ray->wall_side == SOUTH) && ray->dir[Y] < 0)
		return (TRUE);
	return (FALSE);
}

static t_txtr *get_texture_for_ray(t_data *data, t_ray *ray)
{
	if (ray->wall_side == NORTH)
		return (&data->map.textures[NORTH]);
	else if (ray->wall_side == SOUTH)
		return (&data->map.textures[SOUTH]);
	else if (ray->wall_side == WEST)
		return (&data->map.textures[WEST]);
	else
		return (&data->map.textures[EAST]);
}

void	calculate_relative_texture_x(t_data *data, t_ray *ray)
{
	t_txtr *ray_text;

	ray_text = get_texture_for_ray(data, ray);
	ray->texture = ray_text;
	ray_text->coord[X] = (int)(ray->wall_x * (double)ray_text->img->width);
	if (should_invert_texture(ray))
		ray_text->coord[X] = ray_text->img->width - ray_text->coord[X] - 1;
}
