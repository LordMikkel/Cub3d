/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemies_iv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 00:13:09 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/20 00:13:24 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

static int	get_enemy_max_frames(t_data *data, t_enemy *enemy)
{
	if (enemy->mood == ENEMY_IDLE)
		return (TOTAL_ENEMY_IDLE_FRAMES);
	if (enemy->mood == ENEMY_CHASE || enemy->mood == ENEMY_ALERT)
		return (TOTAL_ENEMY_CHASE_FRAMES);
	if (enemy->mood == ENEMY_ATTACK)
		return (TOTAL_ENEMY_ATTACK_FRAMES);
	if (enemy->mood == ENEMY_DEATH)
		return (TOTAL_ENEMY_DEATH_FRAMES);
	return (exit_error(data, ERR_ENEMY_STATE, EXIT_FAIL), ERROR);
}

static t_txtr	*get_enemy_current_texture(t_data *data, t_enemy *enemy)
{
	if (enemy->mood == ENEMY_IDLE)
		return (&data->vars.enemy_idle[enemy->current_frame]);
	if (enemy->mood == ENEMY_CHASE || enemy->mood == ENEMY_ALERT)
		return (&data->vars.enemy_chase[enemy->current_frame]);
	if (enemy->mood == ENEMY_ATTACK)
		return (&data->vars.enemy_attack[enemy->current_frame]);
	if (enemy->mood == ENEMY_DEATH)
		return (&data->vars.enemy_death[enemy->current_frame]);
	return (&data->vars.enemy_idle[0]);
}

void	update_enemy_animation(t_data *data, t_enemy *enemy)
{
	int	max_frames;

	if (enemy->is_dead)
		return ;
	enemy->frame_timer += data->mlx->delta_time;
	if (enemy->frame_timer < FRAME_ENEMY__DURATION)
		return ;
	enemy->frame_timer = 0.0;
	enemy->current_frame++;
	max_frames = get_enemy_max_frames(data, enemy);
	if (enemy->current_frame >= max_frames)
		enemy->current_frame = 0;
	enemy->current_tex = get_enemy_current_texture(data, enemy);
}

// IMPRIMIR ENEMIGOS
// CARGAR TEXTURAS DE ENEMIGOS
