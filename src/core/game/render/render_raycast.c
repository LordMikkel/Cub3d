/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 03:47:05 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/07 00:25:37 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

static void	cast_single_ray(t_data *data, int x)
{
	t_ray	ray;

	init_player_ray(data, data->player, &ray, x);
	perform_dda(&data->map, &ray);
	calc_perp_distance(&data->player, &ray);
	calc_impact_in_wall_x(&data->player, &ray);
	calc_wall_texture_x(data, &ray);
	calc_wall_height(data, &ray);
	calc_wall_texture_y(&ray, ray.texture);
	draw_vertical_line(data, &ray, x);
	save_ray_hit_mm(&data->minimap, &data->player, &ray, x);
	render_transparent_hits(data, &ray, x);
}

/**
 * The routine executed by each individual thread ("worker").
 *
 * 1. Receives its assigned start and end X coordinates.
 * 2. Loops through its assigned vertical slice of the screen,
 * casting rays and drawing the walls ONLY for those specific columns.
 * By doing this, multiple parts of the screen are drawn simultaneously
 * by different CPU cores.
 *
 * @param arg  A void pointer to the thread's specific data structure.
 * @return     NULL (as required by the pthread standard signature).
 */
static void	*render_section(void *arg)
{
	t_thread	*thread;
	int			x;

	thread = (t_thread *)arg;
	x = thread->x[START];
	while (x < thread->x[END])
	{
		cast_single_ray(thread->data, x);
		x++;
	}
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
 * Main multithreading orchestrator for the raycasting engine.
 * Instead of drawing the screen column by column on a single processor,
 * it splits the screen into vertical chunks for massive performance gains.
 *
 * 1. The first loop dispatches a thread for each available CPU core.
 * 2. The second loop uses `pthread_join` to force the main program
 * to stop and wait until ALL threads have finished painting their slices.
 * Without this wait, the engine might try to display a half-drawn frame.
 *
 * @param data  Main program structure.
 */
void	render_raycast(t_data *data)
{
	t_thread	threads[MAX_THREADS];
	int			i;

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
