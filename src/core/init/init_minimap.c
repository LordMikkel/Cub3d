/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:58:13 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/01 22:41:34 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	init_minimap(t_mm *minimap)
{
	int diameter;
	int radius_px;

	minimap->cell_size = MINIMAP_CELL_SIZE;
	minimap->radius = MINIMAP_RADIUS;
	diameter = (minimap->radius * 2 + 1) * minimap->cell_size;
	minimap->size[X] = diameter;
	minimap->size[Y] = diameter;
	minimap->offset[X] = WIN_WIDTH - minimap->size[X] - MINIMAP_PADDING;
	minimap->offset[Y] = MINIMAP_PADDING;
	minimap->center[X] = minimap->offset[X] + (minimap->size[X] / 2);
	minimap->center[Y] = minimap->offset[Y] + (minimap->size[Y] / 2);
	minimap->player_center = (MINIMAP_PLAYER_SIZE / 2);
	radius_px = minimap->size[X] / 2;
	minimap->radius_sq_px = radius_px * radius_px;
}
