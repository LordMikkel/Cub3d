/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:39:39 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/19 21:27:44 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

/**
 * Releases all texture-related resources.
 * It handles three layers of cleanup per texture: the file path string,
 * the raw PNG data, and the MLX image instance.
 *
 * @param data  The main struct containing the mlx.
 * @param map   The map struct containing the texture array.
 */
void	clean_textures(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < TOTAL_TEXTURE)
	{
		if (map->textures[i].path)
			ft_free((void **)&map->textures[i].path);
		if (map->textures[i].txtr)
			mlx_delete_texture(map->textures[i].txtr);
		i++;
	}
}
