/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 21:45:47 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/05 21:51:25 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	init_thread(t_data *data, t_thread *threads, int i, int cols_per_thread)
{
	threads[i].data = data;
	threads[i].x[START] = i * cols_per_thread;
	if (i == data->n_cores - 1)
		threads[i].x[END] = data->img->width;
	else
		threads[i].x[END] = (i + 1) * cols_per_thread;
}
