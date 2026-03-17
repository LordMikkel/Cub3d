/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_frame_not_finished.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:16:53 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/16 23:31:01 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

bool	is_frame_not_finished(t_gun *gun, double now)
{
	double	time_since_last_frame;

	time_since_last_frame = now - gun->frame_timer;
	if (time_since_last_frame < gun->frame_duration)
		return (TRUE);
	return (FALSE);
}
