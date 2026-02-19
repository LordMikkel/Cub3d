/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:00:59 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/19 03:09:53 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

void	draw_vertical_line(t_data *data, t_ray *ray, int x)
{
	draw_ceiling(data, ray, data->map.textures, x);
	draw_wall(data, ray, data->map.textures, x);
	draw_floor(data, ray, data->map.textures, x);
}
