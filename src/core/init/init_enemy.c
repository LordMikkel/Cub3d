/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 04:56:47 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 01:23:38 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	init_enemy_z(t_data *data, t_enemy *enemy)
{
	(void)data;
	enemy->type = ENEMY_THREE;
	enemy->damage = ENEMY_Z_DAMAGE;
	enemy->health = ENEMY_Z_DAMAGE;
	enemy->mood = ENEMY_WALK;
	enemy->cooldown = 0.0;
}

void	init_enemy_y(t_data *data, t_enemy *enemy)
{
	(void)data;
	enemy->type = ENEMY_TWO;
	enemy->damage = ENEMY_Y_DAMAGE;
	enemy->health = ENEMY_Y_DAMAGE;
	enemy->mood = ENEMY_WALK;
	enemy->cooldown = 0.0;
}

void	init_enemy_x(t_data *data, t_enemy *enemy)
{
	(void)data;
	enemy->type = ENEMY_ONE;
	enemy->damage = ENEMY_X_DAMAGE;
	enemy->health = ENEMY_X_DAMAGE;
	enemy->mood = ENEMY_WALK;
	enemy->cooldown = 0.0;
}

void	init_enemy(t_data *data, int x, int y, char type)
{
	static int	i = 0;
	double		random_angle;

	if (!data->enemies)
		data->enemies = alloc(data, data->map.n_enemies, sizeof(t_enemy));
	random_angle = (rand() % 360) * (PI / 180.0);
	data->enemies[i].dir[X] = cos(random_angle);
	data->enemies[i].dir[Y] = sin(random_angle);
	data->enemies[i].pos[X] = (double)x + PRECISE_CENTER_CELL;
	data->enemies[i].pos[Y] = (double)y + PRECISE_CENTER_CELL;
	if (type == 'X')
		init_enemy_x(data, &data->enemies[i]);
	else if (type == 'Y')
		init_enemy_y(data, &data->enemies[i]);
	else if (type == 'Z')
		init_enemy_z(data, &data->enemies[i]);
	data->enemies[i].damage = ENEMY_X_DAMAGE;
	data->enemies[i].health = ENEMY_X_DAMAGE;
	data->enemies[i].mood = ENEMY_WALK;
	data->enemies[i].cooldown = 0.0;
	i++;
}
