/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemies_iv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 00:13:09 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/23 02:45:28 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

int	get_enemy_facing_side_vectors(t_plyr player, t_enemy enemy)
{
	double	dot;
	double	dist;
	double	cross;
	double	to_player[AXIS];

	to_player[X] = player.pos[X] - enemy.pos[X];
	to_player[Y] = player.pos[Y] - enemy.pos[Y];
	dist = ft_dist(enemy.pos[X], enemy.pos[Y], player.pos[X], player.pos[Y]);
	if (dist == 0.0)
		return (ENEMY_SIDE_FRONT);
	to_player[X] /= dist;
	to_player[Y] /= dist;
	dot = ft_dot(enemy.dir[X], enemy.dir[Y], to_player[X], to_player[Y]);
	cross = ft_cross(enemy.dir[X], enemy.dir[Y], to_player[X], to_player[Y]);
	if (dot > COS_45_DEG)
		return (ENEMY_SIDE_FRONT);
	else if (dot < COS_135_DEG)
		return (ENEMY_SIDE_BACK);
	else if (cross > CROSS_CENTER)
		return (ENEMY_SIDE_RIGHT);
	else
		return (ENEMY_SIDE_LEFT);
}

static int	get_enemy_max_frames(t_data *data, t_enemy *enemy)
{
	int	side;

	if (enemy->mood == ENEMY_WALK)
	{
		side = get_enemy_facing_side_vectors(data->player, *enemy);
		if (side == ENEMY_SIDE_FRONT)
			return (TOTAL_ENEMY_FRONT_FRAMES);
		else if (side == ENEMY_SIDE_LEFT)
			return (TOTAL_ENEMY_LEFT_FRAMES);
		else if (side == ENEMY_SIDE_BACK)
			return (TOTAL_ENEMY_BACK_FRAMES);
		else if (side == ENEMY_SIDE_RIGHT)
			return (TOTAL_ENEMY_RIGHT_FRAMES);
	}
	if (enemy->mood == ENEMY_CHASE)
		return (TOTAL_ENEMY_FRONT_FRAMES);
	if (enemy->mood == ENEMY_ATTACK)
		return (TOTAL_ENEMY_ATTACK_FRAMES);
	if (enemy->mood == ENEMY_DEATH)
		return (TOTAL_ENEMY_DEATH_FRAMES);
	return (exit_error(data, ERR_ENEMY_STATE, EXIT_FAILURE), ERROR);
}

static t_txtr	*get_enemy_current_texture(t_data *data, t_enemy *enemy)
{
	int	side;

	if (enemy->mood == ENEMY_WALK)
	{
		side = get_enemy_facing_side_vectors(data->player, *enemy);
		if (side == ENEMY_SIDE_FRONT)
			return (&data->vars.enemy_x_front[enemy->current_frame]);
		else if (side == ENEMY_SIDE_LEFT)
			return (&data->vars.enemy_x_left[enemy->current_frame]);
		else if (side == ENEMY_SIDE_BACK)
			return (&data->vars.enemy_x_back[enemy->current_frame]);
		else if (side == ENEMY_SIDE_RIGHT)
			return (&data->vars.enemy_x_right[enemy->current_frame]);
	}
	if (enemy->mood == ENEMY_CHASE)
		return (&data->vars.enemy_x_front[enemy->current_frame]);
	if (enemy->mood == ENEMY_ATTACK)
		return (&data->vars.enemy_x_attack[enemy->current_frame]);
	if (enemy->mood == ENEMY_DEATH)
		return (&data->vars.enemy_x_death[enemy->current_frame]);
	return (exit_error(data, ERR_ENEMY_STATE, EXIT_FAIL), NULL);
}
/*
 * debug options:
 * dbg_print_enemy_state(enemy, STDOUT);
*/

void	update_enemy_animation(t_data *data, t_enemy *enemy)
{
	int	max_frames;

	enemy->frame_timer += data->mlx->delta_time;
	if (enemy->frame_timer >= FRAME_ENEMY_DURATION)
	{
		enemy->frame_timer = 0.0;
		enemy->current_frame++;
		max_frames = get_enemy_max_frames(data, enemy);
		if (enemy->current_frame >= max_frames)
		{
			if (enemy->mood == ENEMY_DEATH)
			{
				enemy->current_frame = max_frames - 1;
				enemy->anim_done = TRUE;
			}
			else
				enemy->current_frame = 0;
		}
	}
	enemy->current_tex = get_enemy_current_texture(data, enemy);
}
