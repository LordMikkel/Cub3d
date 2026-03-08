/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemies.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 00:11:18 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/08 22:12:10 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

// static void	update_enemy_state(t_data *data, t_plyr *player, t_enemy *enemy)
// {
// 	double dist[AXIS];

// 	if (enemy->is_dead)
// 		return ;
// 	if (can_enemy_see_player(data, enemy))
// 	{
// 		enemy->last_known_pos[X] = player->pos[X];
// 		enemy->last_known_pos[Y] = player->pos[Y];
// 		enemy->mood = ENEMY_CHASE;
// 	}
// 	else if (can_enemy_hear_player(data, enemy) && enemy->mood == ENEMY_IDLE)
// 	{
// 		enemy->last_known_pos[X] = player->pos[X];
// 		enemy->last_known_pos[Y] = player->pos[Y];
// 		enemy->mood = ENEMY_ALERT;
// 	}
// 	if (enemy->mood == ENEMY_CHASE)
// 		move_enemy_towards(data, enemy, player->pos);
// 	else if (enemy->mood == ENEMY_ALERT)
// 	{
// 		move_enemy_towards(data, enemy, enemy->last_known_pos);
// 		dist[X] = enemy->last_known_pos[X] - enemy->pos[X];
// 		dist[Y] = enemy->last_known_pos[Y] - enemy->pos[Y];
// 		if ((dist[X] * dist[X] + dist[Y] * dist[Y]) < 0.1)
// 			enemy->mood = ENEMY_IDLE;
// 	}
// }

// void	update_enemies(t_data *data, t_enemy *enemies)
// {
// 	int	i;

// 	i = 0;
// 	while (i < data->map.n_enemies)
// 	{
// 		update_enemy_mood(data, &data->player, &enemies[i]);
// 		i++;
// 	}
// }
