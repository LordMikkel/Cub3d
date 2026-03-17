/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements_ii.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:57:17 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/08 23:11:59 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * Checks if the mouse is near the right edge of the window.
 * Used to detect when the mouse is about to leave the window boundaries,
 * so we can reposition it and avoid losing mouse tracking.
 *
 * @param mouse_x  The current X position of the mouse.
 * @param width    The width of the window.
 * @return         TRUE if near the right edge, FALSE otherwise.
 */
static bool	is_near_right_edge(int mouse_x, int width)
{
	if (mouse_x > width - 50)
		return (TRUE);
	return (FALSE);
}

/**
 * Checks if the mouse is near the left edge of the window.
 * Used to detect when the mouse is about to leave the window boundaries,
 * so we can reposition it and avoid losing mouse tracking.
 *
 * @param mouse_x  The current X position of the mouse.
 * @param width    The width of the window.
 * @return         TRUE if near the left edge, FALSE otherwise.
 */
static bool	is_near_left_edge(int mouse_x)
{
	if (mouse_x < 50)
		return (TRUE);
	return (FALSE);
}

/**
 * Recenters the mouse to the previous reference position.
 * This prevents infinite rotation by resetting the mouse
 * to its last known reference point after each frame update.
 *
 * @param data  The main data struct containing the mlx instance.
 * @param prev  The previous mouse reference position to restore.
 */
static void	avoid_infinite_player_rotation(t_data *data, int *prev)
{
	mlx_set_mouse_pos(data->mlx, prev[X], prev[Y]);
}

/**
 * Updates the mouse reference position with an offset.
 * Shifts the reference point slightly away from the edge to allow
 * continuous rotation without the mouse escaping the window.
 *
 * @param data    The main data struct containing the mlx instance.
 * @param prev    The previous reference position to update.
 * @param mouse   The current mouse position.
 * @param offset  The offset to apply (+5 left edge, -5 right edge, 0 center).
 */
static void	update_center(t_data *data, int *prev, int *mouse, int offset)
{
	prev[X] = mouse[X] + offset;
	prev[Y] = mouse[Y];
	avoid_infinite_player_rotation(data, prev);
}

/**
 * Limits player rotation by keeping the mouse inside the window.
 * Detects when the mouse approaches either edge and repositions
 * the reference point to simulate infinite horizontal mouse movement.
 *
 * @param data   The main data struct containing the mlx instance.
 * @param prev   The previous mouse reference position.
 * @param mouse  The current mouse position.
 */
void	limits_player_rotation(t_data *data, int *prev, int *mouse)
{
	if (is_near_right_edge(mouse[X], data->img->width))
		update_center(data, prev, mouse, -5);
	else if (is_near_left_edge(mouse[X]))
		update_center(data, prev, mouse, 5);
	else
		update_center(data, prev, mouse, 0);
}
