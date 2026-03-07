/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bresenham.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 20:28:32 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/06 21:31:05 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Calculates the absolute mathematical difference between two coordinates.
 * Ensures the result is always a positive integer, regardless of whether
 * the line is being drawn forwards or backwards.
 *
 * @param start  The starting coordinate.
 * @param end    The target coordinate.
 * @return       The positive distance between the two points.
 */
static int	get_abs_diff(int start, int end)
{
	if (end > start)
		return (end - start);
	return (start - end);
}

/**
 * Determines the plotting direction for Bresenham's line algorithm.
 * If the target is greater than the start, the pixel steps forward (+1).
 * If the target is lesser, it steps backward (-1).
 *
 * @param start  The starting coordinate.
 * @param end    The target coordinate.
 * @return       1 for positive direction, -1 for negative direction.
 */
static int	get_step_direction(int start, int end)
{
	if (start < end)
		return (1);
	return (-1);
}

/**
 * Prepares the structural variables for Bresenham's line algorithm.
 * Calculates the total distance to travel on both axes (delta) and the
 * physical direction the pixels must step (step). Notice that delta Y
 * is negative: this is a standard Bresenham optimization to allow
 * error accumulation with simple addition instead of subtraction.
 *
 * @param delta   Output array to store the absolute distances [X, Y].
 * @param step    Output array to store the directional steps [X, Y].
 * @param origin  The starting [X, Y] pixel coordinates.
 * @param end     The destination [X, Y] pixel coordinates.
 */
void	init_bresenham(int *delta, int *step, int *origin, int *end)
{
	delta[X] = get_abs_diff(origin[X], end[X]);
	delta[Y] = -get_abs_diff(origin[Y], end[Y]);
	step[X] = get_step_direction(origin[X], end[X]);
	step[Y] = get_step_direction(origin[Y], end[Y]);
}
