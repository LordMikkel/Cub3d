/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square_background.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 21:48:12 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/08 16:36:11 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

/**
 * Prevents out-of-bounds memory access during rendering.
 * Modifies the start and end coordinates to ensure they do not exceed
 * the boundaries of the main application window (image buffer).
 *
 * @param img    The main mlx_image_t buffer.
 * @param start  The top-left [X, Y] coordinate to be clamped.
 * @param end    The bottom-right [X, Y] coordinate to be clamped.
 */
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

/**
 * Safely draws a filled rectangle on the screen.
 * Applies coordinate clamping before executing the pixel loop to guarantee
 * no segmentation faults occur if UI elements overlap screen edges.
 *
 * @param data   Main data struct for the image buffer.
 * @param start  Top-left [X, Y] coordinate.
 * @param end    Bottom-right [X, Y] coordinate.
 * @param color  Hex color for the rectangle.
 */
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
			fast_put_pixel(data->img, x, y, color);
			x++;
		}
		y++;
	}
}

/**
 * Draws the outer bounding box and backdrop for the minimap UI.
 * Creates a slightly larger rectangle for a border effect, followed by
 * the inner background layer.
 *
 * @param data     Main data struct.
 * @param minimap  Minimap struct for position and sizing.
 */
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
