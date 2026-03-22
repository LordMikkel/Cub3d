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
		enemies[i].distance = ft_dist(player->pos[X], player->pos[Y],
				enemies[i].pos[X], enemies[i].pos[Y]);
		i++;
	}
}

void	render_enemies(t_data *data, t_plyr *player, t_enemy *enemies)
{
	int	i;

	if (data->map.n_enemies <= 0)
		return ;
	calc_dist_enemies(&data->map, player, enemies);
	sort_enemies(enemies, data->map.n_enemies);
	i = 0;
	while (i < data->map.n_enemies)
	{
		draw_enemy(data, &data->vars, &enemies[i]);
		i++;
	}
}
