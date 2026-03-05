/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_interact.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 19:19:47 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/05 20:55:18 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	input_player_interact(t_data *data)
{
	static bool	key_held = FALSE;

	if (mlx_is_key_down(data->mlx, MLX_KEY_E))
		open_close_door(data, &data->map, &key_held);
	// if (mlx_is_key_down(data->mlx, MLX_KEY_SPACE))
	// 	// reload_gun();
	// if (mlx_is_key_down(data->mlx, MLX_MOUSE_BUTTON_MIDDLE))
	// 	// take_item_in_the_ground();
	else
		key_held = FALSE;
}
