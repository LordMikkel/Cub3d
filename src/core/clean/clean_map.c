/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 02:41:26 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/25 06:06:06 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	clean_map(t_data *data, t_map *map)
{
	(void)data;
	if (!data || !map)
		return ;
	if (map->map_file)
		ft_free_str_array(&map->map_file);
	if (map->map_grid)
		ft_free_str_array(&map->map_grid);
	if (map->textures[1].path)
		clean_textures(data, map);
}
