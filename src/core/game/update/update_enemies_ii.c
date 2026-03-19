/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemies_ii.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 23:13:12 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/19 21:13:52 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

void	attack_player(t_data *data, t_plyr *player, t_enemy *enemy)
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

// FALTA ANIMACIONES DE ENEMIGOS
// STATUS DE ENEMIGO
// IMPRIMIR ENEMIGOS
// CARGAR TEXTURAS DE ENEMIGOS
