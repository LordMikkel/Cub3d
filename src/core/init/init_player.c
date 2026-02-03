/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 04:58:37 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/03 06:20:57 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	init_player(t_map *map, int x, int y, char dir)
{
	if (dir == 'N')
		map->player.spawn_dir = N;
	else if (dir == 'E')
		map->player.spawn_dir = E;
	else if (dir == 'W')
		map->player.spawn_dir = W;
	else if (dir == 'S')
		map->player.spawn_dir = S;
	map->player.health = INIT_PLAYER_HEALTH;
	map->player.damage = INIT_PLAYER_DAMAGE;
	map->player.pos[X] = (double)x + PRECISE_CENTER_CELL;
	map->player.pos[Y] = (double)y + PRECISE_CENTER_CELL;
}
