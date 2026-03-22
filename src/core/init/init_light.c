/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 02:42:16 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 21:40:15 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Allocates and initializes the high-resolution lightmap grid.
 * Instead of mapping 1:1 with the game grid, it multiplies the dimensions
 * by LIGHT_RESOLUTION to allow sub-cell lighting for smoother gradients.
 * Every sub-cell is initialized with a baseline AMBIENT_LIGHT value.
 *
 * @param data  Main program struct.
 * @param map   The map struct to hold the newly created lightmap array.
 */
void	init_lightmap(t_data *data, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	map->lightmap_limit[X] = map->map_max_len * LIGHT_RESOLUTION;
	map->lightmap_limit[Y] = map->grid_size * LIGHT_RESOLUTION;
	map->lightmap = alloc(data, map->lightmap_limit[Y], sizeof(uint8_t *));
	while (y < map->lightmap_limit[Y])
	{
		x = 0;
		map->lightmap[y] = alloc(data, map->lightmap_limit[X], sizeof(uint8_t));
		while (x < map->lightmap_limit[X])
		{
			map->lightmap[y][x] = (uint8_t)(AMBIENT_LIGHT * 255.0);
			x++;
		}
		y++;
	}
}

/**
 * Calculates the bounding box for a specific light source.
 * Instead of checking the whole map against the light, it defines a square
 * boundary based on the light's radius. It also clamps these boundaries
 * using fmax/fmin to ensure they do not exceed the map's physical limits,
 * preventing out-of-bounds memory errors during baking.
 *
 * @param map    The map struct containing the grid limits.
 * @param light  The light struct to calculate bounds for.
 */
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

/**
 * Registers a new static light source into the game map.
 * Converts the integer grid coordinates into precise floating-point center
 * coordinates. Assigns base properties and calculates its area of effect.
 *
 * @param data  Main program struct.
 * @param x     The X grid coordinate where the light is placed.
 * @param y     The Y grid coordinate where the light is placed.
 * @param type  The character identifier (unused here).
 */
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
