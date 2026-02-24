/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 02:16:29 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/23 18:58:17 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * Releases the graphics library resources.
 * It follows the necessary cleanup order: deleting the image buffer first,
 * and then terminating the main MLX instance to close the window.
 *
 * @param data  The main struct containing MLX pointers.
 */
void	clean_mlx(t_data *data)
{
	if (!data)
		return ;
	if (data->img && data->mlx)
		mlx_delete_image(data->mlx, data->img);
	if (data->mlx)
		mlx_terminate(data->mlx);
}
