/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 01:01:26 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/19 20:51:28 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Establishes a clean starting state.
 * We explicitly zero out the entire struct first. This guarantees safe defaults
 * (NULL pointers and 0 integers) to avoid undefined behavior before
 * loading the graphics subsystem.
 *
 * @param data  The main struct to initialize.
 */
void	init_data(t_data *data)
{
	*data = (t_data){0};
	data->mode = LOAD;
	init_mlx(data);
	init_opt(data, &data->vars);
	init_minimap(&data->minimap);
	init_gun(data, &data->player.gun);
	ft_printf_fd(STDOUT, MSG_INIT);
}
