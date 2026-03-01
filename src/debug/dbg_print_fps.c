/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_print_fps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 22:51:22 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/01 22:56:47 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

static double	get_time_elapsed(struct timespec past, struct timespec present)
{
	double	seconds;
	double	nanoseconds;

	seconds = (double)(present.tv_sec - past.tv_sec);
	nanoseconds = (double)(present.tv_nsec - past.tv_nsec) / 1000000000.0;
	return (seconds + nanoseconds);
}

void	dbg_print_fps(int fd)
{
	static struct timespec	last_print_time;
	static int				frame_count;
	struct timespec			current_time;
	double					time_elapsed;

	clock_gettime(CLOCK_MONOTONIC, &current_time);
	if (last_print_time.tv_sec == 0)
	{
		last_print_time = current_time;
		return ;
	}
	frame_count++;
	time_elapsed = get_time_elapsed(last_print_time, current_time);
	if (time_elapsed >= 1.0)
	{
		ft_printf_fd(fd, "FPS: %.1f\n", (double)frame_count / time_elapsed);
		last_print_time = current_time;
		frame_count = 0;
	}
}
