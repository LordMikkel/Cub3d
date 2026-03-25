/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 02:10:58 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/25 02:38:46 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/**
 * Updates the maximum line length found so far.
 * We track this to know the map dimensions for rendering. We also check
 * against a hard limit (MAX_MAP_SIZE) here to stop the program if a
 * map is unreasonably wide, preventing memory issues.
 *
 * @param data  The main struct for error handling.
 * @param map   The map struct to update.
 * @param line  The current line being processed.
 */
static void	get_largest_line_map_len(t_data *data, t_map *map, char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > map->map_max_len)
		map->map_max_len = len;
	if (map->map_max_len >= MAX_MAP_SIZE)
		exit_error(data, ERR_MAP_BIG, EXIT_USE);
}

/**
 * Reads and stores the file content.
 * We trim whitespace immediately to make parsing easier later.
 * Crucially, this function handles the file closure and resets GNL
 * to ensure we don't leave any file descriptors open.
 *
 * @param data  The main struct.
 * @param map   The map struct containing the FD and array to fill.
 * @return      The filled array of strings from the file or NULL on error.
 */
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
			if (is_map_line(map->map_file[i]))
				get_largest_line_map_len(data, map, map->map_file[i]);
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

/**
 * Counts valid lines in the file.
 * We need this count to allocate the exact amount of memory for the
 * map array later. We also enforce minimum and maximum size limits
 * here to reject invalid or empty maps early.
 *
 * @param data  The main struct.
 * @param map   The map struct containing the FD.
 * @return      The total number of valid lines found.
 */
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

/**
 * Orchestrates the file reading process.
 * 1. Open and count lines to allocate the exact memory needed.
 * 2. Re-open and actually read the content into the arrays.
 * This approach avoids complex memory resizing during reading.
 *
 * @param data      The main struct.
 * @param map       The map struct to populate.
 * @param map_path  Path to the .cub file.
 */
void	get_file_info(t_data *data, t_map *map, char *map_path)
{
	map->fd = safe_open(data, map, map_path);
	map->file_size = count_file_size(data, map);
	map->map_file = alloc(data, map->file_size + 1, sizeof(char *));
	map->fd = safe_open(data, map, map_path);
	map->map_file = get_lines(data, map);
}
