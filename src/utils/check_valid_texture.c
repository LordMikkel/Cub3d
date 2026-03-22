/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:04:58 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 17:47:51 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

/**
 * Validates that a loaded texture perfectly matches the engine's required
 * dimensions. For unscaled, optimized raycasting, wall textures typically
 * need to be uniform (e.g., exactly 64x64). If a loaded PNG/XPM deviates,
 * it cleanly exits the program rather than causing undefined render behavior.
 *
 * @param data        Main program struct, used to trigger the clean exit.
 * @param txtr        The texture structure containing the loaded MLX data.
 * @param opt_width   The strictly required width (e.g., 64).
 * @param opt_height  The strictly required height (e.g., 64).
 */

void	check_valid_texture(t_data *data, t_txtr *txtr,
		int opt_width, int opt_height)
{
	char	*path;

	path = txtr->path;
	if ((int)txtr->txtr->height != opt_height)
		exit_error(data, ERR_TXTR_SIZE, EXIT_USE, path, opt_width, opt_height);
	if ((int)txtr->txtr->width != opt_width)
		exit_error(data, ERR_TXTR_SIZE, EXIT_USE, path, opt_width, opt_height);
}
