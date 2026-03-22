/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_buffers_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 01:10:12 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 01:20:22 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	save_z_buffer(t_map *map, t_ray *ray, int x)
{
	map->t_buffer[x] = 0.0;
	map->z_buffer[x] = ray->perp_dist;
}

void	save_t_buffer(t_map *map, t_ray *ray, int x)
{
	map->t_buffer[x] = ray->perp_dist;
}
