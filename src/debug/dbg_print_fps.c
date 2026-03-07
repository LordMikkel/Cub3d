/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_print_fps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 22:51:22 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/06 23:35:20 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/**
 * Converts POSIX timespec structures into a floating-point second value.
 * Combines seconds and nanoseconds into a single double.
 *
 * @param past     The previous recorded time snapshot.
 * @param present  The current time snapshot.
 * @return         The precise elapsed time in seconds.
 */
static double	get_time_elapsed(struct timespec past, struct timespec present)
{
	double	seconds;
	double	nanoseconds;

	seconds = (double)(present.tv_sec - past.tv_sec);
	nanoseconds = (double)(present.tv_nsec - past.tv_nsec) / 1000000000.0;
	return (seconds + nanoseconds);
}

/**
 * Calculates and prints the application's Frames Per Second (FPS).
 * Uses CLOCK_MONOTONIC to get unaffected system hardware time.
 * Accumulates frames over a 1-second interval before printing to the
 * specified file descriptor, ensuring the output is readable and accurate.
 *
 * @param fd  The file descriptor to print the FPS to (e.g., standard output).
 */
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
