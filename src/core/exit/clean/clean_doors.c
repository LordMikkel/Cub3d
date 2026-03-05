/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:57:02 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/05 23:14:40 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

static void	clean_doors_sprites(t_data *data, t_map *map, t_door *doors)
{
	int	i;
	int y;

	y = 0;
	while (y < map->n_doors)
	{
		i = 0;
		while (i < DOOR_ANIMATIONS)
		{
			if (doors[y].sprites[i].txtr)
				mlx_delete_texture(doors[y].sprites[i].txtr);
			if (doors[y].sprites[i].img)
				mlx_delete_image(data->mlx, doors[y].sprites[i].img);
			i++;
		}
		y++;
	}
}

void	clean_doors(t_data *data, t_map *map)
{

	if (!map || !data)
		return ;
	if (map->doors->sprites->txtr)
		clean_doors_sprites(data, map, map->doors);
	if (map->doors)
		ft_free((void **)&map->doors);
}
