/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square_background.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 21:48:12 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/01 21:48:20 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

static void	clamp_bounds(mlx_image_t *img, int *start, int *end)
{
	if (start[X] < 0)
		start[X] = 0;
	if (start[Y] < 0)
		start[Y] = 0;
	if (end[X] > (int)img->width)
		end[X] = (int)img->width;
	if (end[Y] > (int)img->height)
		end[Y] = (int)img->height;
}

static void	fill_rect(t_data *data, int *start, int *end, uint32_t color)
{
	int	x;
	int	y;

	clamp_bounds(data->img, start, end);
	y = start[Y];
	while (y < end[Y])
	{
		x = start[X];
		while (x < end[X])
		{
			mlx_put_pixel(data->img, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_minimap_background(t_data *data, t_mm *minimap)
{
	int	start[AXIS];
	int	end[AXIS];

	start[X] = minimap->offset[X] - MINIMAP_BORDER;
	start[Y] = minimap->offset[Y] - MINIMAP_BORDER;
	end[X] = minimap->offset[X] + minimap->size[X] + MINIMAP_BORDER;
	end[Y] = minimap->offset[Y] + minimap->size[Y] + MINIMAP_BORDER;
	fill_rect(data, start, end, MINIMAP_BORDER_COLOR);
	start[X] = minimap->offset[X];
	start[Y] = minimap->offset[Y];
	end[X] = minimap->offset[X] + minimap->size[X];
	end[Y] = minimap->offset[Y] + minimap->size[Y];
	fill_rect(data, start, end, MINIMAP_BG_COLOR);
}

