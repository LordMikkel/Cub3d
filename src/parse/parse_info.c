/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 23:56:27 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/04 22:30:37 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/**
 * Main parsing loop.
 * It iterates through the normalized file lines and dispatches them to
 * the correct handler (texture config or map grid) based on the content.
 *
 * @param data  The main struct.
 * @param map   The map struct containing the file lines.
 */
void	parse_info(t_data *data, t_map *map)
{
	int	i;

	i = 0;
	while (map->map_file[i])
	{
		parse_texture(data, map, map->map_file[i]);
		parse_map(data, map, map->map_file[i]);
		i++;
	}
}
