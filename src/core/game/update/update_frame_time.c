/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_frame_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 12:00:00 by migarrid          #+#    #+#             */
/*   Updated: 2026/10/12 12:00:00 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * Updates the frame timing values once at the beginning of every frame.
 * 1. Caps delta_time to MAX_DELTA_TIME: MLX measures the first frame from
 * glfwInit, so it includes the whole loading time (textures, lightmap...),
 * and a long frame (window drag...) would do the same. Without this cap,
 * enemies and the player would jump several cells in one step, crossing
 * walls or leaving the map.
 * 2. Stores time_factor: how many reference frames the last frame lasted.
 * Movement constants are tuned per frame at REFERENCE_FPS, so they are
 * scaled by this value to make speed independent of the real frame rate
 * (1.0 at REFERENCE_FPS, < 1.0 above it and > 1.0 below it).
 *
 * @param data  The main struct containing the mlx instance.
 */
void	update_frame_time(t_data *data)
{
	if (data->mlx->delta_time > MAX_DELTA_TIME)
		data->mlx->delta_time = MAX_DELTA_TIME;
	data->vars.time_factor = data->mlx->delta_time * REFERENCE_FPS;
}
