/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 12:00:00 by migarrid          #+#    #+#             */
/*   Updated: 2026/10/12 12:00:00 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Initializes the two barriers that sync every frame. Both wait for
 * every worker plus the main thread, which also renders.
 *
 * @param data  Main program structure (for exit_error).
 * @param pool  The pool that stores the barriers.
 */
static void	init_barriers(t_data *data, t_pool *pool)
{
	int	n_threads;

	n_threads = pool->n_workers + 1;
	if (pthread_barrier_init(&pool->frame_start, NULL, n_threads) != 0)
		exit_error(data, ERR_THREADS, EXIT_FAILURE);
	if (pthread_barrier_init(&pool->frame_end, NULL, n_threads) != 0)
		exit_error(data, ERR_THREADS, EXIT_FAILURE);
}

/**
 * Launches the worker threads, which wait for the first frame.
 * The pool is only marked as running when every worker started, so
 * clean_pool never waits on a barrier that some worker will not reach
 * (if a creation fails, exit() ends the already created workers).
 *
 * @param data  Main program structure, shared with every worker.
 * @param pool  The pool that stores the workers.
 */
static void	init_workers(t_data *data, t_pool *pool)
{
	int	i;

	i = 0;
	while (i < pool->n_workers)
	{
		if (pthread_create(&pool->workers[i], NULL, pool_worker_routine, data) != 0)
			exit_error(data, ERR_THREADS, EXIT_FAILURE);
		i++;
	}
	pool->is_running = TRUE;
}

/**
 * Creates the thread pool once, at the end of init_data (it needs the
 * image and the number of cores). The workers wait blocked at the first
 * barrier, without using CPU, while the map is parsed and the lightmap
 * baked; if parsing fails, clean_all stops them (see clean_pool).
 * Creating and joining threads every frame cost about 1 ms, so the
 * workers live during the whole game and two barriers sync each frame.
 * The main thread also renders, so there is one worker less than cores
 * and both barriers wait for the workers plus the main thread.
 *
 * @param data  Main program structure.
 * @param pool  The pool to initialize.
 */
void	init_pool(t_data *data, t_pool *pool)
{
	pool->n_workers = data->vars.n_cores - 1;
	pool->quit = FALSE;
	init_sections(data, pool);
	init_barriers(data, pool);
	init_workers(data, pool);
}
