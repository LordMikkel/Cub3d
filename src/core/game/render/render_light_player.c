/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_light_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 02:00:38 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/08 16:24:56 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

void	apply_light_to_gun(mlx_image_t *img, uint8_t *original, double light)
{
	uint32_t	i;
	uint8_t		alpha;
	uint8_t		red;
	uint8_t		green;
	uint8_t		blue;

	i = 0;
	while (i < img->width * img->height * 4)
	{
		alpha = original[i + 3];
		if (alpha > 0)
		{
			red = original[i + 0];
			green = original[i + 1];
			blue = original[i + 2];
			img->pixels[i + 0] = (uint8_t)(red * light);
			img->pixels[i + 1] = (uint8_t)(green * light);
			img->pixels[i + 2] = (uint8_t)(blue * light);
			img->pixels[i + 3] = alpha;
		}
		i += 4;
	}
}

double	calc_player_brightness(t_map *map, t_plyr *player)
{
	double	brightness;
	int		light[AXIS];

	if (map->n_lights == 0)
		return (1.0);
	light[X] = (int)(player->pos[X] * LIGHT_RESOLUTION);
	light[Y] = (int)(player->pos[Y] * LIGHT_RESOLUTION);
	brightness = get_brightness(map, light[X], light[Y]);
	if (brightness < GUN_MIN_BRIGHTNESS)
		brightness = GUN_MIN_BRIGHTNESS;
	return (brightness);
}
