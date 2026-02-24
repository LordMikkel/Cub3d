/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:16:51 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/23 18:39:05 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

static void	validate_min_feature(t_data *data, t_map *map)
{
	int	i;

	i = 0;
	while (map->map_file[i])
	{
		if (ft_strncmp(map->map_file[i], "NO", 2) == EQUAL)
			map->n_features++;
		else if (ft_strncmp(map->map_file[i], "EA", 2) == EQUAL)
			map->n_features++;
		else if (ft_strncmp(map->map_file[i], "SO", 2) == EQUAL)
			map->n_features++;
		else if (ft_strncmp(map->map_file[i], "WE", 2) == EQUAL)
			map->n_features++;
		else if (ft_strncmp(map->map_file[i], "F", 1) == EQUAL)
			map->n_features++;
		else if (ft_strncmp(map->map_file[i], "C", 1) == EQUAL)
			map->n_features++;
		else if (ft_strncmp(map->map_file[i], "D", 1) == EQUAL)
			map->n_features++;
		else if (ft_strncmp(map->map_file[i], "L", 1) == EQUAL)
			map->n_features++;
		i++;
	}
	if (map->n_features < MIN_MAP_FEATURES)
		exit_error(data, ERR_MAP_MISSING, EXIT_USE);
}

void	init_map_grid(t_data *data, t_map *map)
{
	validate_min_feature(data, map);
	map->grid_size = map->file_size - map->n_features + 1;
	map->map_grid = alloc(data, map->grid_size, sizeof(char *));
}
