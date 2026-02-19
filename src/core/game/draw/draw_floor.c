/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 00:44:26 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/19 03:09:13 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

void	draw_floor(t_data *data, t_ray *ray, t_txtr *texture, int x)
{
	int	y;

	y = ray->draw_end;
	while (y < (int)data->img->height)
	{
		mlx_put_pixel(data->img, x, y, texture[FLOOR].hex_color);
		y++;
	}
}
