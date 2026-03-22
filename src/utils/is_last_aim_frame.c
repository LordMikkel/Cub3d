/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_last_aim_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 23:29:40 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 17:43:19 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

/**
 * Checks if the aiming animation has reached its final frame.
 * Used to freeze the animation loop so the weapon stays continuously
 * aimed down sights instead of restarting the lifting animation.
 *
 * @param gun  The weapon structure being evaluated.
 * @return     TRUE if strictly on the last frame of the AIM state,
 *             FALSE otherwise.
 */
bool	is_last_aim_frame(t_gun *gun)
{
	if (gun->state == GUN_AIM && gun->current_frame == TOTAL_GUN_AIM_FRAMES - 1)
		return (TRUE);
	return (FALSE);
}
