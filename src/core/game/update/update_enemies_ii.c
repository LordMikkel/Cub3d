/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemies_ii.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 23:13:12 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/20 00:20:16 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

static void	attack_player(t_data *data, t_plyr *player, t_enemy *enemy)
{
	enemy->mood = ENEMY_ATTACK;
	enemy->cooldown += data->mlx->delta_time;
	if (enemy->cooldown >= ENEMY_SEG_FREC_DAMAGE)
	{
		player->health -= enemy->damage;
		enemy->cooldown = 0.0;
		if (player->health <= 0)
			player->is_dead = true;
	}
}

static void	move_enemy_towards(t_data *data, t_enemy *enemy, double *target)
{
	double	step;
	double	dist_total;
	double	dist[AXIS];
	double	next_pos[AXIS];

	dist_total = ft_dist(enemy->pos[X], enemy->pos[Y], target[X], target[Y]);
	if (dist_total < ENEMY_ATTACK_RANGE)
	{
		attack_player(data, &data->player, enemy);
		return ;
	}
	enemy->cooldown = 0.0;
	dist[X] = target[X] - enemy->pos[X];
	dist[Y] = target[Y] - enemy->pos[Y];
	enemy->dir[X] = dist[X] * dist_total;
	enemy->dir[Y] = dist[Y] * dist_total;
	step = ENEMY_SPEED * data->mlx->delta_time;
	next_pos[X] = enemy->pos[X] + (enemy->dir[X] * step);
	next_pos[Y] = enemy->pos[Y] + (enemy->dir[Y] * step);
	if (!is_wall(data->map.map_grid[(int)enemy->pos[Y]][(int)next_pos[X]]))
		enemy->pos[X] = next_pos[X];
	if (!is_wall(data->map.map_grid[(int)next_pos[Y]][(int)enemy->pos[X]]))
		enemy->pos[Y] = next_pos[Y];
}

void	update_enemy_state(t_data *data, t_plyr *player, t_enemy *enemy)
{
	if (enemy->is_dead)
		return ;
	if (can_enemy_see_player(data, player, enemy))
	{
		enemy->last_known_pos[X] = player->pos[X];
		enemy->last_known_pos[Y] = player->pos[Y];
		enemy->mood = ENEMY_CHASE;
	}
	else if (can_enemy_hear_player(data, enemy) && enemy->mood == ENEMY_IDLE)
	{
		enemy->last_known_pos[X] = player->pos[X];
		enemy->last_known_pos[Y] = player->pos[Y];
		enemy->mood = ENEMY_ALERT;
	}
	if (enemy->mood == ENEMY_CHASE)
		move_enemy_towards(data, enemy, player->pos);
	else if (enemy->mood == ENEMY_ALERT)
		move_enemy_towards(data, enemy, enemy->last_known_pos);
}
