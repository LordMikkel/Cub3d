/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_transparent_hits.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:02:00 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/07 00:06:58 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * Overwrites the current ray state with a previously saved transparent hit.
 * This prepares the main raycasting math functions to process distance and
 * textures as if the ray had stopped exactly at this transparent object.
 *
 * @param ray  The current ray to be overwritten.
 * @param hit  The saved hit state to restore.
 */
static void	recover_transparent_hits(t_ray *ray, t_hit *hit)
{
	ray->pos[X] = hit->pos[X];
	ray->pos[Y] = hit->pos[Y];
	ray->wall_side = hit->wall_side;
	ray->wall[X] = hit->wall[X];
	ray->wall[Y] = hit->wall[Y];
}

/**
 * Renders all transparent objects (like open doors) that the ray pierced.
 * Uses the Painter's Algorithm: it loops backwards through the saved hits
 * (from the furthest door to the closest door). By drawing back-to-front,
 * transparent pixels will correctly overlay the solid walls and other
 * deeper objects without breaking the depth illusion.
 *
 * @param data  Main data structure.
 * @param ray   The ray containing the array of transparent hits.
 * @param x     The screen column pixel currently being rendered.
 */
void	render_transparent_hits(t_data *data, t_ray *ray, int x)
{
	int	i;

	i = ray->n_transparent_hits - 1;
	while (i >= 0)
	{
		recover_transparent_hits(ray, &ray->transparent_hits[i]);
		calc_perp_distance(&data->player, ray);
		calc_impact_in_wall_x(&data->player, ray);
		calc_wall_texture_x(data, ray);
		calc_wall_height(data, ray);
		calc_wall_texture_y(ray, ray->texture);
		draw_vertical_line(data, ray, x);
		i--;
	}
}
