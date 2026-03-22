/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_behind_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 23:25:31 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 17:46:56 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

/**
 * Skip sprites that are mathematically behind the player's camera plane.
 * After multiplying the sprite's relative position by the inverse camera
 * matrix, the resulting transform[Y] represents the depth. If it's <= 0,
 * the sprite is behind the camera and attempting to render it would cause
 * graphical glitches.
 *
 * @param ren  The sprite rendering data structure.
 * @return     TRUE if the sprite is behind the player, FALSE if it is in front.
 */
bool	is_behind_player(t_sprtren *ren)
{
	if (ren->transform[Y] <= 0)
		return (TRUE);
	return (FALSE);
}
