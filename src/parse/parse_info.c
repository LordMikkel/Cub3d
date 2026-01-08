/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 23:56:27 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/08 03:32:42 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	parse_info(t_data *data, t_map *map)
{
	int	i;

	i = 0;
	while(map->map_file[i])
	{
		parse_texture(data, map, map->map_file[i]);
		//parse_map(data, map, map->map_file[i]);
		i++;
	}
}
