/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_row_distances.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 12:00:00 by migarrid          #+#    #+#             */
/*   Updated: 2026/10/12 12:00:00 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

/**
 * Precalculates the floor/ceiling distance of every screen row.
 * The distance only depends on the row and the horizon (screen center),
 * which is the same for every column, so we compute it once per frame
 * instead of doing a division per pixel inside every thread.
 *
 * @param data  Main program structure.
 */
void	calc_row_distances(t_data *data)
{
	double	half_height;
	double	center_y;
	int		y;

	half_height = data->vars.half_img_height;
	center_y = data->vars.half_img_height + data->player.head[POS];
	y = 0;
	while (y < (int)data->img->height)
	{
		if (y < center_y)
			data->map.row_dist[y] = half_height / (center_y - y);
		else
			data->map.row_dist[y] = half_height / (y - center_y);
		y++;
	}
}
