/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:55:48 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/06 21:10:15 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

/**
 * Renders the player indicator exactly in the center of the minimap.
 * Since the map scrolls around the player, the player's icon remains static.
 *
 * @param data     Main data struct.
 * @param minimap  Minimap struct for center coordinates.
 */
void	draw_minimap_player(t_data *data, t_mm *minimap)
{
	int	top_left[AXIS];

	top_left[X] = minimap->center[X] - minimap->player_center;
	top_left[Y] = minimap->center[Y] - minimap->player_center;
	draw_square(data, top_left, MINIMAP_PLAYER_SIZE, MINIMAP_PLAYER_COLOR);
}
