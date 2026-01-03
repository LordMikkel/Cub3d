/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 23:03:37 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/02 23:58:36 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	normalize_map_data(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_file[i])
	{
		ft_strcut(map->map_file[i], '\n');
		ft_normalize_spaces(map->map_file[i], ' ');
		i++;
	}
}
