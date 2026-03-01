/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:24:52 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/01 21:49:08 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

void	draw_minimap(t_data *data, t_mm *minimap)
{
	draw_minimap_circle_background(data, minimap);
	draw_minimap_cells(data, &data->player, minimap);
	draw_minimap_fov(data, &data->player, minimap);
	draw_minimap_player(data, minimap);
}
