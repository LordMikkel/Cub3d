/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 02:07:16 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/05 03:29:05 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/**
 * Pads the map line with spaces.
 * This ensures the map is stored as a perfect rectangle (matrix) in memory,
 * regardless of the original line length. This simplifies raycasting logic,
 * avoiding out-of-bounds checks when looking at neighbors.
 *
 * @param map   The struct containing max dimensions.
 * @param line  The specific map row to pad.
 */
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
	line[map->map_max_len] = '\0';
}

/**
 * Validates map characters and counts entities.
 * It ensures only valid characters exist and counts
 * players/enemies/lights/doors.This count is needed
 * later to enforce game rules
 *
 * @param str  The map line to check.
 * @param map  Map struct contains the counters for players/enemies/lights
 * @return     TRUE if all chars are valid.
 */
static bool	is_valid_grid_chrs(char *s, t_map *map)
{
	int	i;

	i = 0;
	if (!s)
		return (FALSE);
	while (s[i])
	{
		if (is_player(s[i]))
			map->n_players++;
		else if (is_enemy(s[i]))
			map->n_enemies++;
		else if (is_light(s[i]))
			map->n_lights++;
		else if (is_door(s[i]))
			map->n_doors++;
		else if (!is_valid_element(s[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/**
 * Builds the map grid row by row.
 * We use a static index to track our position in the grid array.
 * Note that at this stage, we only validate that the characters are legal
 * We don't check for closed walls yet; that complex logic
 * is handled later by the specific map validation function.
 *
 * @param data  The main struct.
 * @param map   The map struct to fill.
 * @param line  The current line to process.
 */
void	parse_map(t_data *data, t_map *map, char *line)
{
	static int	i = 0;

	if ((strncmp("1", line, 1) == EQUAL) || (strncmp("0", line, 1) == EQUAL))
	{
		if (!is_valid_grid_chrs(line, map))
			exit_error(data, ERR_MAP_INVALID, EXIT_USE);
		map->map_grid[i] = ft_strndup(line, map->map_max_len);
		if (!map->map_grid[i])
			exit_error(data, ERR_MALLOC, EXIT_FAILURE);
		put_spaces_in_line_void(map, map->map_grid[i]);
		i++;
	}
}
