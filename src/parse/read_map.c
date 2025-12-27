/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 02:10:58 by migarrid          #+#    #+#             */
/*   Updated: 2025/12/27 02:40:06 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

static int count_map_size(t_data *data, t_map *map)
{
	char	*line;
	int		size;

	size = 0;
	line = get_next_line(map->fd);
	while (line != NULL)
	{
		size++;
		free(line);
		line = get_next_line(map->fd);
	}
	get_next_line(RESET);
	close(map->fd);
	if (size == 0)
		exit_error(data, ERR_MAP_EMPTY, EXIT_USE);
	if (size >= MAX_MAP_SIZE)
		exit_error(data, ERR_MAP_EMPTY, EXIT_USE);
	return(size);
}

void	read_map_file(t_data *data, t_map *map, char *map_path)
{
	int	size;

	map->fd = safe_open(data, map, map_path);
	size = count_map_size(data, map);
	map->map = ft_calloc(size, sizeof(char *));
	map->fd = safe_open(data, map, map_path);
}
