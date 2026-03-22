/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemies_i.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 00:11:18 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 01:35:13 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

void	update_enemies(t_data *data, t_enemy *enemies)
{
	int	i;

	i = 0;
	while (i < data->map.n_enemies)
	{
		update_enemy_state(data, &data->player, &enemies[i]);
		update_enemy_animation(data, &enemies[i]);
		i++;
	}
}
