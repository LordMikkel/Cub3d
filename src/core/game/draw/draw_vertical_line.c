/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:00:59 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/13 05:31:09 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

void	draw_vertical_line(t_data *data, t_ray *ray, int x)
{
	double	wall_x;
	int		tex_x;
	int		tex_y;
	int		y;

	(void)tex_x;
	(void)tex_y;
	(void)wall_x;
	y = ray->draw_start;
	draw_ceiling(data, ray, data->map.textures, x);
	while (y <= ray->draw_end)
	{
		mlx_put_pixel(data->img, x, y, 0xFFFFFFFF);
		y++;
	}
	draw_floor(data, ray, data->map.textures, x);
}
