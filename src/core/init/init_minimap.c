/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:58:13 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/07 00:08:37 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Records the precise world coordinates of a ray's impact for the minimap.
 * Calculates the exact hit point using vector mathematics:
 * Impact Point = Origin + (Direction * Distance).
 * This data is cached in an array indexed by the screen column, allowing
 * the engine to later draw the Field of View (FOV) cone on the 2D minimap
 * quickly, without needing to run the expensive DDA raycasting algorithm again.
 *
 * @param minimap  The minimap struct where the hit coordinates are saved.
 * @param player   The player struct acting as the origin point (P0).
 * @param ray      The current ray containing direction vector and distance.
 * @param col      The current vertical screen column index (ray index).
 */
void	save_ray_hit_mm(t_mm *minimap, t_plyr *player, t_ray *ray, int col)
{
	minimap->ray_hits[col][X] = player->pos[X] + (ray->dir[X] * ray->perp_dist);
	minimap->ray_hits[col][Y] = player->pos[Y] + (ray->dir[Y] * ray->perp_dist);
}

/**
 * Initializes the structural and spatial properties of the minimap.
 * Defines the radius and calculates the total diameter. Crucially, it sets
 * the position of the minimap on the screen (top-right corner) and establishes
 * the absolute center point where the player will be fixed.
 *
 * @param minimap  The minimap struct to be initialized.
 */
void	init_minimap(t_mm *minimap)
{
	int	diameter;
	int	radius_px;

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
