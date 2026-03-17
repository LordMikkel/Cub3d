/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aim_gun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 19:20:33 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/16 23:23:00 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

void	aim_gun(t_gun *gun)
{
	if (gun->state == GUN_IDLE_A)
	{
		gun->state = GUN_AIM;
		gun->current_frame = 0;
	}
}

void	unaim_gun(t_gun *gun)
{
	if (gun->state == GUN_AIM)
	{
		gun->state = GUN_UNAIM;
		gun->anim_done = FALSE;
	}
}
