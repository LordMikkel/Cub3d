/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:24:52 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/07 00:26:44 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * Master function that orchestrates the rendering of the minimap.
 * Draws layers sequentially from bottom to top: background, floor/walls,
 * field of view rays, and finally the player marker on top.
 *
 * @param data     Main data struct.
 * @param minimap  Minimap struct containing all UI data.
 */
void	render_minimap(t_data *data, t_mm *minimap)
{
	draw_minimap_circle_background(data, minimap);
	draw_minimap_cells(data, &data->player, minimap);
	draw_minimap_fov(data, &data->player, minimap);
	draw_minimap_player(data, minimap);
}
