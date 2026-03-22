/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 22:59:27 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 21:50:03 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

/**
 * Modulates a 32-bit RGBA color based on a floating-point light multiplier.
 * Uses bitwise operations to isolate each color channel:
 * -Shifts right (>>) and masks (& 0xFF) to extract Red, Green, Blue, and Alpha.
 * -Multiplies the RGB channels by the brightness (0.0 = black, 1.0 = original).
 * -Repacks the modified channels back into a single 32-bit integer using
 * left shifts (<<) and bitwise OR (|).
 * Includes early-return optimizations for fully lit or completely unlit states.
 *
 * @param data        Main program struct containing light settings.
 * @param color       The original 32-bit RGBA pixel color.
 * @param brightness  The multiplier (0.0 to 1.0) to apply.
 * @return            The dynamically darkened 32-bit pixel color.
 */
uint32_t	apply_light(t_data *data, uint32_t color, uint32_t brightness)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	uint32_t	a;

	if (data->map.n_lights == 0)
		return (color);
	if (brightness >= 252)
		return (color);
	if (brightness <= 2)
		return (color & 0x000000FF);
	r = (color >> 24) & 0xFF;
	g = (color >> 16) & 0xFF;
	b = (color >> 8) & 0xFF;
	a = color & 0xFF;
	r = (r * brightness) >> 8;
	g = (g * brightness) >> 8;
	b = (b * brightness) >> 8;
	return ((r << 24) | (g << 16) | (b << 8) | a);
}
