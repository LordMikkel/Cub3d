/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 03:47:05 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/06 02:29:24 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

static void	cast_single_ray(t_data *data, int x)
{
	t_ray	ray;

	init_ray(data, data->map.player, &ray, x);
	perform_dda(&data->map, &ray);
	calculate_perp_distance(&data->map.player, &ray);
	calculate_line_height(data, &ray);
	// render_lights();
	// draw_vertical_line(data, &ray);
}

static void	*render_section(void	*arg)
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

static void	render_threads(t_data *data, t_thread *threads, int i)
{
	int	cols_per_thread;

	cols_per_thread = data->img->width / data->n_cores;
	init_thread(data, threads, i, cols_per_thread);
	pthread_create(&threads[i].thread, NULL, render_section, &threads[i]);
}

void	raycast_render(t_data *data)
{
	t_thread	threads[MAX_THREADS];
	int			i;

	i = 0;
	while (i < data->n_cores)
	{
		render_threads(data, threads, i);
		i++;
	}
	i = 0;
	while (i < data->n_cores)
	{
		pthread_join(threads[i].thread, NULL);
		i++;
	}
}
