/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 01:05:37 by migarrid          #+#    #+#             */
/*   Updated: 2025/12/25 04:51:59 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE, TRUE);
	if (!data->mlx)
		return (exit_error(data, ERR_MLX_INIT, EXIT_FAILURE));
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img)
		return (exit_error(data, ERR_MLX_IMG, EXIT_FAILURE));
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) == ERROR)
		return (exit_error(data, ERR_MLX_WIN, EXIT_FAILURE));
	return (SUCCESS);
}
