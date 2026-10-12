/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visible_bounds.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 12:00:00 by migarrid          #+#    #+#             */
/*   Updated: 2026/10/12 12:00:00 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

uint32_t	get_pixel_color(uint8_t *pixels, int *tex, int width);

/**
 * Grows the bounds so they contain the pixel at x, y.
 *
 * @param bounds  The [MIN_X, MAX_X, MIN_Y, MAX_Y] box to update.
 * @param x       X coordinate of the visible pixel.
 * @param y       Y coordinate of the visible pixel.
 */
static void	add_pixel_to_bounds(int *bounds, int x, int y)
{
	if (x < bounds[MIN_X])
		bounds[MIN_X] = x;
	if (x > bounds[MAX_X])
		bounds[MAX_X] = x;
	if (y < bounds[MIN_Y])
		bounds[MIN_Y] = y;
	if (y > bounds[MAX_Y])
		bounds[MAX_Y] = y;
}

/**
 * Precalculates the box that contains every visible pixel of a texture.
 * Big sprites like the gun frames are mostly transparent, so drawing only
 * this box instead of the whole texture skips most of the work every frame.
 * It uses the same alpha threshold as is_visible_pixel. A fully transparent
 * texture ends with MIN > MAX, so the drawing loops don't run at all.
 *
 * @param txtr  The loaded texture whose bounds will be stored.
 */
void	init_visible_bounds(t_txtr *txtr)
{
	int	tex[AXIS];

	txtr->bounds[MIN_X] = txtr->txtr->width;
	txtr->bounds[MAX_X] = -1;
	txtr->bounds[MIN_Y] = txtr->txtr->height;
	txtr->bounds[MAX_Y] = -1;
	tex[Y] = 0;
	while (tex[Y] < (int)txtr->txtr->height)
	{
		tex[X] = 0;
		while (tex[X] < (int)txtr->txtr->width)
		{
			if (is_visible_pixel(get_pixel_color(txtr->txtr->pixels, tex,
						txtr->txtr->width)))
				add_pixel_to_bounds(txtr->bounds, tex[X], tex[Y]);
			tex[X]++;
		}
		tex[Y]++;
	}
}
