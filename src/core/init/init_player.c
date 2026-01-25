/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 04:58:37 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/25 05:53:54 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	init_player(t_map *map, int x, int y, char dir)
{
	if (dir == 'N')
		map->player.direction = N;
	else if (dir == 'E')
		map->player.direction = E;
	else if (dir == 'W')
		map->player.direction = W;
	else if (dir == 'S')
		map->player.direction = S;
	map->player.healt = INIT_PLAYER_HEALTH;
	map->player.damage = INIT_PLAYER_DAMAGE;
	map->player.pos[X] = x;
	map->player.pos[Y] = y;
}
