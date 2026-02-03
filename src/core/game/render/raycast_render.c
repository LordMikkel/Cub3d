/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 03:47:05 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/03 17:09:06 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

static void	cast_single_ray(t_data *data, int x)
{
	t_ray	ray;

	(void)x;
	(void)data;
	init_ray(data, data->map.player, &ray, x);
	// perform_dda(data->map,  &ray);
	// calculate_perpendicular_distance(data->map.player, &ray);
	// calculate_line_height(data, &ray);
	// render_lights();
	// draw_vertical_line(data, &ray);
}

void	raycast_render(t_data *data)
{
	int	x;

	x = 0;
	while (x < (int)data->img->width)
	{
		cast_single_ray(data, x);
		x++;
	}
}
