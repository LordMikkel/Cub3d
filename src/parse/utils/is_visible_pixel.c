/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_visible_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:10:27 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/06 17:15:32 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Determines if a pixel is opaque enough to be rendered.
 * Isolates the alpha channel by applying the bitmask 0x000000FF
 * to a 32-bit RGBA-packed integer (format: 0xRRGGBBAA).
 * A threshold of 10 is used instead of 0 to filter out
 * sub-pixel alpha values introduced by PNG bilinear interpolation,
 * preventing ghost fringe artifacts on transparent texture edges.
 *
 * @param color  32-bit RGBA value (bits [7:0] = alpha channel).
 * @return       TRUE if (color & 0xFF) > 10, FALSE otherwise.
 */
bool	is_visible_pixel(uint32_t color)
{
	if ((color & 0x000000FF) > 10)
		return (TRUE);
	return (FALSE);
}
