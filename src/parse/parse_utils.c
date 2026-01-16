/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 02:35:25 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/16 01:30:13 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

bool is_duplicated_or_initialized_texture(t_txtr *texture)
{
	if (texture->type != 0)
		return (TRUE);
	return (FALSE);
}

bool is_map_line(char *line)
{
	if (ft_strncmp(line, "1", 1) == EQUAL)
		return (TRUE);
	else if (ft_strncmp(line, "0", 1) == EQUAL)
		return (TRUE);
	else if (ft_strncmp(line, " ", 1) == EQUAL)
		return (TRUE);
	return (FALSE);
}

bool	is_not_an_empty_line(char *line)
{
	if (ft_strlen(line) > 1)
		return (TRUE);
	return (FALSE);
}

int	safe_open(t_data *data, t_map *map, char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == ERROR)
		exit_error(data, ERR_FILE_OPEN, EXIT_FAILURE, map_path);
	map->fd = fd;
	return (fd);
}
