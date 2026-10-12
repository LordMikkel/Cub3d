/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 12:00:00 by migarrid          #+#    #+#             */
/*   Updated: 2026/10/12 12:00:00 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * Casts the ray of one screen column and draws everything it hits.
 * 1. Initializes the ray and runs the DDA until it hits a wall or a door.
 * 2. Calculates the distance (saved in the z-buffer for the sprites),
 * the texture coordinates and the height of the wall on screen.
 * 3. Draws the ceiling, the wall and the floor of the column, saves the
 * hit for the minimap and draws the transparent doors on top.
 *
 * @param data  Main program structure.
 * @param x     The screen column to render.
 */
static void	cast_single_ray(t_data *data, int x)
{
	t_ray	ray;

	init_player_ray(data, &data->player, &ray, x);
	perform_dda(&data->map, &ray);
	calc_perp_distance(&data->player, &ray);
	save_z_buffer(&data->map, &ray, x);
	calc_impact_in_wall_x(&data->player, &ray);
	calc_wall_texture_x(data, &ray);
	calc_wall_height(data, &ray);
	calc_wall_texture_y(&ray, ray.texture);
	draw_vertical_line(data, &ray, x);
	save_ray_hit_mm(&data->minimap, &data->player, &ray, x);
	render_transparent_hits(data, &ray, x);
}

/**
 * Renders the map (walls, doors, floor and ceiling) of a thread.
 * Casts one ray per column, only for the [START, END) columns of the
 * thread, which also fills the z-buffer of those columns for the sprites.
 *
 * @param thread  The thread with its range of columns.
 */
void	render_map(t_thread *thread)
{
	int	x;

	x = thread->x[START];
	while (x < thread->x[END])
	{
		cast_single_ray(thread->data, x);
		x++;
	}
}
