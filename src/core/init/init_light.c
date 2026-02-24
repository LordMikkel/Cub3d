/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 02:42:16 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/23 18:39:13 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	init_lightmap(t_data *data, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	map->lightmap_limit[X] = map->map_max_len * LIGHT_RESOLUTION;
	map->lightmap_limit[Y] = map->grid_size * LIGHT_RESOLUTION;
	map->lightmap = alloc(data, map->lightmap_limit[Y], sizeof(double *));
	while (y < map->lightmap_limit[Y])
	{
		x = 0;
		map->lightmap[y] = alloc(data, map->lightmap_limit[X], sizeof(double));
		while (x < map->lightmap_limit[X])
		{
			map->lightmap[y][x] = AMBIENT_LIGHT;
			x++;
		}
		y++;
	}
}

void	init_light_bounds(t_map *map, t_light *light)
{
	int	spread[LIMITS];

	spread[MIN_Y] = (int)(light->pos[Y] - light->radius);
	light->bounds[MIN_Y] = fmax(0, spread[MIN_Y]);
	spread[MAX_Y] = (int)(light->pos[Y] + light->radius);
	light->bounds[MAX_Y] = fmin(map->map_limit[Y], spread[MAX_Y]);
	spread[MIN_X] = (int)(light->pos[X] - light->radius);
	light->bounds[MIN_X] = fmax(0, spread[MIN_X]);
	spread[MAX_X] = (int)(light->pos[X] + light->radius);
	light->bounds[MAX_X] = fmin(map->map_limit[X], spread[MAX_X]);
}

void	init_light(t_data *data, int x, int y, char type)
{
	static int	i = 0;

	(void)type;
	if (!data->map.lights)
		data->map.lights = alloc(data, data->map.n_lights, sizeof(t_light));
	data->map.lights[i].pos[X] = (double)x + PRECISE_CENTER_CELL;
	data->map.lights[i].pos[Y] = (double)y + PRECISE_CENTER_CELL;
	data->map.lights[i].intensity = LIGHT_INTENSITY;
	data->map.lights[i].radius = LIGHT_RADIUS;
	init_light_bounds(&data->map, &data->map.lights[i]);
	i++;
}
