/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_print_gun_state.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 00:09:02 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/17 00:15:37 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	dbg_print_gun_state(t_gun *gun, int fd)
{
	char	*state_str;
	int		frame;

	if (gun->state == GUN_IDLE_A)
		state_str = "GUN_IDLE_A";
	else if (gun->state == GUN_IDLE_E)
		state_str = "GUN_IDLE_E";
	else if (gun->state == GUN_AIM)
		state_str = "GUN_AIM";
	else if (gun->state == GUN_UNAIM)
		state_str = "GUN_UNAIM";
	else if (gun->state == GUN_SHOOT)
		state_str = "GUN_SHOOT";
	else if (gun->state == GUN_MELEE)
		state_str = "GUN_MELEE";
	else if (gun->state == GUN_RELOAD)
		state_str = "GUN_RELOAD";
	else
		state_str = "UNKNOWN";
	frame = gun->current_frame;
	ft_printf_fd(fd, "Gun State: %s | Frame: %d\n", state_str, frame);
}
