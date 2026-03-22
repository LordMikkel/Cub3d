/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:41:28 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 18:04:50 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

uint32_t	get_pixel_color(uint8_t *pixels, int *tex, int width);
uint32_t	apply_light(t_data *data, uint32_t color, double brightness);

/**
 * Safely validates if a calculated pixel coordinate falls within the screen
 * boundaries. Prevents writing out of bounds on the MLX image buffer, which
 * would cause a segmentation fault.
 *
 * @param data    Main program struct containing the target image buffer.
 * @param screen  The [X, Y] coordinates on the screen to validate.
 * @return        TRUE if strictly inside the screen, FALSE otherwise.
 */
static bool	is_pixel_on_screen(t_data *data, int *screen)
{
	if (screen[X] < 0 || screen[X] >= (int)data->img->width)
		return (FALSE);
	if (screen[Y] < 0 || screen[Y] >= (int)data->img->height)
		return (FALSE);
	return (TRUE);
}

/**
 * Renders a single pixel of the weapon texture onto the screen.
 * Translates the texture coordinate to a screen coordinate based on the gun's
 * fixed screen position. If the pixel is visible (alpha channel check) and
 * on-screen, it applies the dynamic lighting multiplier before drawing.
 *
 * @param data       Main program struct.
 * @param tex        The MLX texture of the current gun frame.
 * @param tex_coord  The [X, Y] coordinates of the specific texture pixel.
 * @param light      The precalculated brightness multiplier (0.0 to 1.0).
 */
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
	if (is_visible_pixel(color))
	{
		color = apply_light(data, color, light);
		fast_put_pixel(data->img, screen[X], screen[Y], color);
	}
}

/**
 * Calculates the total brightness affecting the player's weapon.
 * Maps the player's floating-point world coordinates to the high-resolution
 * lightmap grid. Applies a minimum brightness clamp (GUN_MIN_BRIGHTNESS)
 * to ensure the weapon never becomes completely pitch black and unreadable.
 *
 * @param map     The map structure containing the baked lightmap.
 * @param player  The player structure to extract coordinates from.
 * @return        A float representing the brightness multiplier.
 */
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

/**
 * Orchestrates the drawing of the active weapon frame.
 * Fetches the dynamic brightness for the player's current position once,
 * then iterates through every pixel of the current weapon texture frame,
 * delegating the actual rendering and light application to draw_gun_pixel.
 *
 * @param data     Main program struct.
 * @param texture  The fully loaded MLX texture of the current frame to draw.
 */
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
