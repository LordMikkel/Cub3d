/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_player_inside_door.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 23:40:28 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/16 23:31:19 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

bool	is_player_inside_door(t_plyr *player, t_door *door)
{
	if ((int)player->pos[X] == (int)door->pos[X]
		&& (int)player->pos[Y] == (int)door->pos[Y])
		return (TRUE);
	return (FALSE);
}
