/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle_background.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:15:38 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/08 16:36:11 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

/**
 * Fills the minimap area with a base background color.
 * Iterates through the entire square bounding box of the minimap UI,
 * but only colors pixels that fall inside the circular radius.
 *
 * @param data     Main data struct containing the image buffer.
 * @param minimap  Minimap struct containing offset and size data.
 */
void	draw_minimap_circle_background(t_data *data, t_mm *minimap)
{
	int	x;
	int	y;

	y = minimap->offset[Y];
	while (y < minimap->offset[Y] + minimap->size[Y])
	{
		x = minimap->offset[X];
		while (x < minimap->offset[X] + minimap->size[X])
		{
			if (is_inside_circle(minimap, x, y))
				fast_put_pixel(data->img, x, y, MINIMAP_BG_COLOR);
			x++;
		}
		y++;
	}
}
