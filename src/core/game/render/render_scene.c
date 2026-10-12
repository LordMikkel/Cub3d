/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 03:47:05 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 16:16:30 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * Renders the whole 3D scene: walls, floor, ceiling, enemies and the gun.
 * 1. Precalculates what every section only reads: the floor/ceiling distance
 * of each row and the enemies sorted by distance.
 * 2. Renders the frame in parallel with the thread pool (see
 * pool_render_frame and render_thread_sections).
 *
 * @param data  Main program structure.
 */
void	render_scene(t_data *data)
{
	calc_row_distances(data);
	sort_enemies_by_distance(data);
	pool_render_frame(data, &data->pool);
}
