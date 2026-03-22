/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_frame_not_finished.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:16:53 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 17:45:01 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

/**
 * Controls animation pacing by comparing elapsed time against frame duration.
 * Ensures animations run at the correct visual speed independently of the
 * machine's framerate by calculating the delta time since the frame started.
 *
 * @param gun  The weapon structure containing the timer and duration limit.
 * @param now  The current timestamp (usually from mlx_get_time()).
 * @return     TRUE if the frame should still be displayed,
 *             FALSE if it's time to advance.
 */
bool	is_frame_not_finished(t_gun *gun, double now)
{
	double	time_since_last_frame;

	time_since_last_frame = now - gun->frame_timer;
	if (time_since_last_frame < gun->frame_duration)
		return (TRUE);
	return (FALSE);
}
