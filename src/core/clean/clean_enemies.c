/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_enemies.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 06:02:56 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/25 06:12:48 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	clean_enemies(t_data *data, t_map *map)
{
	if (!data || !map)
		return ;
	if (map->enemies)
		ft_free((void **)&map->enemies);
}
