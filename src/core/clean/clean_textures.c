/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:39:39 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/11 18:42:13 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	clean_textures(t_data *data, t_map *map)
{
	int	i;

	i = 0;
	while (i < TOTAL_TEXTURE)
	{
		if (map->textures[i].path)
			ft_free((void **)&map->textures[i].path);
		if (map->textures[i].txtr)
			mlx_delete_texture(map->textures[i].txtr);
		if (map->textures[i].img)
			mlx_delete_image(data->mlx, map->textures[i].img);
		i++;
	}
}
