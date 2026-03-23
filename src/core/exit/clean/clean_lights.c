/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:24:23 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 23:08:02 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

void	free_lightmap_matrix(uint8_t ***matrix_ptr, size_t rows)
{
	size_t		i;
	uint8_t		**matrix;

	if (!matrix_ptr)
		return ;
	matrix = *matrix_ptr;
	if (!matrix || rows <= 0)
	{
		ft_free((void **)matrix_ptr);
		return ;
	}
	i = 0;
	while (i < rows)
	{
		if (matrix[i])
			ft_free((void **)&matrix[i]);
		i++;
	}
	ft_free((void **)matrix_ptr);
}

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
	if (map->lightmap)
		free_lightmap_matrix(&map->lightmap, map->lightmap_limit[Y]);
	if (map->lights)
		ft_free((void **)&map->lights);
}
