/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 02:26:20 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/09 01:28:21 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

static bool is_inside_map(t_map *map, int x, int y)
{
	if (x < 0 || y < 0)
		return (FALSE);
	if (x >= map->map_limit[X])
		return (FALSE);
	if (y >= map->map_limit[Y])
		return (FALSE);
	if (map->map_grid[y][x] == '1' || map->map_grid[y][x] == ' ')
		return (FALSE);
	return (TRUE);
}

static void move_player(t_map *map, t_plyr *player, double mov_x, double mov_y)
{
	int new_x;
	int new_y;

	new_x = (int)(player->pos[X] + mov_x);
	new_y = (int)(player->pos[Y]);
	if (is_inside_map(map, new_x, new_y))
		player->pos[X] += mov_x;
	new_x = (int)(player->pos[X]);
	new_y = (int)(player->pos[Y] + mov_y);
	if (is_inside_map(map, new_x, new_y))
		player->pos[Y] += mov_y;
}

void input_player_movement(t_data *data)
{
	double pace;

	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
		pace = RUN_SPEED_PLAYER;
	else
		pace = WALK_SPEED_PLAYER;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_player(&data->map, &data->player,
					data->player.dir[X] * pace,
					data->player.dir[Y] * pace);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_player(&data->map, &data->player,
					-data->player.dir[X] * pace,
					-data->player.dir[Y] * pace);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_player(&data->map, &data->player,
					-data->player.dir[Y] * pace,
					data->player.dir[X] * pace);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_player(&data->map, &data->player,
					data->player.dir[Y] * pace,
					-data->player.dir[X] * pace);
}
