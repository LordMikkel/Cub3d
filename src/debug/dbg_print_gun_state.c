/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_print_gun_state.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 00:09:02 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 17:52:42 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/**
 * A debugging utility that prints the current state and frame of the weapon.
 * Translates internal integer states into human-readable strings and prints
 * the output to the specified file descriptor. Essential for tracing the
 * state machine during animation transitions.
 *
 * @param gun  The weapon structure to inspect.
 * @param fd   The file descriptor to print to (usually STDOUT or STDERR).
 */
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
