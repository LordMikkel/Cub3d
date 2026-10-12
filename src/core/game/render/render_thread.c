/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 12:00:00 by migarrid          #+#    #+#             */
/*   Updated: 2026/10/12 12:00:00 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * Takes the index of the next section nobody has rendered yet.
 * The counter is atomic, so every section is given to exactly one thread.
 *
 * @param pool  The running thread pool.
 * @return      The section index, or a value >= n_sections when none are left.
 */
static int	take_next_section(t_pool *pool)
{
	return (atomic_fetch_add(&pool->next_section, 1));
}

/**
 * Renders sections of the screen until all of them are taken.
 * Every thread (workers and main) runs this loop, so the threads that
 * get cheap sections just take more: the work stays balanced even when the
 * center of the screen (gun, doors, close walls) costs more.
 * Each section is drawn walls -> enemies -> gun: the sprites use the
 * z-buffer of the section columns, filled just before by the same thread.
 *
 * @param data  Main program structure.
 * @param pool  The running thread pool.
 */
void	render_thread_sections(t_data *data, t_pool *pool)
{
	t_section	*section;
	int		i;

	i = take_next_section(pool);
	while (i < pool->n_sections)
	{
		section = &pool->sections[i];
		render_map(data, section->cols);
		render_enemies(data, data->enemies, section->cols);
		render_gun(data, &data->player.gun, section->area);
		i = take_next_section(pool);
	}
}
