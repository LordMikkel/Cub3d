/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_interact.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 19:19:47 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/07 00:09:24 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	input_player_interact(t_data *data)
{
	static bool	key_held = FALSE;

	if (mlx_is_key_down(data->mlx, MLX_KEY_E))
		open_close_door(data, &data->map, &key_held);
	if (mlx_is_key_down(data->mlx, MLX_MOUSE_BUTTON_RIGHT))
		aim_gun();
	if (mlx_is_key_down(data->mlx, MLX_MOUSE_BUTTON_LEFT))
		shot_gun();
	if (mlx_is_key_down(data->mlx, MLX_KEY_R))
		reload_gun();
	// if (mlx_is_key_down(data->mlx, MLX_KEY_Q))
	// 	// take_item_in_the_ground();
	else
		key_held = FALSE;
}
