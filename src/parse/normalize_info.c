/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 23:03:37 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/16 01:28:49 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	normalize_info(t_map *map)
{
	int		i;
	char	*new_line;

	i = 0;
	while (map->map_file[i])
	{
		ft_strnorm_spaces(map->map_file[i], ' ');
		new_line = NULL;
		if (ft_strncmp(map->map_file[i], "NO", 2) == EQUAL)
			new_line = ft_strnorm_multi(map->map_file[i], " \t\n\r\v\f", ' ');
		else if (ft_strncmp(map->map_file[i], "EA", 2) == EQUAL)
			new_line = ft_strnorm_multi(map->map_file[i], " \t\n\r\v\f", ' ');
		else if (ft_strncmp(map->map_file[i], "SO", 2) == EQUAL)
			new_line = ft_strnorm_multi(map->map_file[i], " \t\n\r\v\f", ' ');
		else if (ft_strncmp(map->map_file[i], "WE", 2) == EQUAL)
			new_line = ft_strnorm_multi(map->map_file[i], " \t\n\r\v\f", ' ');
		else if (ft_strncmp(map->map_file[i], "F", 1) == EQUAL)
			new_line = ft_strnorm_multi(map->map_file[i], " \t\n\r\v\f", ' ');
		else if (ft_strncmp(map->map_file[i], "C", 1) == EQUAL)
			new_line = ft_strnorm_multi(map->map_file[i], " \t\n\r\v\f", ' ');
		if (new_line)
			ft_str_replace(&map->map_file[i], new_line);
		i++;
	}
}
