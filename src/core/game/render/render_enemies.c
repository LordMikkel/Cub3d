/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enemies.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 00:39:03 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 00:38:29 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

static void	swap_enemies(t_enemy *a, t_enemy *b)
{
	t_enemy	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	sort_enemies(t_enemy *enemies, int count)
{
	int	swapped;
	int	limit;
	int	i;

	limit = count;
	swapped = TRUE;
	while (swapped)
	{
		i = 0;
		swapped = FALSE;
		while (i < limit - 1)
		{
			if (enemies[i].distance < enemies[i + 1].distance)
			{
				swap_enemies(&enemies[i], &enemies[i + 1]);
				swapped = TRUE;
			}
			i++;
		}
		limit--;
	}
}

static void	calc_dist_enemies(t_map *map, t_plyr *player, t_enemy *enemies)
{
	int	i;

	i = 0;
	while (i < map->n_enemies)
	{
		enemies[i].distance = ft_dist(player->pos[X], player->pos[Y], enemies[i].pos[X], enemies[i].pos[Y]);
		i++;
	}
}

/**
 * Sorts the enemies from the furthest to the closest (Painter's Algorithm).
 * Called once per frame by the main thread before launching the render
 * threads, which only read the sorted array.
 *
 * @param data  Main program struct containing the enemies.
 */
void	sort_enemies_by_distance(t_data *data)
{
	if (data->map.n_enemies <= 0)
		return ;
	calc_dist_enemies(&data->map, &data->player, data->enemies);
	sort_enemies(data->enemies, data->map.n_enemies);
}

/**
 * Draws every enemy (already sorted) on the columns of a render thread.
 * Sprites are drawn column by column against the z-buffer, so each thread
 * can draw its own columns right after its walls without any lock.
 *
 * @param data     Main program struct.
 * @param enemies  The enemies sorted by sort_enemies_by_distance.
 * @param cols     [START, END) range of screen columns to draw.
 */
void	render_enemies(t_data *data, t_enemy *enemies, int *cols)
{
	int	i;

	i = 0;
	while (i < data->map.n_enemies)
	{
		draw_enemy(data, &data->vars, &enemies[i], cols);
		i++;
	}
}
