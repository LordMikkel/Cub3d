/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:57:02 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/19 21:26:57 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * Safely iterates through all loaded door animation frames and frees them.
 * Specifically interacts with the MLX library to delete the texture buffers
 * and image instances from memory, preventing memory leaks.
 *
 * @param data  Main program struct for the MLX context.
 * @param map   The map struct containing the door array.
 * @param doors The specific door array to clean up.
 */
static void	clean_doors_sprites(t_map *map, t_door *doors)
{
	int	i;
	int	y;

	y = 0;
	while (y < map->n_doors)
	{
		i = 0;
		while (i < DOOR_ANIMATIONS)
		{
			if (doors[y].sprites[i].txtr)
				mlx_delete_texture(doors[y].sprites[i].txtr);
			i++;
		}
		y++;
	}
}

/**
 * Master cleanup function for door entities.
 * Triggers the sprites memory releases and then frees the dynamically
 * allocated array holding the door objects themselves.
 *
 * @param data  Main program struct.
 * @param map   The map struct to be cleaned.
 */
void	clean_doors(t_map *map)
{
	if (!map || !map->doors)
		return ;
	if (map->doors->sprites->txtr)
		clean_doors_sprites(map, map->doors);
	if (map->doors)
		ft_free((void **)&map->doors);
}
