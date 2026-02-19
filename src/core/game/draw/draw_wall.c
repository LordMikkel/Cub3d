/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 03:09:39 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/19 05:08:35 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

void	draw_wall(t_data *data, t_ray *ray, t_txtr *texture, int x)
{
	int	y;

	(void)texture;
	y = ray->draw_start;
	while (y < (int)data->img->height)
	{
		mlx_put_pixel(data->img, x, y, 0xFFFFFFFF);
		y++;
	}
}
