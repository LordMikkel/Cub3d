/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_last_aim_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 23:29:40 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/16 23:31:09 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

bool	is_last_aim_frame(t_gun *gun)
{
	if (gun->state == GUN_AIM && gun->current_frame == TOTAL_GUN_AIM_FRAMES - 1)
		return (TRUE);
	return (FALSE);
}
