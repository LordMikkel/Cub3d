/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 02:07:16 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/10 00:59:39 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

static bool	is_valid_grid_chars(char *str, int *player_count)
{
	int	i;

	i = 0;
	if (!str)
		return (FALSE);
	while (str[i])
	{
		if ((str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W'))
			(*player_count)++;
		if (str[i] != '1' && str[i] != '0'
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
		if (!is_valid_grid_chars(line, &map->player_count))
			exit_error(data, ERR_MAP_INVALID, EXIT_USE);
		map->map_grid[i] = ft_strdup(line);
		if (!map->map_grid[i])
			exit_error(data, ERR_MALLOC, EXIT_FAILURE);
		i++;
	}
}
