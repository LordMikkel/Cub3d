/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 04:58:37 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/05 03:18:36 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Configures the camera vectors for East/West orientation.
 * We set two main vectors here:
 * 1. Direction (dir): Where the player is looking (X axis).
 * 2. Camera Plane (fov): The width of the screen (Y axis).
 *
 * @param player  The player struct to configure.
 * @param dir     The char identifier ('E' or 'W').
 */
static void set_dir_east_and_west(t_plyr *player, char dir)
{
	if (dir == 'E')
	{
		player->spawn_dir = E;
		player->dir[X] = 1.0;
		player->dir[Y] = 0.0;
		player->fov[X] = 0.0;
		player->fov[Y] = FOV_FACTOR;
	}
	else
	{
		player->spawn_dir = W;
		player->dir[X] = -1.0;
		player->dir[Y] = 0.0;
		player->fov[X] = 0.0;
		player->fov[Y] = -FOV_FACTOR;
	}
}

/**
 * Configures the camera vectors for North/South orientation.
 * We set two main vectors here:
 * 1. Direction (dir): Where the player is looking (X axis).
 * 2. Camera Plane (fov): The width of the screen (Y axis).
 *
 * @param player  The player struct to configure.
 * @param dir     The char identifier ('N' or 'S').
 */
static void	set_dir_north_and_south(t_plyr *player, char dir)
{
	if (dir == 'N')
	{
		player->spawn_dir = N;
		player->dir[X] = 0.0;
		player->dir[Y] = -1.0;
		player->fov[X] = FOV_FACTOR;
		player->fov[Y] = 0.0;
	}
	else
	{
		player->spawn_dir = S;
		player->dir[X] = 0.0;
		player->dir[Y] = 1.0;
		player->fov[X] = -FOV_FACTOR;
		player->fov[Y] = 0.0;
	}
}

/**
 * Initializes the player's starting orientation.
 * It reads the character from the map file (N, S, E, W) and translates it
 * into mathematical vectors that the raycasting engine can understand.
 * This setup ensures the player starts facing the correct way when the
 * game launches.
 *
 * @param player  The player struct to initialize.
 * @param dir     The orientation character found in the map.
 */
static void	init_dir_and_fov_player(t_plyr *player, char dir)
{
	if (dir == 'N' || dir == 'S')
		set_dir_north_and_south(player, dir);
	else
		set_dir_east_and_west(player, dir);
}

void	init_player(t_map *map, int x, int y, char spawn_dir)
{
	init_dir_and_fov_player(&map->player, spawn_dir);
	map->player.health = INIT_PLAYER_HEALTH;
	map->player.damage = INIT_PLAYER_DAMAGE;
	map->player.pos[X] = (double)x + PRECISE_CENTER_CELL;
	map->player.pos[Y] = (double)y + PRECISE_CENTER_CELL;
}
