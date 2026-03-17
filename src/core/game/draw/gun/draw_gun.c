/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:41:28 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/17 20:21:52 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

uint32_t	get_pixel_color(uint8_t *pixels, int *tex, int width);
uint32_t	apply_light(t_data *data, uint32_t color, double brightness);

static bool	is_pixel_on_screen(t_data *data, int *screen)
{
	if (screen[X] < 0 || screen[X] >= (int)data->img->width)
		return (FALSE);
	if (screen[Y] < 0 || screen[Y] >= (int)data->img->height)
		return (FALSE);
	return (TRUE);
}

static void	draw_gun_pixel(t_data *data, mlx_texture_t *tex, int *tex_coord,
		double light)
{
	uint32_t	color;
	int			screen[AXIS];

	screen[X] = data->vars.gun_pos[X] + tex_coord[X];
	screen[Y] = data->vars.gun_pos[Y] + tex_coord[Y];
	if (!is_pixel_on_screen(data, screen))
		return ;
	color = get_pixel_color(tex->pixels, tex_coord, tex->width);
	if (!is_visible_pixel(color))
		return ;
	color = apply_light(data, color, light);
	fast_put_pixel(data->img, screen[X], screen[Y], color);
}

static double	get_player_brightness(t_map *map, t_plyr *player)
{
	double	brightness;
	int		light[AXIS];

	light[X] = (int)(player->pos[X] * LIGHT_RESOLUTION);
	light[Y] = (int)(player->pos[Y] * LIGHT_RESOLUTION);
	brightness = get_brightness(map, light[X], light[Y]);
	if (brightness < GUN_MIN_BRIGHTNESS)
		brightness = GUN_MIN_BRIGHTNESS;
	return (brightness);
}

void	draw_gun(t_data *data, mlx_texture_t *texture)
{
	double	brightness;
	int		tex_coord[AXIS];

	tex_coord[Y] = 0;
	brightness = get_player_brightness(&data->map, &data->player);
	while (tex_coord[Y] < (int)texture->height)
	{
		tex_coord[X] = 0;
		while (tex_coord[X] < (int)texture->width)
		{
			draw_gun_pixel(data, texture, tex_coord, brightness);
			tex_coord[X]++;
		}
		tex_coord[Y]++;
	}
}
