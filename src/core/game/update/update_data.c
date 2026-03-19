/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 00:32:56 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/18 00:45:53 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

void	update_data(t_data *data)
{
	update_player(&data->player);
	update_doors(&data->map);
	update_gun(data, &data->player.gun);
	// update_enemies(data, data->enemies);
}
