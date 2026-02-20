/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 21:45:47 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/19 23:36:05 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Initializes the workload boundaries for a specific thread.
 *
 * Links the thread to the main data and calculates exactly which
 * vertical screen columns it should paint. If it's the last thread,
 * it forces the end point to the screen width to catch any remainder
 * pixels not perfectly divisible by the core count.
 *
 * @param data             Main program structure.
 * @param threads          Array storing all thread structures.
 * @param i                Index of the current thread.
 * @param cols_per_thread  Base number of columns per thread.
 */
void	init_thread(t_data *data, t_thread *threads, int i, int cols_per_thread)
{
	threads[i].data = data;
	threads[i].x[START] = i * cols_per_thread;
	if (i == data->n_cores - 1)
		threads[i].x[END] = data->img->width;
	else
		threads[i].x[END] = (i + 1) * cols_per_thread;
}
