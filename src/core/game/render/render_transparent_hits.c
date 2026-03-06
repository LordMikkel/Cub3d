/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_transparent_hits.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:02:00 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/06 18:59:27 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

static void	recover_transparent_hits(t_ray *ray, t_hit *hit)
{
	ray->pos[X] = hit->pos[X];
	ray->pos[Y] = hit->pos[Y];
	ray->wall_side = hit->wall_side;
	ray->wall[X] = hit->wall[X];
	ray->wall[Y] = hit->wall[Y];
}

void	render_transparent_hits(t_data *data, t_ray *ray, int x)
{
	int	i;

	i = ray->n_transparent_hits - 1;
	while (i >= 0)
	{
		recover_transparent_hits(ray, &ray->transparent_hits[i]);
		calculate_perp_distance(&data->player, ray);
		calculate_impact_in_wall_x(&data->player, ray);
		calculate_wall_texture_x(data, ray);
		calculate_wall_height(data, ray);
		calculate_wall_texture_y(ray, ray->texture);
		draw_vertical_line(data, ray, x);
		i--;
	}
}
