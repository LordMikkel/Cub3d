/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:24:23 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 21:37:57 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * Safely frees all memory allocated for the lighting system.
 * Iterates through the double-pointer lightmap array and the light entities.
 *
 * @param map  The map structure to clean.
 */
void	clean_lights(t_map *map)
{
	if (!map)
		return ;
	// if (map->lightmap)
		// ft_free_double_matrix(&map->lightmap, map->lightmap_limit[Y]);
	if (map->lights)
		ft_free((void **)&map->lights);
}
