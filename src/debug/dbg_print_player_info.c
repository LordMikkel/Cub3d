/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_print_player_info.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:40:19 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/19 18:24:53 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/**
 * Prints the current player and mouse state to a file descriptor.
 * Outputs the mouse coordinates, direction vector, FOV plane vector,
 * and world position in a single formatted line. Useful for real-time
 * debugging of player movement and rotation during development.
 *
 * @param player  The player struct containing direction, FOV and position.
 * @param mouse   The current mouse position as a two-element array [X, Y].
 * @param fd      The file descriptor to write to (e.g. STDOUT or STDERR).
 */
void	dbg_print_player_info(t_plyr *player, int *mouse, int fd)
{
	ft_printf_fd(fd, "Mouse: %d, %d | Dir: %f, %f | Fov: %f, %f | Pos: %f, %f\n",
		mouse[X], mouse[Y],
		player->dir[X], player->dir[Y],
		player->fov[X], player->fov[Y],
		player->pos[X], player->pos[Y]);
}
