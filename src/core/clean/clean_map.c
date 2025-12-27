/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 02:41:26 by migarrid          #+#    #+#             */
/*   Updated: 2025/12/27 02:44:52 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	clean_map(t_data *data, t_map *map)
{
	(void)data;
	if (!map)
		return ;
	if (map->map)
		ft_free_str_array(&map->map);
}
