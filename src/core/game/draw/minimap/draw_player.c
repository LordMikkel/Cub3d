/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:55:48 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/01 22:01:51 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

void	draw_minimap_player(t_data *data, t_mm *minimap)
{
	int	top_left[AXIS];

	top_left[X] = minimap->center[X] - minimap->player_center;
	top_left[Y] = minimap->center[Y] - minimap->player_center;
	draw_square(data, top_left, MINIMAP_PLAYER_SIZE, MINIMAP_PLAYER_COLOR);
}
