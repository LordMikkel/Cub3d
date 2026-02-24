/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:11:03 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/23 18:41:29 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

/**
 * Extracts and packs the RGBA color of a specific pixel from texture memory.
 * * How the 2D to 1D memory index is calculated (Row-Major Order):
 * - (tex[Y] * width): Skips all the complete rows above our target Y coord.
 * - (+ tex[X])      : Moves forward to the exact X column in the current Y row.
 * - (* 4)           : Multi by 4 because MLX42 stores 4 bytes per pixel (RGBA).
 * * Once the starting byte of the pixel is located, it reads the Red, Green,
 * Blue, and Alpha channels sequentially and packs them into a 32-bit integer
 * using bitwise left shifts (<<) and OR (|).
 *
 * @param pixels  Pointer to the raw 1D array of texture pixels.
 * @param tex     Array containing the current X and Y texture coordinates.
 * @param width   The true width of the texture image in pixels.
 * @return        A single uint32_t representing the packed color (0xRRGGBBAA).
 */
uint32_t	get_pixel_color(uint8_t *pixels, int *tex, int width)
{
	int			index;
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	uint32_t	a;

	index = (tex[Y] * width + tex[X]) * 4;
	r = pixels[index];
	g = pixels[index + 1];
	b = pixels[index + 2];
	a = pixels[index + 3];
	return ((r << 24) | (g << 16) | (b << 8) | a);
}
