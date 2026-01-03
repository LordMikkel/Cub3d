/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 20:32:01 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/03 00:20:02 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	game_loop(t_data *data)
{
	mlx_key_hook(data->mlx, &handle_keyboard_inpt, data);
	mlx_cursor_hook(data->mlx, &handle_cursor_inpt, data);
	mlx_mouse_hook(data->mlx, &handle_click_inpt, data);
	mlx_close_hook(data->mlx, &close_x, data);
	mlx_loop(data->mlx);
}
