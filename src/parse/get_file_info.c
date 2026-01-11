/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 02:10:58 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/11 17:14:18 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

static bool	is_not_an_empty_line(char *line)
{
	if (ft_strlen(line) > 1)
		return (TRUE);
	return (FALSE);
}

static int	safe_open(t_data *data, t_map *map, char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == ERROR)
		exit_error(data, ERR_FILE_OPEN, EXIT_FAILURE, map_path);
	map->fd = fd;
	return (fd);
}

static char	**get_lines(t_data *data, t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(map->fd);
	while (line != NULL)
	{
		if (is_not_an_empty_line(line))
		{
			map->map_file[i] = ft_strtrim(line, " \t\n\r\v\f");
			if (!map->map_file[i])
			{
				ft_free((void **)&line);
				return (exit_error(data, ERR_MALLOC, EXIT_FAILURE), NULL);
			}
			i++;
		}
		ft_free((void **)&line);
		line = get_next_line(map->fd);
	}
	map->map_file[i] = NULL;
	get_next_line(RESET);
	close(map->fd);
	return (map->map_file);
}

static int	count_file_size(t_data *data, t_map *map)
{
	char	*line;

	line = get_next_line(map->fd);
	while (line != NULL)
	{
		if (is_not_an_empty_line(line))
			map->file_size++;
		ft_free((void **)&line);
		line = get_next_line(map->fd);
	}
	get_next_line(RESET);
	close(map->fd);
	if (map->file_size == 0)
		exit_error(data, ERR_MAP_EMPTY, EXIT_USE);
	if (map->file_size < 9)
		exit_error(data, ERR_MAP_MISSING, EXIT_USE);
	if (map->file_size >= MAX_MAP_SIZE)
		exit_error(data, ERR_MAP_BIG, EXIT_USE);
	return (map->file_size);
}

void	get_file_info(t_data *data, t_map *map, char *map_path)
{
	int	size;

	map->fd = safe_open(data, map, map_path);
	size = count_file_size(data, map);
	map->map_file = allocator(data, size + 1, sizeof(char *));
	map->map_grid = allocator(data, size - 5 + 1, sizeof(char *));
	map->fd = safe_open(data, map, map_path);
	map->map_file = get_lines(data, map);
}
