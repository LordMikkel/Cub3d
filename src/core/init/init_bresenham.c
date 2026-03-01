/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bresenham.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 20:28:32 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/01 20:30:38 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

static int	get_abs_diff(int start, int end)
{
	if (end > start)
		return (end - start);
	return (start - end);
}

static int	get_step_direction(int start, int end)
{
	if (start < end)
		return (1);
	return (-1);
}

void	init_bresenham(int *delta, int *step, int *origin, int *end)
{
	delta[X] = get_abs_diff(origin[X], end[X]);
	delta[Y] = -get_abs_diff(origin[Y], end[Y]);
	step[X] = get_step_direction(origin[X], end[X]);
	step[Y] = get_step_direction(origin[Y], end[Y]);
}
