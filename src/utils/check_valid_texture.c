/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:04:58 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/18 21:33:29 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	check_valid_texture(t_data *data, t_txtr *txtr, int opt_width, int opt_height)
{
	char	*path;

	path = txtr->path;
	if ((int)txtr->txtr->height != opt_height)
		exit_error(data, ERR_TXTR_SIZE, EXIT_USE, path, opt_width, opt_height);
	if ((int)txtr->txtr->width != opt_width)
		exit_error(data, ERR_TXTR_SIZE, EXIT_USE, path, opt_width, opt_height);
}
