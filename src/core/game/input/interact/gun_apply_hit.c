/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_apply_hit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 19:39:47 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 18:48:08 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

static double	get_dist_sq(t_plyr *player, t_enemy *enemy, double *dist)
{
	dist[X] = enemy->pos[X] - player->pos[X];
	dist[Y] = enemy->pos[Y] - player->pos[Y];
	return ((dist[X]) * (dist[X]) + (dist[Y]) * (dist[Y]));
}

bool	is_in_hit_margin(t_opt *o, t_plyr *player, double *dist, double dist_sq)
{
	double	dot;
	double	dot_sq;
	double	min_hitbox_margin;
	double	shot_dist_sq;

	if (is_enemy_in_the_same_cell(dist_sq))
		return (TRUE);
	dot = ft_dot(dist[X], dist[Y], player->dir[X], player->dir[Y]);
	if (dot <= 0.0)
		return (FALSE);
	dot_sq = dot * dot;
	shot_dist_sq = o->shoot_dist_sq;
	if (dist_sq < shot_dist_sq)
		min_hitbox_margin = 0.99 * dist_sq;
	else
		min_hitbox_margin = 0.6 * dist_sq;
	if (dot_sq > min_hitbox_margin)
		return (TRUE);
	return (FALSE);
}

static bool	is_valid_target(t_data *data, t_enemy *enemy, double max_dist_sq,
		double *dist_sq)
{
	t_plyr	*player;
	double	dist[AXIS];

	if (enemy->is_dead)
		return (FALSE);
	player = &data->player;
	*dist_sq = get_dist_sq(player, enemy, dist);
	if (*dist_sq > max_dist_sq)
		return (FALSE);
	if (!is_in_hit_margin(&data->vars, player, dist, *dist_sq))
		return (FALSE);
	if (!is_line_of_sight_clear(data, sqrt(*dist_sq), player->pos, enemy->pos))
		return (FALSE);
	return (TRUE);
}

static t_enemy	*find_hit_enemy(t_data *data, t_enemy *enemies, int max_dist)
{
	t_enemy	*closest;
	double	dist_sq;
	double	min_dist_sq;
	int		i;

	i = 0;
	closest = NULL;
	min_dist_sq = max_dist * max_dist;
	while (i < data->map.n_enemies)
	{
		if (is_valid_target(data, &enemies[i], min_dist_sq, &dist_sq))
		{
			min_dist_sq = dist_sq;
			closest = &enemies[i];
		}
		i++;
	}
	return (closest);
}

void	gun_apply_hit(t_data *data, t_gun *gun, int damage, double max_dist)
{
	t_enemy	*enemy;

	enemy = find_hit_enemy(data, data->enemies, max_dist);
	if (!enemy)
	{
		gun->last_hit = HIT_NONE;
		return ;
	}
	enemy->health -= damage;
	if (enemy->health < 0)
		enemy_death(&data->map, &data->player, enemy);
	enemy->mood = ENEMY_CHASE;
	gun->last_hit = HIT_DAMAGE;
}
