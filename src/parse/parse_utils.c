/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 02:35:25 by migarrid          #+#    #+#             */
/*   Updated: 2025/12/27 02:39:00 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

int safe_open(t_data *data, t_map *map, char *map_path)
{
	int fd;

	fd = open(map_path, O_RDONLY);
	if (fd == ERROR)
		exit_error(data, ERR_FILE_OPEN, EXIT_FAILURE, map_path);
	map->fd = fd;
	return (fd);
}
