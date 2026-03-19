/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemies_iii.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 23:05:29 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/20 00:24:48 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

static bool	is_inside_enemy_hear_range(double *delta,
		double enemy_hear_range_sq)
{
	double	delta_dist_sq;

	delta_dist_sq = delta[X] * delta[X] + delta[Y] * delta[Y];
	if (delta_dist_sq < enemy_hear_range_sq)
		return (TRUE);
	return (FALSE);
}

bool	can_enemy_hear_player(t_data *data, t_enemy *enemy)
{
	double	delta[AXIS];

	if (!data->player.moving || data->player.gun.model == CROSSBOW)
		return (FALSE);
	delta[X] = data->player.pos[X] - enemy->pos[X];
	delta[Y] = data->player.pos[Y] - enemy->pos[Y];
	return (is_inside_enemy_hear_range(delta, data->vars.enemy_hear_range_sq));
}

static bool	is_line_of_sight_clear(t_data *data, double dist,
		double *start, double *end)
{
	int		i;
	double	pos[AXIS];
	double	step[AXIS];
	double	delta[AXIS];

	if (dist == 0.0)
		return (TRUE);
	pos[X] = start[X];
	pos[Y] = start[Y];
	delta[X] = (end[X] - start[X]) / dist;
	delta[Y] = (end[Y] - start[Y]) / dist;
	step[X] = delta[X] * ENEMY_RAY_STEP;
	step[Y] = delta[Y] * ENEMY_RAY_STEP;
	i = 0;
	while (i < (int)(dist / ENEMY_RAY_STEP))
	{
		if (is_wall(data->map.map_grid[(int)pos[Y]][(int)pos[X]])
			|| is_door(data->map.map_grid[(int)pos[Y]][(int)pos[X]]))
			return (FALSE);
		pos[X] += step[X];
		pos[Y] += step[Y];
		i++;
	}
	return (TRUE);
}

static bool	is_player_in_fov(t_enemy *enemy, double *delta, double distance)
{
	double	dir_to_player[AXIS];
	double	dot;

	dir_to_player[X] = delta[X] / distance;
	dir_to_player[Y] = delta[Y] / distance;
	dot = ft_dot_product(enemy->dir[X], enemy->dir[Y], dir_to_player[X],
			dir_to_player[Y]);
	if (dot >= ENEMY_FOV_COS)
		return (TRUE);
	return (FALSE);
}

bool	can_enemy_see_player(t_data *data, t_plyr *player, t_enemy *enemy)
{
	double	distance;
	double	dist[AXIS];

	distance = ft_dist(enemy->pos[X], enemy->pos[Y], player->pos[X],
			player->pos[Y]);
	if (distance > ENEMY_SIGHT_RANGE)
		return (FALSE);
	dist[X] = data->player.pos[X] - enemy->pos[X];
	dist[Y] = data->player.pos[Y] - enemy->pos[Y];
	if (!is_player_in_fov(enemy, dist, distance))
		return (FALSE);
	return (is_line_of_sight_clear(data, distance, enemy->pos, player->pos));
}
