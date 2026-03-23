/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_print_enemy_state.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 01:33:12 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/23 01:36:37 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/**
 * A debugging utility that prints the current state and frame of the enemy.
 * Translates internal integer states into human-readable strings and prints
 * the output to the specified file descriptor. Essential for tracing the
 * state machine during animation transitions.
 *
 * @param gun  The weapon structure to inspect.
 * @param fd   The file descriptor to print to (usually STDOUT or STDERR).
 */
void	dbg_print_enemy_state(t_enemy *enemy, int fd)
{
	char	*state_str;
	int		frame;

	if (enemy->mood == ENEMY_WALK)
		state_str = "ENEMY_WALK";
	else if (enemy->mood == ENEMY_CHASE)
		state_str = "ENEMY_CHASE";
	else if (enemy->mood == ENEMY_ATTACK)
		state_str = "ENEMY_ATTACK";
	else if (enemy->mood == ENEMY_DEATH)
		state_str = "ENEMY_DEATH";
	else
		state_str = "UNKNOWN";
	frame = enemy->current_frame;
	ft_printf_fd(fd, "Gun State: %s | Frame: %d\n", state_str, frame);
}
