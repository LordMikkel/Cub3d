/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_print_player_info.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:40:19 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/21 20:54:18 by migarrid         ###   ########.fr       */
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
void	dbg_print_player_pos(t_plyr *player, int *mouse, int fd)
{
	ft_printf_fd(fd, "Mouse: %d, %d", mouse[X], mouse[Y]);
	ft_putstr_fd(" | ", fd);
	ft_printf_fd(fd, "Dir: %f, %f", player->dir[X], player->dir[Y]);
	ft_putstr_fd(" | ", fd);
	ft_printf_fd(fd, "Fov: %f, %f", player->fov[X], player->fov[Y]);
	ft_putstr_fd(" | ", fd);
	ft_printf_fd(fd, "Pos: %f, %f", player->pos[X], player->pos[Y]);
	ft_putstr_fd("\n", fd);
}
