/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemies_i.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 00:11:18 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/17 20:22:15 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

// static void move_enemy_towards(t_data *data, t_enemy *enemy, double *target)
// {
// 	double	delta[2];
// 	double	dist;
// 	double	step;
// 	double	next_pos[2];

// 	delta[X] = target[X] - enemy->pos[X];
// 	delta[Y] = target[Y] - enemy->pos[Y];
// 	dist = ft_distance();
// 	if (dist < 0.01)
// 		return ;
// 	enemy->dir[X] = delta[X] * dist;
// 	enemy->dir[Y] = delta[Y] * dist;
// 	step = ENEMY_SPEED * mlx_get_time();
// 	next_pos[X] = enemy->pos[X] + (enemy->dir[X] * step);
// 	next_pos[Y] = enemy->pos[Y] + (enemy->dir[Y] * step);
// 	if (!is_wall(data->map.map_grid[(int)enemy->pos[Y]][(int)next_pos[X]]))
// 		enemy->pos[X] = next_pos[X];
// 	if (!is_wall(data->map.map_grid[(int)next_pos[Y]][(int)enemy->pos[X]]))
// 		enemy->pos[Y] = next_pos[Y];
// }

// static bool	can_enemy_hear_player(t_plyr *player, t_enemy *enemy)
// {
// 	double	dx;
// 	double	dy;

// 	if (!player->moving || player->gun.model == CROSSBOW)
// 		return (FALSE);
// 	dx = player->pos[X] - enemy->pos[X];
// 	dy = player->pos[Y] - enemy->pos[Y];
// 	return ((dx * dx + dy * dy) < ENEMY_HEAR_RANGE * ENEMY_HEAR_RANGE);
// }

// static void	update_enemy_state(t_data *data, t_plyr *player, t_enemy *enemy)
// {
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
// 		if (enemy_reached_the_point(enemy))
// 			enemy->mood = ENEMY_IDLE;
// 	}
// }

// void	update_enemies(t_data *data, t_enemy *enemies)
// {
// 	(void)data,
// 	(void)enemies;
// 	int	i;

// 	i = 0;
// 	while (i < data->map.n_enemies)
// 	{
// 		update_enemy_mood(data, &data->player, &enemies[i]);
// 		i++;
// 	}
// }
