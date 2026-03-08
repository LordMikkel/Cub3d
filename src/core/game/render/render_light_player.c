/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_light_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 02:00:38 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/08 15:50:47 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

void	apply_light_to_gun(mlx_image_t *img, uint8_t *original, double light)
{
	uint32_t		i;
	uint8_t			a;

	i = 0;
	while (i < img->width * img->height * 4)
	{
		a = original[i + 3];
		if (a > 0)
		{
			img->pixels[i + 0] = (uint8_t)(original[i + 0] * light);
			img->pixels[i + 1] = (uint8_t)(original[i + 1] * light);
			img->pixels[i + 2] = (uint8_t)(original[i + 2] * light);
			img->pixels[i + 3] = a;
		}
		i += 4;
	}
}
double	calc_player_brightness(t_map *map, t_plyr *player)
{
	double	brightness;
	int 	light[AXIS];

	if (map->n_lights == 0)
		return (1.0);
	light[X] = (int)(player->pos[X] * LIGHT_RESOLUTION);
	light[Y] = (int)(player->pos[Y] * LIGHT_RESOLUTION);
	brightness = get_brightness(map, light[X], light[Y]);
	if (brightness < GUN_MIN_BRIGHTNESS)
		brightness = GUN_MIN_BRIGHTNESS;
	return (brightness);
}
