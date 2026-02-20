/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 00:32:56 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/20 00:34:50 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

static void	update_player(t_plyr *player)
{
	player->head[POS] = player->head[TILT] + player->head[BOUNCE];
}

void	update_data(t_data *data)
{
	update_player(&data->player);
}
