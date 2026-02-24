/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:24:23 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/23 22:52:38 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

void	clean_lights(t_map *map)
{
	if (!map)
		return ;
	if (map->lightmap)
		ft_free_double_matrix(&map->lightmap, map->lightmap_limit[Y]);
	if (map->lights)
		ft_free((void **)&map->lights);
}
