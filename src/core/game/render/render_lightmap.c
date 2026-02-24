/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_lightmap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 18:41:21 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/23 19:21:43 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

bool	is_blocked_by_wall(t_map *map, t_ray *ray)
{
	if (is_hit_wall(map, ray))
		return (TRUE);
	return (FALSE);
}

bool	is_unblocked_light_path(t_ray *ray, double *target)
{
	if (ray->pos[X] == (int)target[X] && ray->pos[Y] == (int)target[Y])
		return (TRUE);
	return (FALSE);
}

static bool	is_light_path_blocked(t_map *map, t_light *light, double *target)
{
	t_ray	ray;

	init_light_ray(&ray, light, target);
	while (1)
	{
		if (is_unblocked_light_path(&ray, target))
			return (FALSE);
		if (ray.side_dist[X] < ray.side_dist[Y])
			move_x_side(&ray);
		else
			move_y_side(&ray);
		if (is_blocked_by_wall(map, &ray))
			return (TRUE);
	}
}

static void	calc_light_to_cell(t_map *map, t_light *light, double x, double y)
{
	double	dist;
	double	intensity_received;
	double	target[AXIS];
	int		sub_cell[AXIS];

	if (is_wall(map->map_grid[(int)y][(int)x]))
		return ;
	target[X] = x + (1.0 / (LIGHT_RESOLUTION * 2.0));
	target[Y] = y + (1.0 / (LIGHT_RESOLUTION * 2.0));
	dist = ft_distance(light->pos[X], light->pos[Y], target[X], target[Y]);
	if (dist > light->radius)
		return ;
	if (is_light_path_blocked(map, light, target))
		return ;
	intensity_received = light->intensity / (1.0 + dist * dist * 0.5);
	sub_cell[X] = (int)(x * LIGHT_RESOLUTION);
	sub_cell[Y] = (int)(y * LIGHT_RESOLUTION);
	map->lightmap[sub_cell[Y]][sub_cell[X]] += intensity_received;
	if (map->lightmap[sub_cell[Y]][sub_cell[X]] > 1.0)
		map->lightmap[sub_cell[Y]][sub_cell[X]] = 1.0;
}

static void	bake_single_light(t_data *data, t_light *light)
{
	double	x;
	double	y;
	double	step;

	step = 1.0 / (double)LIGHT_RESOLUTION;
	y = light->bounds[MIN_Y];
	while (y <= light->bounds[MAX_Y])
	{
		x = light->bounds[MIN_X];
		while (x <= light->bounds[MAX_X])
		{
			calc_light_to_cell(&data->map, light, x, y);
			x += step;
		}
		y += step;
	}
}

void	render_lightmap(t_data *data)
{
	int		i;
	t_map	*map;

	i = 0;
	map = &data->map;
	init_lightmap(data, map);
	while (i < map->n_lights)
	{
		bake_single_light(data, &map->lights[i]);
		i++;
	}
	ft_printf_fd(STDOUT, MSG_LIGHTMAP);
}
