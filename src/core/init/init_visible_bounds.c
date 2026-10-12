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
 * Grows the bounds so they contain the visible row span of row y.
 *
 * @param bounds  The [MIN_X, MAX_X, MIN_Y, MAX_Y] box to update.
 * @param span    The [START, END) visible span of the row.
 * @param y       Y coordinate of the row.
 */
static void	add_span_to_bounds(int *bounds, int *span, int y)
{
	if (span[START] >= span[END])
		return ;
	if (span[START] < bounds[MIN_X])
		bounds[MIN_X] = span[START];
	if (span[END] - 1 > bounds[MAX_X])
		bounds[MAX_X] = span[END] - 1;
	if (y < bounds[MIN_Y])
		bounds[MIN_Y] = y;
	if (y > bounds[MAX_Y])
		bounds[MAX_Y] = y;
}

/**
 * Prepares the scan of one texture row.
 * The span starts empty (START == END) and the scan at the first pixel.
 *
 * @param span  The [START, END) span of the row to reset.
 * @param tex   The [X, Y] texture coordinate used to scan the row.
 * @param y     The row to scan.
 */
static void	init_row_scan(int *span, int *tex, int y)
{
	span[START] = 0;
	span[END] = 0;
	tex[X] = 0;
	tex[Y] = y;
}

/**
 * Finds the first and last visible pixel of one texture row.
 * It uses the same alpha threshold as is_visible_pixel.
 * A fully transparent row ends with START == END (nothing to draw).
 *
 * @param txtr  The loaded MLX texture.
 * @param y     The row to scan.
 * @param span  Output [START, END) span of visible pixels in the row.
 */
static void	find_row_span(mlx_texture_t *txtr, int y, int *span)
{
	int	tex[AXIS];

	init_row_scan(span, tex, y);
	while (tex[X] < (int)txtr->width)
	{
		if (is_visible_pixel(get_pixel_color(txtr->pixels, tex, txtr->width)))
		{
			if (span[START] == span[END])
				span[START] = tex[X];
			span[END] = tex[X] + 1;
		}
		tex[X]++;
	}
}

/**
 * Allocates one span per row and starts the bounds as an empty box.
 * MIN starts above any valid pixel and MAX below, so the first visible
 * pixel found sets both and a fully transparent texture keeps MIN > MAX.
 *
 * @param data  Main struct, used to exit cleanly if malloc fails.
 * @param txtr  The loaded texture whose spans and bounds will be reset.
 */
static void	init_empty_bounds(t_data *data, t_txtr *txtr)
{
	txtr->row_span = alloc(data, txtr->txtr->height, sizeof(*txtr->row_span));
	txtr->bounds[MIN_X] = txtr->txtr->width;
	txtr->bounds[MAX_X] = -1;
	txtr->bounds[MIN_Y] = txtr->txtr->height;
	txtr->bounds[MAX_Y] = -1;
}

/**
 * Precalculates where the visible pixels of a texture are.
 * Big sprites like the gun frames are mostly transparent, so we store
 * for every row its [START, END) span of visible pixels, plus the box
 * that contains all of them. Drawing only those spans instead of the
 * whole texture skips most of the work every frame.
 * A fully transparent texture ends with MIN > MAX, so nothing is drawn.
 *
 * @param data  Main struct, used to exit cleanly if malloc fails.
 * @param txtr  The loaded texture whose spans and bounds will be stored.
 */
void	init_visible_bounds(t_data *data, t_txtr *txtr)
{
	int	y;

	init_empty_bounds(data, txtr);
	y = 0;
	while (y < (int)txtr->txtr->height)
	{
		find_row_span(txtr->txtr, y, txtr->row_span[y]);
		add_span_to_bounds(txtr->bounds, txtr->row_span[y], y);
		y++;
	}
}
