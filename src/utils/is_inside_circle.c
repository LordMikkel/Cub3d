/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_inside_circle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 22:06:50 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/18 21:51:09 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

/**
 * Determines if a given [X, Y] pixel falls within the minimap's circular area.
 * Uses the Pythagorean theorem to calculate the squared distance from the
 * center. Crucially, it compares squared values to avoid the computationally
 * expensive square root function. This optimization is vital for performance
 * since this check is executed per-pixel during rendering and clipping.
 *
 * @param minimap  The minimap struct containing the center and squared radius.
 * @param point_x  The absolute X coordinate of the pixel to check.
 * @param point_y  The absolute Y coordinate of the pixel to check.
 * @return         TRUE if the point is inside the circle, FALSE otherwise.
 */
bool	is_inside_circle(t_mm *minimap, int point_x, int point_y)
{
	int	dist[AXIS];
	int	squared_distance;

	dist[X] = point_x - minimap->center[X];
	dist[Y] = point_y - minimap->center[Y];
	squared_distance = (dist[X] * dist[X]) + (dist[Y] * dist[Y]);
	if (squared_distance <= minimap->radius_sq_px)
		return (TRUE);
	return (FALSE);
}
