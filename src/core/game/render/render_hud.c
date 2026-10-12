/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:24:52 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 18:09:37 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * Master function that orchestrates the rendering of the HUD.
 * Drawn by the main thread after the 3D scene, so it is always on top.
 * Draws layers sequentially from bottom to top: minimap background,
 * floor/walls, field of view rays, enemies, the player marker and
 * finally the health bar.
 *
 * @param data     Main data struct.
 * @param minimap  Minimap struct containing all UI data.
 */
void	render_hud(t_data *data, t_mm *minimap)
{
	draw_minimap_circle_background(data, minimap);
	draw_minimap_cells(data, &data->player, minimap);
	draw_minimap_fov(data, &data->player, minimap);
	draw_minimap_enemies(data, &data->player, minimap);
	draw_minimap_player(data, minimap);
	draw_minimap_health(data, &data->player);
}
