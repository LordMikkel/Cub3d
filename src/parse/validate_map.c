/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 22:06:09 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/26 00:57:47 by migarrid         ###   ########.fr       */
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

static void	close_bounds(t_data *data, char **map, t_p2d max, t_p2d pos, int *n)
{
	if (pos.x < 0 || pos.y < 0 || pos.x > max.x || pos.y > max.y)
		exit_error(data, ERR_MAP_WALLS, EXIT_USE);
	if (map[pos.y][pos.x] == ' ')
		exit_error(data, ERR_MAP_WALLS, EXIT_USE);
	if (map[pos.y][pos.x] == '1' || map[pos.y][pos.x] == 'V')
		return ;
	if (is_enemy(map[pos.y][pos.x]))
		(*n)++;
	map[pos.y][pos.x] = 'V';
	close_bounds(data, map, max, (t_p2d){pos.x + 1, pos.y}, n);
	close_bounds(data, map, max, (t_p2d){pos.x - 1, pos.y}, n);
	close_bounds(data, map, max, (t_p2d){pos.x, pos.y + 1}, n);
	close_bounds(data, map, max, (t_p2d){pos.x, pos.y - 1}, n);
}

void	validate_map(t_data *data, t_map *map)
{
	t_p2d	start;
	t_p2d	limits;
	int		reachable_enemies;

	if (map->n_player != 1)
		exit_error(data, ERR_MAP_PLAYER, EXIT_USE);
	if (map->n_enemy > MAX_ENEMIES)
		exit_error(data, ERR_MAP_PLAYER, EXIT_USE);
	get_limits_map(map);
	get_elements(data, map);
	reachable_enemies = 0;
	map->map_copy = ft_arraydup(map->map_grid);
	if(!map->map_copy)
		exit_error(data, ERR_MALLOC, EXIT_FAILURE);
	start = (t_p2d){map->player.pos[X], map->player.pos[Y]};
	limits = (t_p2d){map->map_limit[X], map->map_limit[Y]};
	close_bounds(data, map->map_copy, limits, start, &reachable_enemies);
	if (reachable_enemies != map->n_enemy)
		exit_error(data, ERR_MAP_RECHABLE, EXIT_USE);
}
