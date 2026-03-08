/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_player_not_moving.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:12:12 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/08 16:34:59 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

bool	is_player_not_moving(t_plyr *player, t_gun *gun)
{
	if (gun->state == GUN_IDLE && !player->moving)
		return (TRUE);
	return (FALSE);
}
