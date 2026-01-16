/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 02:07:16 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/17 00:06:40 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

static void	put_spaces_in_line_void(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (i < map->map_max_len)
	{
		if (line[i] == '\0' || line[i] == 0)
			line[i] = ' ';
		i++;
	}
}

static bool	is_valid_grid_chars(char *str, int *player_count, int *enemy_count)
{
	int	i;

	i = 0;
	if (!str)
		return (FALSE);
	while (str[i])
	{
		if ((str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W'))
			(*player_count)++;
		else if (str[i] == 'X' || str[i] == 'Y' || str[i] == 'Z')
			(*enemy_count)++;
		else if (str[i] != '1' && str[i] != '0'
			&& str[i] != 'N' && str[i] != 'S'
			&& str[i] != 'E' && str[i] != 'W'
			&& str[i] != ' ' && str[i] != 'X'
			&& str[i] != 'Y' && str[i] != 'Z'
			&& str[i] != 'D')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	parse_map(t_data *data, t_map *map, char *line)
{
	static int	i = 0;

	if (strncmp("1", line, 1) == EQUAL)
	{
		if (!is_valid_grid_chars(line, &map->n_player, &map->n_enemy))
			exit_error(data, ERR_MAP_INVALID, EXIT_USE);
		map->map_grid[i] = ft_strndup(line, map->map_max_len);
		if (!map->map_grid[i])
			exit_error(data, ERR_MALLOC, EXIT_FAILURE);
		put_spaces_in_line_void(map, map->map_grid[i]);
		i++;
	}
	if (strncmp("0", line, 1) == EQUAL)
		exit_error(data, ERR_MAP_WALLS, EXIT_USE);
}
