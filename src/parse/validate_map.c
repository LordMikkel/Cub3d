/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 22:06:09 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/25 06:55:15 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

static void	get_limits_map(t_map *map)
{
	map->map_limit[X] = map->map_max_len - 1;
	map->map_limit[Y] = (int)ft_arraylen(map->map_grid) - 1;
}

static void	get_elements(t_data *data, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map_grid[y])
	{
		x = 0;
		while (map->map_grid[y][x])
		{
			if (is_player(map->map_grid[y][x]))
				init_player(map, x, y, map->map_grid[y][x]);
			else if (is_enemy(map->map_grid[y][x]))
				init_enemy(data, x, y, map->map_grid[y][x]);
			else if (is_door(map->map_grid[y][x]))
			{
				if (!is_valid_door(map, x, y))
					exit_error(data, ERR_MAP_DOOR, EXIT_USE);
			}
			x++;
		}
		y++;
	}
}

static void	close_bounds_flood_fill(char **map, t_pos A, t_pos B, int *n_enemy)
{
	(void)map;
	(void)A;
	(void)B;
	(void)n_enemy;
}

void	validate_map(t_data *data, t_map *map)
{
	if (map->n_player != 1)
		exit_error(data, ERR_MAP_PLAYER, EXIT_USE);
	if (map->n_enemy > MAX_ENEMIES)
		exit_error(data, ERR_MAP_PLAYER, EXIT_USE);
	get_limits_map(map);
	get_elements(data, map);
	close_bounds_flood_fill(map->map_grid, 1, 1, &map->n_enemy);
}
