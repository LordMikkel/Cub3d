/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 01:05:37 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/07 02:08:45 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Initializes the graphics library (MLX 42).
 * It creates the window and the main image where we will draw the game.
 * We check for errors at each step to ensure the window opens correctly
 * before we start.
 *
 * @param data  The main struct to store the MLX instance and image.
 */
int	init_mlx(t_data *data)
{
	setenv("LD_PRELOAD", "", 1);
	data->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE, TRUE);
	if (!data->mlx)
		return (exit_error(data, ERR_MLX_INIT, EXIT_FAILURE));
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img)
		return (exit_error(data, ERR_MLX_IMG, EXIT_FAILURE));
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) == ERROR)
		return (exit_error(data, ERR_MLX_WIN, EXIT_FAILURE));
	data->img->enabled = true;
	return (SUCCESS);
}
