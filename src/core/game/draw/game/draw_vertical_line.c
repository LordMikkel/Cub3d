/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:00:59 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/01 19:11:20 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

/**
 * Orchestrates the complete rendering of a single vertical screen column.
 *
 * Divides the screen slice into three distinct visual sections. First, it
 * draws the ceiling from the top of the window down to the wall's start.
 * Then, it renders the textured or solid wall block itself. Finally, it
 * fills the remaining pixels from the wall's end down to the screen floor.
 *
 * @param data  Main structure containing the image buffer and map assets.
 * @param ray   The processed ray containing drawing boundaries and textures.
 * @param x     The exact vertical screen column (X-coordinate) being drawn.
 */
void	draw_vertical_line(t_data *data, t_ray *ray, int x)
{
	draw_ceiling(data, ray, &data->map.textures[CEILING], x);
	draw_wall(data, ray, ray->texture, x);
	draw_floor(data, ray, &data->map.textures[FLOOR], x);
}
