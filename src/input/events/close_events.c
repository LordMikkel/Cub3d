/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:42:54 by migarrid          #+#    #+#             */
/*   Updated: 2025/12/25 18:51:51 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	close_x(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	exit_success(data, MSG_EXIT, EXIT_SUCCESS);
}

int close_esc(mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		return (YES);
	return (NO);
}
