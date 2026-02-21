/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:11:03 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/21 20:25:28 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * Extracts and packs the RGBA color of a specific pixel from texture memory.
 * 1. Flattens the 2D coordinates (X, Y) into a 1D memory index.
 * 2. Multiplies by 4 because MLX42 stores 4 bytes per pixel (R, G, B, A).
 * 3. Uses bitwise shifts to move each byte into its correct position
 * and fuses them with bitwise OR (|) into a single 32-bit integer.
 *
 * @param pixels  Pointer to the raw 1D array of texture pixels.
 * @param tex     Array containing the current X and Y texture coordinates.
 * @param width   The true width of the texture image.
 * @return        A single uint32_t representing the packed color.
 */
uint32_t	get_pixel_color(uint8_t *pixels, int *tex, int width)
{
	uint8_t	*p;

	p = pixels + (tex[Y] * width + tex[X]) * 4;
	return ((uint32_t)p[0] << 24
		| (uint32_t)p[1] << 16
		| (uint32_t)p[2] << 8
		| (uint32_t)p[3]);
}
