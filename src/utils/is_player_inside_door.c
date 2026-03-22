/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_player_inside_door.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 23:40:28 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 17:42:36 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

/**
 * Detects if the player's current position overlaps with a door's grid cell.
 * Truncates the player's floating-point position to integer coordinates to
 * check if they are standing strictly inside the 1x1 map block of the door.
 *
 * @param player  The player structure.
 * @param door    The door structure.
 * @return        TRUE if the player is inside the door block, FALSE otherwise.
 */
bool	is_player_inside_door(t_plyr *player, t_door *door)
{
	if ((int)player->pos[X] == (int)door->pos[X]
		&& (int)player->pos[Y] == (int)door->pos[Y])
		return (TRUE);
	return (FALSE);
}
