/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_apply_hit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 19:39:47 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/20 00:22:23 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

static double	get_dist_sq(t_plyr *player, t_enemy *enemy, double *dist)
{
	dist[X] = enemy->pos[X] - player->pos[X];
	dist[Y] = enemy->pos[Y] - player->pos[Y];
	return ((dist[X]) * (dist[X]) + (dist[Y]) * (dist[Y]));
}

static bool	is_in_hit_margin(t_plyr *player, double *dist, double dist_sq)
{
	double	dot;

	dot = ft_dot_product(dist[X], dist[Y], player->dir[X], player->dir[Y]);
	if (dot > 0.0 && (dot * dot) > (0.9025 * dist_sq))
		return (TRUE);
	return (FALSE);
}

static bool	is_valid_target(t_plyr *player, t_enemy *enemy, double max_dist_sq,
		double *dist_sq)
{
	double	dist[AXIS];

	if (enemy->is_dead)
		return (FALSE);
	*dist_sq = get_dist_sq(player, enemy, dist);
	if (*dist_sq > max_dist_sq)
		return (FALSE);
	return (is_in_hit_margin(player, dist, *dist_sq));
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
		if (is_valid_target(&data->player, &enemies[i], min_dist_sq, &dist_sq))
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
		enemy->is_dead = TRUE;
	enemy->mood = ENEMY_CHASE;
	gun->last_hit = HIT_DAMAGE;
}
