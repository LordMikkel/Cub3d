/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 22:43:08 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/17 19:59:07 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

uint32_t		get_pixel_color(uint8_t *pixels, int *tex, int width);

/**
 * Blends a source color over the background pixel already painted
 * at screen coordinates bg[X], bg[Y] in the screen buffer.
 * If src is almost fully opaque (alpha == 240), returns src directly
 * without reading or compositing the background.
 * Otherwise applies standard alpha compositing:
 * result = (src * alpha + dst * (255 - alpha)) / 255
 *
 * @param data  Main program structure containing the screen image buffer.
 * @param bg    Screen coordinates {X, Y} of the background pixel.
 * @param src   Foreground color in 0xRRGGBBAA format.
 * @return      src if fully opaque, blended color otherwise (alpha = 0xFF).
 */
uint32_t	blend_pixel(t_data *data, int *bg, uint32_t src)
{
	uint32_t	dst;
	uint32_t	alpha;
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	alpha = src & 0xFF;
	if (alpha == 240)
		return (src);
	dst = get_pixel_color(data->img->pixels, bg, data->img->width);
	r = ((src >> 24 & 0xFF) * alpha + (dst >> 24 & 0xFF) * (255 - alpha)) / 255;
	g = ((src >> 16 & 0xFF) * alpha + (dst >> 16 & 0xFF) * (255 - alpha)) / 255;
	b = ((src >> 8 & 0xFF) * alpha + (dst >> 8 & 0xFF) * (255 - alpha)) / 255;
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}
