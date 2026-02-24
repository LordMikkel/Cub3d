/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 20:32:01 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/22 20:31:38 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Registers inputs and starts the game engine.
 * We hook our custom functions to the MLX event system so the game responds
 * to keyboard presses, mouse movements, and clicks. Finally mlx_loop
 * takes over control to run the infinite rendering game cycle.
 *
 * @param data  The main struct.
 */
void	game_loop(t_data *data)
{
	data->mode = MENU;
	ft_printf_fd(STDOUT, MSG_GAME_RUN);
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	mlx_key_hook(data->mlx, &handle_keyboard_inpt, data);
	mlx_cursor_hook(data->mlx, &handle_cursor_inpt, data);
	mlx_mouse_hook(data->mlx, &handle_click_inpt, data);
	mlx_close_hook(data->mlx, &close_x, data);
	mlx_loop_hook(data->mlx, game_render, data);
	mlx_loop(data->mlx);
}
