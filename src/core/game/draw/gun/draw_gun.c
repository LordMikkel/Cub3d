/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:41:28 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 21:45:30 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

uint32_t	get_brightness(t_map *map, int x, int y);
uint32_t	get_pixel_color(uint8_t *pixels, int *tex, int width);
uint32_t	apply_light(t_data *data, uint32_t color, uint32_t brightness);

/**
 * Clips the visible bounds of the gun frame to the screen boundaries.
 * Done once per frame instead of checking every pixel, it prevents writing
 * out of bounds on the MLX image buffer, which would cause a segfault.
 *
 * @param data    Main program struct containing the target image buffer.
 * @param frame   The gun frame with its precalculated visible bounds.
 * @param limits  Output [MIN_X, MAX_X, MIN_Y, MAX_Y] in texture coordinates.
 */
static void	clip_bounds_to_screen(t_data *data, t_txtr *frame, int *limits)
{
	int	max_screen[AXIS];

	max_screen[X] = (int)data->img->width - 1 - data->vars.gun_pos[X];
	max_screen[Y] = (int)data->img->height - 1 - data->vars.gun_pos[Y];
	limits[MIN_X] = ft_max(frame->bounds[MIN_X], -data->vars.gun_pos[X]);
	limits[MIN_Y] = ft_max(frame->bounds[MIN_Y], -data->vars.gun_pos[Y]);
	limits[MAX_X] = frame->bounds[MAX_X];
	if (limits[MAX_X] > max_screen[X])
		limits[MAX_X] = max_screen[X];
	limits[MAX_Y] = frame->bounds[MAX_Y];
	if (limits[MAX_Y] > max_screen[Y])
		limits[MAX_Y] = max_screen[Y];
}

/**
 * Renders a single pixel of the weapon texture onto the screen.
 * Translates the texture coordinate to a screen coordinate based on the gun's
 * fixed screen position. If the pixel is visible (alpha channel check),
 * it applies the dynamic lighting multiplier before drawing.
 * The caller guarantees the pixel is on-screen (see clip_bounds_to_screen).
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
static uint32_t	get_player_brightness(t_map *map, t_plyr *player)
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
 * then iterates only through the visible box of the current weapon frame
 * (precalculated at load time and clipped to the screen), delegating the
 * actual rendering and light application to draw_gun_pixel.
 *
 * @param data   Main program struct.
 * @param frame  The current gun frame with its loaded texture and bounds.
 */
void	draw_gun(t_data *data, t_txtr *frame)
{
	double	brightness;
	int		limits[LIMITS];
	int		tex_coord[AXIS];

	brightness = get_player_brightness(&data->map, &data->player);
	clip_bounds_to_screen(data, frame, limits);
	tex_coord[Y] = limits[MIN_Y];
	while (tex_coord[Y] <= limits[MAX_Y])
	{
		tex_coord[X] = limits[MIN_X];
		while (tex_coord[X] <= limits[MAX_X])
		{
			draw_gun_pixel(data, frame->txtr, tex_coord, brightness);
			tex_coord[X]++;
		}
		tex_coord[Y]++;
	}
}
