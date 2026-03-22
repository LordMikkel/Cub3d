/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_wall_texture_x.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:59:52 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 18:48:22 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

/**
 * Maps a door's open state percentage to a specific animation frame index.
 * Divides the opening sequence into 5 distinct frames (0 to 4) based on
 * how far along the opening transition the door is.
 *
 * @param percent  A float between 0.0 (closed) and 1.0 (fully open).
 * @return         The integer index (0-4) of the sprite to render.
 */
int	get_door_frame(double percent)
{
	if (percent >= 0.80)
		return (4);
	if (percent >= 0.60)
		return (3);
	if (percent >= 0.40)
		return (2);
	if (percent >= 0.20)
		return (1);
	return (0);
}

/**
 * Identifies which specific door a ray hit and retrieves its current texture.
 * Iterates through the map's door array to find the exact entity intersected
 * by the ray, then fetches the correct animation sprite based on that door's
 * current open percentage.
 *
 * @param data  Main program struct containing the map and doors.
 * @param ray   The ray that intersected a door block.
 * @return      Pointer to the correct animation texture for the hit door.
 */
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

/**
 * Determines if a wall texture needs to be flipped horizontally.
 * In raycasting, as the screen renders from left to right, the map coordinates
 * might be traversed in reverse depending on the viewing angle.
 * - For East/West walls (hitting the Y axis):
 * If looking West (ray->dir[X] < 0), the screen's left-to-right maps to a
 * decreasing Y coordinate on the grid.
 * - For North/South walls (hitting the X axis):
 * If looking South (ray->dir[Y] > 0), the screen's left-to-right maps to a
 * decreasing X coordinate.
 * If uncorrected, textures on these specific faces would appear mirrored
 *
 * @param ray  The ray containing hit data and direction vectors.
 * @return     TRUE if the texture X coordinate should be inverted,
 *             FALSE otherwise.
 */
static bool	should_invert_texture(t_ray *ray)
{
	if ((ray->wall_side == WEST || ray->wall_side == EAST) && ray->dir[X] < 0)
		return (TRUE);
	if ((ray->wall_side == NORTH || ray->wall_side == SOUTH) && ray->dir[Y] > 0)
		return (TRUE);
	return (FALSE);
}

/**
 * Selects the appropriate texture based on the ray's collision data.
 * Differentiates between doors and standard walls, picking the correct
 * directional texture (North, South, East, West) based on the wall face hit.
 *
 * @param data  Main program struct containing loaded textures.
 * @param ray   The ray containing collision information.
 * @return      Pointer to the texture struct to be used for this ray slice.
 */
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

/**
 * Calculates the exact X pixel coordinate on the texture to draw.
 * Translates the fractional part of the wall hit (e.g., 0.0 to 0.99) into a
 * specific vertical pixel column on the texture map (e.g., 0 to 63 for 64px).
 * * If the texture requires inversion (viewed from a mirroring), it applies
 * an axial symmetry calculation: `width - calculated_x - 1`.
 * The `- 1` is critical to prevent off-by-one buffer overflows (Segfaults),
 * ensuring the maximum index on a 64px texture strictly remains 63, not 64.
 *
 * @param data  Main program struct.
 * @param ray   The ray to calculate the texture X coordinate for.
 */
void	calc_wall_texture_x(t_data *data, t_ray *ray)
{
	t_txtr	*tex;

	tex = get_texture_for_ray(data, ray);
	ray->texture = tex;
	if (ray->texture->format != TEXTURE)
		return ;
	ray->tex[X] = ray->wall[X] * (double)tex->txtr->width;
	if (should_invert_texture(ray))
		ray->tex[X] = tex->txtr->width - ray->tex[X] - 1;
}
