/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_lightmap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 18:41:21 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/06 23:53:54 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * Evaluates if a shadow-casting ray has hit a solid obstacle.
 * Used exclusively during the light baking phase to check if a wall or a
 * closed door is blocking the light from reaching a specific target cell.
 * It also allow the ray path through a open door.
 *
 * @param map  The map structure.
 * @param ray  The current shadow ray being cast.
 * @return     TRUE if the light is blocked, FALSE if it can keep traveling.
 */
bool	is_blocked_by_wall_or_door(t_map *map, t_ray *ray)
{
	if (ray->pos[Y] < 0 || ray->pos[Y] >= map->map_limit[Y])
		return (TRUE);
	if (ray->pos[X] < 0 || ray->pos[X] >= map->map_limit[X])
		return (TRUE);
	if (is_wall(map->map_grid[ray->pos[Y]][ray->pos[X]]))
		return (TRUE);
	if (is_door_close(map->map_grid[ray->pos[Y]][ray->pos[X]]))
		return (TRUE);
	return (FALSE);
}

/**
 * Checks if the shadow-casting ray has successfully reached its target.
 * If the ray's current grid position matches the target cell's integer
 * coordinates, it means there were no obstacles in the way.
 * which means that light can light up that area.
 *
 * @param ray     The current shadow ray.
 * @param target  The [X, Y] coordinates of the cell being evaluated for light.
 * @return        TRUE if the target is reached (lit), FALSE otherwise.
 */
bool	is_unblocked_light_path(t_ray *ray, double *target)
{
	if (ray->pos[X] == (int)target[X] && ray->pos[Y] == (int)target[Y])
		return (TRUE);
	return (FALSE);
}

/**
 * Traces a line  from a light source to a target cell to check for shadows.
 * Uses a modified DDA algorithm. It steps towards the target and checks for
 * collisions. If it hits a wall before reaching the target, the target is in
 * shadow. If it reaches the target first, the target receives direct light.
 *
 * @param map     The map structure.
 * @param light   The light source emitting the rays.
 * @param target  The specific cell coordinate trying to receive light.
 * @return        TRUE if in shadow, FALSE if directly illuminated.
 */
static bool	is_light_path_blocked(t_map *map, t_light *light, double *target)
{
	t_ray	ray;

	init_light_ray(&ray, light, target);
	while (42)
	{
		if (is_unblocked_light_path(&ray, target))
			return (FALSE);
		if (ray.side_dist[X] < ray.side_dist[Y])
			move_x_side(&ray);
		else
			move_y_side(&ray);
		if (is_blocked_by_wall_or_door(map, &ray))
			return (TRUE);
	}
}

/**
 * Calculates the exact light intensity a specific sub-cell receives.
 * * 1. Wall Exclusion: Immediately skips walls. In a 2D grid, light cannot
 * illuminate the "inside" of a solid wall block. Wall surface shading
 * is handled later during the 3D raycasting rendering phase.
 * 2. Range Check: Ignores cells strictly outside the light's radius.
 * 3. Line of Sight: Casts a shadow ray. If an obstacle is hit, it skips.
 * 4. Physics Attenuation (Inverse-Square Law Approximation):
 * It calculates the density in that subcell of the sphere light
 * In reality, light spreads as a sphere, so its intensity drops based on
 * the squared distance (1 / r²). We simulate this with the formula:
 * `intensity / (1.0 + (dist * dist) * 0.5)`
 * - `dist * dist`: Represents the squared distance (the r²).
 * - `0.5`: A cinematic dampening factor to make the light fade smoothly.
 * - `1.0 +`: A mathematical safety net. If distance is 0, we divide by 1.
 * * 5. Additive Blending: Adds the computed intensity to whatever light is
 * already there (from other light sources) and caps it at 1.0 (pure white).
 *
 * @param map    The map containing the lightmap array.
 * @param light  The light source being processed.
 * @param x      The X floating-point coordinate of the sub-cell.
 * @param y      The Y floating-point coordinate of the sub-cell.
 */
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

/**
 * Processes a single light and "bakes" (pre-render) it into the lightmap.
 * Iterates only within the light's optimized bounds box, stepping by fractions
 * defined by the LIGHT_RESOLUTION to evaluate every sub-cell in its range.
 *
 * @param data   Main program struct.
 * @param light  The light source to bake.
 */
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

/**
 * The master orchestration function for the pre-rendered lighting system.
 * Initializes the blank lightmap and then iterates through all active lights,
 * layering their emissions onto the map before the game loop even begins.
 *
 * @param data  Main program struct.
 */
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
