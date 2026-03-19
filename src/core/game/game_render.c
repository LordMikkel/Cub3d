/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 05:48:38 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/18 00:45:09 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	game_render(void *param)
{
	t_data	*data;

	data = param;
	data->mode = GAME;
	dbg_print_fps(STDOUT);
	render_raycast(data);
	// render_enemies(data);
	render_minimap(data, &data->minimap);
	render_gun(data, &data->player.gun);
	input_player_movement(data);
	input_player_rotation(data);
	input_player_interact(data);
	update_data(data);
}
