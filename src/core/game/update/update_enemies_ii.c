/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemies_ii.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 23:13:12 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 18:49:45 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

void	enemy_death(t_map *map, t_plyr *player, t_enemy *enemy)
{
	enemy->mood = ENEMY_DEATH;
	enemy->is_dead = TRUE;
	map->n_dead_enemies++;
	if (map->n_dead_enemies >= map->n_enemies)
		player->has_won = TRUE;
}

static void	enemy_attack(t_data *data, t_plyr *player, t_enemy *enemy)
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

void	move_enemy_randomly(t_data *data, t_enemy *enemy)
{
	double	new_angle;
	double	next_pos[AXIS];
	double	safe_pos[AXIS];

	next_pos[X] = enemy->pos[X] + (enemy->dir[X] * enemy->step[WALK]);
	next_pos[Y] = enemy->pos[Y] + (enemy->dir[Y] * enemy->step[WALK]);
	safe_pos[X] = next_pos[X] + (enemy->dir[X] * ENEMY_HITBOX);
	safe_pos[Y] = next_pos[Y] + (enemy->dir[Y] * ENEMY_HITBOX);
	if (is_wall(data->map.map_grid[(int)enemy->pos[Y]][(int)(safe_pos[X])])
		|| is_wall(data->map.map_grid[(int)safe_pos[Y]][(int)enemy->pos[X]]))
	{
		new_angle = (rand() % 360) * (PI / 180.0);
		enemy->dir[X] = cos(new_angle);
		enemy->dir[Y] = sin(new_angle);
	}
	else
	{
		enemy->pos[X] = next_pos[X];
		enemy->pos[Y] = next_pos[Y];
	}
}

static void	move_enemy_towards(t_data *data, t_enemy *enemy, double *target)
{
	double	dist_total;
	double	dist[AXIS];
	double	next_pos[AXIS];
	double	safe_pos[AXIS];

	dist_total = ft_dist(enemy->pos[X], enemy->pos[Y], target[X], target[Y]);
	if (dist_total < ENEMY_ATTACK_RANGE)
	{
		enemy_attack(data, &data->player, enemy);
		return ;
	}
	enemy->mood = ENEMY_CHASE;
	enemy->cooldown = 0.0;
	dist[X] = target[X] - enemy->pos[X];
	dist[Y] = target[Y] - enemy->pos[Y];
	enemy->dir[X] = dist[X] / dist_total;
	enemy->dir[Y] = dist[Y] / dist_total;
	next_pos[X] = (enemy->pos[X] + (enemy->dir[X] * enemy->step[CHASE]));
	next_pos[Y] = (enemy->pos[Y] + (enemy->dir[Y] * enemy->step[CHASE]));
	safe_pos[X] = next_pos[X] + (enemy->dir[X] * ENEMY_HITBOX);
	safe_pos[Y] = next_pos[Y] + (enemy->dir[Y] * ENEMY_HITBOX);
	if (!is_wall(data->map.map_grid[(int)enemy->pos[Y]][(int)safe_pos[X]]))
		enemy->pos[X] = next_pos[X];
	if (!is_wall(data->map.map_grid[(int)safe_pos[Y]][(int)enemy->pos[X]]))
		enemy->pos[Y] = next_pos[Y];
}

void	update_enemy_state(t_data *data, t_plyr *player, t_enemy *enemy)
{
	if (enemy->is_dead)
		return ;
	enemy->step[CHASE] = ENEMY_SPEED_CHASE * data->mlx->delta_time;
	enemy->step[WALK] = ENEMY_SPEED_WALK * data->mlx->delta_time;
	if (can_enemy_see_player(data, player, enemy))
	{
		enemy->last_known_pos[X] = player->pos[X];
		enemy->last_known_pos[Y] = player->pos[Y];
		enemy->mood = ENEMY_CHASE;
	}
	else if (can_enemy_hear_player(data, enemy))
	{
		enemy->last_known_pos[X] = player->pos[X];
		enemy->last_known_pos[Y] = player->pos[Y];
		enemy->mood = ENEMY_CHASE;
	}
	else if (enemy->mood == ENEMY_CHASE || enemy->mood == ENEMY_ATTACK)
		enemy->mood = ENEMY_WALK;
	if (enemy->mood == ENEMY_CHASE || enemy->mood == ENEMY_ATTACK)
		move_enemy_towards(data, enemy, player->pos);
	else if (enemy->mood == ENEMY_WALK)
		move_enemy_randomly(data, enemy);
}
