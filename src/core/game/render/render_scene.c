/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 03:47:05 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 16:16:30 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * The routine executed by each individual thread ("worker").
 *
 * 1. Receives its assigned columns and screen area (see init_thread).
 * 2. render_map: casts the rays and draws the walls, doors, floor and
 * ceiling ONLY for those specific columns.
 * 3. render_enemies and render_gun: draw the sprites on top, also only on
 * its columns (the gun is clipped to the thread area).
 * Sprites use the z-buffer of each column, which this same thread has just
 * filled, so no synchronization is needed between threads.
 * By doing this, multiple parts of the screen are drawn simultaneously
 * by different CPU cores.
 *
 * @param arg  A void pointer to the thread's specific data structure.
 * @return     NULL (as required by the pthread standard signature).
 */
static void	*render_section(void *arg)
{
	t_thread	*thread;

	thread = (t_thread *)arg;
	render_map(thread);
	render_enemies(thread->data, thread->data->enemies, thread->x);
	render_gun(thread->data, &thread->data->player.gun, thread->area);
	return (NULL);
}

/**
 * Prepares and launches a single thread to render its portion of the screen.
 *
 * 1. Divides the total screen width by the number of CPU cores
 * to figure out exactly how many vertical columns this thread needs to paint.
 * 2. Initializes the thread's specific boundaries (where to start and stop).
 * 3. Spawns the thread and send them to to work on `render_section`.
 *
 * @param data     Main program structure containing screen and core info.
 * @param threads  The array storing all our thread structures.
 * @param i        The index (ID) of the current thread being launched.
 */
static void	render_threads(t_data *data, t_thread *threads, int i)
{
	int	cols_per_thread;

	cols_per_thread = data->img->width / data->vars.n_cores;
	init_thread(data, threads, i, cols_per_thread);
	pthread_create(&threads[i].thread, NULL, render_section, &threads[i]);
}

/**
 * Renders the whole 3D scene: walls, floor, ceiling, enemies and the gun.
 * Main multithreading orchestrator for the raycasting engine.
 * Instead of drawing the screen column by column on a single processor,
 * it splits the screen into vertical chunks for massive performance gains.
 *
 * 1. The first loop dispatches a thread for each available CPU core.
 * 2. The second loop uses `pthread_join` to force the main program
 * to stop and wait until ALL threads have finished painting their slices.
 * Without this wait, the engine might try to display a half-drawn frame.
 * Before that, the per row floor/ceiling distances are precalculated
 * and the enemies are sorted (read only while the threads run).
 *
 * @param data  Main program structure.
 */
void	render_scene(t_data *data)
{
	t_thread	threads[MAX_THREADS];
	int			i;

	calc_row_distances(data);
	sort_enemies_by_distance(data);
	i = 0;
	while (i < data->vars.n_cores)
	{
		render_threads(data, threads, i);
		i++;
	}
	i = 0;
	while (i < data->vars.n_cores)
	{
		pthread_join(threads[i].thread, NULL);
		i++;
	}
}
