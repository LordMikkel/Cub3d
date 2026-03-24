/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:51:27 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/24 16:56:11 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Detects the machine's hardware capabilities to optimize rendering.
 *
 * Queries the OS for the number of available processing cores.
 * It caps the maximum threads to avoid performance drops caused by
 * excessive context switching, ensuring the engine runs efficiently.
 *
 * @param data  Main structure where the core count will be saved.
 */
void	init_cores(t_data *data, t_opt *vars)
{
	vars->n_cores = sysconf(_SC_NPROCESSORS_ONLN);
	if (vars->n_cores < 1)
		exit_error(data, ERR_CORES, EXIT_FAILURE);
	if (vars->n_cores > MAX_THREADS)
		vars->n_cores = MAX_THREADS;
}
