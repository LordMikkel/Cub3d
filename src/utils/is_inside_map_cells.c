/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_inside_map_cells.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:56:34 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/16 23:31:07 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

bool	is_inside_map_cells(t_map *map, int *cell)
{
	if (cell[X] >= 0 && cell[X] < map->map_limit[X] + 1
		&& cell[Y] >= 0 && cell[Y] < map->map_limit[Y] + 1)
		return (TRUE);
	return (FALSE);
}
