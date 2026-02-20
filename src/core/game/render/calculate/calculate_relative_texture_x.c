/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_relative_texture_x.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:59:52 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/19 22:47:36 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

static bool	should_invert_texture(t_ray *ray)
{
	if ((ray->wall_side == WEST || ray->wall_side == EAST) && ray->dir[X] < 0)
		return (TRUE);
	if ((ray->wall_side == NORTH || ray->wall_side == SOUTH) && ray->dir[Y] > 0)
		return (TRUE);
	return (FALSE);
}

static t_txtr	*get_texture_for_ray(t_data *data, t_ray *ray)
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
	t_txtr	*tex;

	tex = get_texture_for_ray(data, ray);
	ray->texture = tex;
	if (ray->texture->format != TEXTURE)
		return ;
	ray->tex[X] = (int)(ray->wall[X] * (double)tex->img->width);
	if (should_invert_texture(ray))
		ray->tex[X] = tex->img->width - ray->tex[X] - 1;
}
