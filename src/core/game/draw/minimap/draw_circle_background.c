/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle_background.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:15:38 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/01 23:52:50 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

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
				mlx_put_pixel(data->img, x, y, MINIMAP_BG_COLOR);
			x++;
		}
		y++;
	}
}
