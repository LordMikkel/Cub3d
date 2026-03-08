/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:04:58 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/08 04:58:46 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

bool	is_valid_texture(t_data *data, t_txtr *texture, int txt_opt_size)
{
	if ((int)texture->img->width > txt_opt_size)
		exit_error(data, ERR_TXTR_SIZE, EXIT_USE, txt_opt_size, txt_opt_size);
	if ((int)texture->img->height > txt_opt_size)
		exit_error(data, ERR_TXTR_SIZE, EXIT_USE, txt_opt_size, txt_opt_size);
	if (texture->img->width != texture->img->height)
		exit_error(data, WARN_TXTR_FORM, EXIT_USE);
	return (TRUE);
}
