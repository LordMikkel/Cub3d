/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game_over.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:30:46 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 18:47:32 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

void	update_game_over(t_data *data)
{
	if (data->player.is_dead)
		exit_success(data, MSG_LOST, EXIT_SUCCESS);
	else if (data->player.has_won)
		exit_success(data, MSG_WON, EXIT_SUCCESS);
}
