/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_pool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 12:00:00 by migarrid          #+#    #+#             */
/*   Updated: 2026/10/12 12:00:00 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * Stops the worker threads and frees the pool.
 * The workers are waiting at frame_start between frames, so we set quit
 * and open that barrier: they see quit, return and can be joined.
 * Skipped if the pool never fully started (error before the game loop).
 *
 * @param pool  The thread pool to stop.
 */
void	clean_pool(t_pool *pool)
{
	int	i;

	if (!pool->is_running)
		return ;
	pool->quit = TRUE;
	pthread_barrier_wait(&pool->frame_start);
	i = 0;
	while (i < pool->n_workers)
	{
		pthread_join(pool->workers[i], NULL);
		i++;
	}
	pthread_barrier_destroy(&pool->frame_start);
	pthread_barrier_destroy(&pool->frame_end);
	pool->is_running = FALSE;
}
