/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 02:26:20 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/19 22:18:55 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/**
 * Checks if the given coordinates are a valid walkable cell.
 * Validates that the position is within the map bounds and that
 * the cell is not a wall ('1') or an empty space (' ').
 *
 * @param map  The map struct containing the grid and its limits.
 * @param x    The X coordinate to check.
 * @param y    The Y coordinate to check.
 * @return     TRUE if the cell is walkable, FALSE otherwise.
 */
static bool	is_inside_map(t_map *map, int x, int y)
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

/**
 * Applies a sinusoidal head bobbing effect while the player is moving.
 * Simulates the natural up-and-down motion of a walking person by
 * updating the bounce offset using a sine function. When the player
 * stops, the bounce gradually returns to zero.
 *
 * @param player  The player struct containing the head bounce state.
 */
static void	apply_head_bounce(t_plyr *player)
{
	if (player->moving)
	{
		player->head[STEP] += HEAD_BOUNCE_SPEED;
		player->head[BOUNCE] = (int)(sin(player->head[STEP]) * HEAD_MOV_AMPLIT);
	}
	else
	{
		player->head[STEP] = 0;
		if (player->head[BOUNCE] > 0)
			player->head[BOUNCE]--;
		else if (player->head[BOUNCE] < 0)
			player->head[BOUNCE]++;
	}
}

/**
 * Moves the player along the X and Y axes independently.
 * Each axis is checked separately to allow sliding along walls.
 * If the destination cell is walkable, the position is updated.
 * Sets the player moving flag to TRUE after each call.
 *
 * @param map    The map struct used for collision checking.
 * @param player The player struct whose position will be updated.
 * @param mov_x  The movement delta on the X axis.
 * @param mov_y  The movement delta on the Y axis.
 */
static void	move_player(t_map *map, t_plyr *player, double mov_x, double mov_y)
{
	int	new_x;
	int	new_y;

	new_x = (int)(player->pos[X] + mov_x);
	new_y = (int)(player->pos[Y]);
	if (is_inside_map(map, new_x, new_y))
		player->pos[X] += mov_x;
	new_x = (int)(player->pos[X]);
	new_y = (int)(player->pos[Y] + mov_y);
	if (is_inside_map(map, new_x, new_y))
		player->pos[Y] += mov_y;
	player->moving = TRUE;
}

/**
 * Processes keyboard input to move the player in the world.
 * Reads WASD keys to determine the movement direction relative
 * to where the player is facing. Holding Left Shift increases
 * the movement speed to a run. Also triggers the head bob effect.
 *
 * @param data  The main data struct containing the player and map.
 */
void	input_player_movement(t_data *data)
{
	double	pace;

	data->player.moving = FALSE;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
		pace = RUN_SPEED_PLAYER;
	else
		pace = WALK_SPEED_PLAYER;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_player(&data->map, &data->player, data->player.dir[X] * pace,
			data->player.dir[Y] * pace);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_player(&data->map, &data->player, -data->player.dir[X] * pace,
			-data->player.dir[Y] * pace);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_player(&data->map, &data->player, -data->player.dir[Y] * pace,
			data->player.dir[X] * pace);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_player(&data->map, &data->player, data->player.dir[Y] * pace,
			-data->player.dir[X] * pace);
	apply_head_bounce(&data->player);
}
