/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_wall_texture_x.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:59:52 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/05 21:29:13 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

int	get_door_frame(double percent)
{
	if (percent == 0)
		return (0);
	if (percent >= 25)
		return (1);
	if (percent >= 50)
		return (2);
	if (percent >= 75)
		return (3);
	if (percent >= 100)
		return (4);
	else
		return (0);
}

static t_txtr	*get_door_texture(t_data *data, t_ray *ray)
{
	t_door	*door;
	int		i;

	i = 0;
	while (i < data->map.n_doors)
	{
		door = &data->map.doors[i];
		if (is_ray_hit_the_door(door, ray))
			return (&door->sprites[get_door_frame(door->open_percent)]);
		i++;
	}
	return (&data->map.textures[DOOR]);
}

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
	if (is_door(data->map.map_grid[ray->pos[Y]][ray->pos[X]]))
		return (get_door_texture(data, ray));
	if (ray->wall_side == NORTH)
		return (&data->map.textures[NORTH]);
	else if (ray->wall_side == SOUTH)
		return (&data->map.textures[SOUTH]);
	else if (ray->wall_side == WEST)
		return (&data->map.textures[WEST]);
	else
		return (&data->map.textures[EAST]);
}

void	calculate_wall_texture_x(t_data *data, t_ray *ray)
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
