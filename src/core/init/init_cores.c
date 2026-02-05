/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:51:27 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/05 20:53:48 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	init_cores(t_data *data)
{
	data->n_cores = sysconf(_SC_NPROCESSORS_ONLN);
	if (data->n_cores < 1)
		exit_error(data, ERR_CORES, EXIT_FAILURE);
	if (data->n_cores > MAX_THREADS)
		data->n_cores = MAX_THREADS;
}
