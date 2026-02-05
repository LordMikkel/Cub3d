/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 23:56:36 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/05 02:14:08 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Distinguishes map content from configuration lines.
 * Lines starting with walls ('1'), spaces (' '), or empty spots ('0')
 * are treated as the beginning of the grid.
 *
 * @param line  The line string to analyze.
 * @return      TRUE if the line belongs to the map grid.
 */
bool	is_map_line(char *line)
{
	if (ft_strncmp(line, "1", 1) == EQUAL)
		return (TRUE);
	else if (ft_strncmp(line, "0", 1) == EQUAL)
		return (TRUE);
	else if (ft_strncmp(line, " ", 1) == EQUAL)
		return (TRUE);
	return (FALSE);
}

/**
 * Filters out empty or whitespace-only lines.
 * Useful to skip gaps in the configuration file.
 *
 * @param line  The line to check.
 * @return      TRUE if the line contains data.
 */
bool	is_not_an_empty_line(char *line)
{
	if (ft_strlen(line) > 1)
		return (TRUE);
	return (FALSE);
}

/**
 * Checks if a texture slot is already assigned.
 * Prevents the parser from overwriting an existing configuration
 * if the file has duplicate identifiers.
 *
 * @param texture  The texture struct to check.
 * @return         TRUE if the slot is already in use.
 */
bool	is_duplicated_or_initialized_texture(t_txtr *texture)
{
	if (texture->type != 0)
		return (TRUE);
	return (FALSE);
}

/**
 * Opens a file with immediate error handling.
 * If the file cannot be opened (read-only), the program exits cleanly
 * to prevent using an invalid file descriptor.
 *
 * @param data      Main struct for error management.
 * @param map       Map struct to store the FD.
 * @param map_path  Path to the file.
 * @return          The valid file descriptor.
 */
int	safe_open(t_data *data, t_map *map, char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == ERROR)
		exit_error(data, ERR_FILE_OPEN, EXIT_FAILURE, map_path);
	map->fd = fd;
	return (fd);
}
