/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemies_i.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 00:11:18 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/18 21:52:24 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

static void move_enemy_towards(t_data *data, t_enemy *enemy, double *target)
{
	double	dist[AXIS];
	double	dist_total;
	double	step;
	double	next_pos[AXIS];

	dist_total= ft_distance(enemy->pos[X], enemy->pos[Y], target[X], target[Y]);
	if (dist_total < ENEMY_ATTACK_RANGE)
	{
		attack_player(data, &data->player, enemy);
		return;
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

bool is_inside_enemy_hear_range(double *delta, double enemy_hear_range_sq)
{
	double	delta_dist_sq;

	delta_dist_sq = delta[X] * delta[X] + delta[Y] - delta[Y];
	if (delta_dist_sq < enemy_hear_range_sq)
		return (TRUE);
	return (FALSE);
}

static bool	can_enemy_hear_player(t_data *data, t_enemy *enemy)
{
	double	delta[AXIS];

	if (!data->player.moving || data->player.gun.model == CROSSBOW)
		return (FALSE);
	delta[X] = data->player.pos[X] - enemy->pos[X];
	delta[Y] = data->player.pos[Y] - enemy->pos[Y];
	return (is_inside_enemy_hear_range(delta, data->vars.enemy_hear_range_sq));
}

static void	update_enemy_state(t_data *data, t_plyr *player, t_enemy *enemy)
{
	if (enemy->is_dead)
		return ;
	// if (can_enemy_see_player(data, enemy))
	// {
	// 	enemy->last_known_pos[X] = player->pos[X];
	// 	enemy->last_known_pos[Y] = player->pos[Y];
	// 	enemy->mood = ENEMY_CHASE;
	// }
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

void	update_enemies(t_data *data, t_enemy *enemies)
{
	int	i;

	i = 0;
	while (i < data->map.n_enemies)
	{
		update_enemy_state(data, &data->player, &enemies[i]);
		i++;
	}
}
