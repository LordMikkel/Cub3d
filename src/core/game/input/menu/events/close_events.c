/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:42:54 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/08 14:52:13 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../../inc/cube.h"

/**
 * Callback for the window close button (X).
 * This function is triggered automatically when the user clicks the window's
 * cross. We cast the generic parameter back to our main struct to ensure
 * a clean exit with full memory cleanup.
 *
 * @param param  Generic void pointer (casted to t_data).
 */
void	close_x(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	exit_success(data, MSG_EXIT, EXIT_SUCCESS);
}

/**
 * Detects the exit signal.
 * We specifically check for the PRESS action (ignoring release or repeat)
 * on the Escape key. This ensures the quit command triggers exactly once.
 *
 * @param keydata  The key state struct from MLX.
 * @return         YES if Escape was pressed, otherwise NO.
 */
int	close_esc(mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		return (YES);
	return (NO);
}
