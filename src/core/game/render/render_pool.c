/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 12:00:00 by migarrid          #+#    #+#             */
/*   Updated: 2026/10/12 12:00:00 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * The routine of every worker thread, alive during the whole game.
 * Each loop is one frame:
 * 1. Waits at frame_start until the main thread starts a frame.
 * 2. Renders sections until there are none left (see render_thread_sections).
 * 3. Waits at frame_end so the main thread knows the frame is complete.
 * When clean_pool sets quit and opens frame_start, the worker returns.
 *
 * @param arg  The main program structure (t_data *).
 * @return     NULL (as required by the pthread standard signature).
 */
void	*pool_worker_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (TRUE)
	{
		pthread_barrier_wait(&data->pool.frame_start);
		if (data->pool.quit)
			break ;
		render_thread_sections(data, &data->pool);
		pthread_barrier_wait(&data->pool.frame_end);
	}
	return (NULL);
}

/**
 * Renders one frame of the 3D scene with the thread pool.
 * 1. Resets the section counter and wakes up the workers (frame_start).
 * 2. The main thread renders sections too instead of waiting idle.
 * 3. Waits at frame_end until every section has been drawn.
 * The barriers also order the memory: what the main thread prepared
 * before frame_start is visible to the workers, and everything they drew
 * is visible to the main thread after frame_end.
 *
 * @param data  Main program structure.
 * @param pool  The running thread pool.
 */
void	pool_render_frame(t_data *data, t_pool *pool)
{
	atomic_store(&pool->next_section, 0);
	pthread_barrier_wait(&pool->frame_start);
	render_thread_sections(data, pool);
	pthread_barrier_wait(&pool->frame_end);
}
