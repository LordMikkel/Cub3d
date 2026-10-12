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
 * Calculates the width of every section from the number of threads.
 * Each thread gets about SECTIONS_PER_THREAD sections: with only one per
 * thread the work can't be balanced, with too many the threads spend
 * more time taking sections than drawing (5 measured best: 32 columns
 * with 12 threads). The width is rounded up to a multiple of
 * CACHE_LINE_PIXELS (16 pixels = 64 bytes), so two threads never write
 * on the same cache line of a row (no false sharing).
 *
 * @param data  Main program structure (image width and cores).
 * @return      The width in columns of every section.
 */
static int	get_section_width(t_data *data)
{
	int	width;

	width = data->img->width / (data->vars.n_cores * SECTIONS_PER_THREAD);
	width = (width + CACHE_LINE_PIXELS - 1) / CACHE_LINE_PIXELS;
	return (ft_max(width, 1) * CACHE_LINE_PIXELS);
}

/**
 * Sets the columns and the screen area of one section.
 * The last section is clamped to the image width.
 *
 * @param data     Main program structure (image size).
 * @param section  The section to initialize.
 * @param start    First screen column of the section.
 * @param width    Width in columns of the section.
 */
static void	init_section(t_data *data, t_section *section, int start,
		int width)
{
	section->cols[START] = start;
	section->cols[END] = ft_min(start + width, (int)data->img->width);
	section->area[MIN_X] = section->cols[START];
	section->area[MAX_X] = section->cols[END] - 1;
	section->area[MIN_Y] = 0;
	section->area[MAX_Y] = (int)data->img->height - 1;
}

/**
 * Splits the screen in vertical sections (see get_section_width).
 * They are computed once: every frame the threads only pick them up.
 *
 * @param data  Main program structure.
 * @param pool  The pool that stores the sections.
 */
static void	init_sections(t_data *data, t_pool *pool)
{
	int	start;
	int	width;

	width = get_section_width(data);
	pool->n_sections = 0;
	start = 0;
	while (start < (int)data->img->width)
	{
		init_section(data, &pool->sections[pool->n_sections], start, width);
		pool->n_sections++;
		start += width;
	}
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
		if (pthread_create(&pool->workers[i], NULL, pool_worker, data) != 0)
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
	if (pthread_barrier_init(&pool->frame_start, NULL, pool->n_workers + 1)
		|| pthread_barrier_init(&pool->frame_end, NULL, pool->n_workers + 1))
		exit_error(data, ERR_THREADS, EXIT_FAILURE);
	init_workers(data, pool);
}
