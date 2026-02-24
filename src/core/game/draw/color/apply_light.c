/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 22:59:27 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/23 18:41:49 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

uint32_t	apply_light(t_data *data, uint32_t color, double brightness)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	uint32_t	a;

	if (data->map.n_lights == 0)
		return (color);
	r = (color >> 24) & 0xFF;
	g = (color >> 16) & 0xFF;
	b = (color >> 8) & 0xFF;
	a = color & 0xFF;
	r = (uint8_t)(r * brightness);
	g = (uint8_t)(g * brightness);
	b = (uint8_t)(b * brightness);
	return ((r << 24) | (g << 16) | (b << 8) | a);
}
