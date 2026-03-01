/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_inside_circle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 22:06:50 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/02 00:19:08 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

bool	is_inside_circle(t_mm *minimap, int point_x, int point_y)
{
	int	dx;
	int	dy;
	int	squared_distance;

	dx = point_x - minimap->center[X];
	dy = point_y - minimap->center[Y];
	squared_distance = (dx * dx) + (dy * dy);
	if (squared_distance <= minimap->radius_sq_px)
		return (TRUE);
	return (FALSE);
}
