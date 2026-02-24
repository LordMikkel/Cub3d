/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:04:58 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/23 19:17:22 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	is_valid_texture(t_txtr *texture)
{
	if (texture->img->width > TXTR_MAX_SIZE)
		ft_printf_fd(STDERR, WARN_TXTR_SIZE, TXTR_MAX_SIZE, TXTR_MAX_SIZE);
	if (texture->img->height > TXTR_MAX_SIZE)
		ft_printf_fd(STDERR, WARN_TXTR_SIZE, TXTR_MAX_SIZE, TXTR_MAX_SIZE);
	if (texture->img->height != texture->img->height)
		ft_printf_fd(STDERR, WARN_TXTR_FORM);
}
