/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 05:48:38 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/07 02:46:57 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	game_render(void *param)
{
	t_data	*data;

	data = param;
	data->mode = GAME;
	input_player_movement(data);
	raycast_render(data);
}
