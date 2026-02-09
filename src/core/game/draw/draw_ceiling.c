/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 00:40:44 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/09 00:50:01 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

void draw_ceiling(t_data *data, t_ray *ray, t_txtr *texture, int x)
{
	int		y;

	y = 0;
	while (y < ray->draw_start)
	{
		mlx_put_pixel(data->img, x, y, texture[CEILING].hex_color);
		y++;
	}
}
