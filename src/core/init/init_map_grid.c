/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:16:51 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/28 04:53:41 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Validates the header configuration of the map file.
 * Scans the raw file lines to count the presence of mandatory identifiers
 * (North, South, East, West textures, Floor/Ceiling colors, Doors, etc.).
 * If the file lacks the minimum required configuration keys, it aborts
 * the program to prevent parsing a malformed or purely visual grid.
 *
 * @param data  Main program structure for error handling.
 * @param map   The map structure containing the raw file array.
 */
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
		i++;
	}
	if (map->n_features < MIN_MAP_FEATURES)
		exit_error(data, ERR_MAP_MISSING, EXIT_USE);
}

/**
 * Allocates memory for the 2D map grid array.
 * First ensures all necessary texture/color configurations are present.
 * Then, it calculates the exact height of the actual map grid by subtracting
 * the number of configuration lines from the total file length, optimizing
 * the memory allocation.
 *
 * @param data  Main program structure.
 * @param map   The map structure to initialize.
 */
void	init_map_grid(t_data *data, t_map *map)
{
	validate_min_feature(data, map);
	map->grid_size = map->file_size - map->n_features + 1;
	map->map_grid = alloc(data, map->grid_size, sizeof(char *));
}
