/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:55:44 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/01 22:19:39 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

static void	update_bresenham_pos(int *current, int *delta, int *step, int *error)
{
	int	error_double;

	error_double = 2 * (*error);
	if (error_double >= delta[Y])
	{
		*error += delta[Y];
		current[X] += step[X];
	}
	if (error_double <= delta[X])
	{
		*error += delta[X];
		current[Y] += step[Y];
	}
}

static void	draw_bresenham_ray(t_data *data, t_mm *mm, int *current, int *end)
{
	int	delta[AXIS];
	int	step[AXIS];
	int	error;

	init_bresenham(delta, step, current, end);
	error = delta[X] + delta[Y];
	while (42)
	{
		if (is_inside_circle(mm, current[X], current[Y]))
			mlx_put_pixel(data->img, current[X], current[Y], MINIMAP_RAY_COLOR);
		if (current[X] == end[X] && current[Y] == end[Y])
			break ;
		update_bresenham_pos(current, delta, step, &error);
	}
}

void	draw_minimap_fov(t_data *data, t_plyr *player, t_mm *minimap)
{
	int		col;
	int		start[AXIS];
	int		end[AXIS];
	double	ray_diff[AXIS];

	col = 0;
	while (col < (int)data->img->width)
	{
		ray_diff[X] = minimap->ray_hits[col][X] - player->pos[X];
		ray_diff[Y] = minimap->ray_hits[col][Y] - player->pos[Y];
		start[X] = minimap->center[X];
		start[Y] = minimap->center[Y];
		end[X] = start[X] + (int)(ray_diff[X] * minimap->cell_size);
		end[Y] = start[Y] + (int)(ray_diff[Y] * minimap->cell_size);
		draw_bresenham_ray(data, minimap, start, end);
		col += MINIMAP_RAY_STRIDE;
	}
}
