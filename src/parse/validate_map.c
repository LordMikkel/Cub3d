/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 22:06:09 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/09 06:09:42 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	validate_map(t_data *data, t_map *map)
{
	if (map->player_count != 1)
		exit_error(data, ERR_MAP_PLAYER, EXIT_USE);
}
