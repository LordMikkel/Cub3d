/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sprite_visible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 23:25:34 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 16:15:20 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

bool	is_sprite_visible(t_map *map, t_sprtren *ren, int x)
{
	if (ren->transform[Y] < map->z_buffer[x])
	{
		if (map->t_buffer[x] > 0.0 && ren->transform[Y] > map->t_buffer[x])
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}
