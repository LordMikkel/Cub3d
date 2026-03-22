/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_or_door.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 03:09:39 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 21:47:15 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

uint32_t		get_brightness(t_map *map, int x, int y);
uint32_t		blend_pixel(t_data *data, int *bg, uint32_t src);
uint32_t		get_pixel_color(uint8_t *pixels, int *tex, int width);
uint32_t		apply_light(t_data *data, uint32_t color, uint32_t brightness);

/**
 * Calculates the exact decimal coordinate to sample the light from.
 * Slides along the wall using the hit fraction and takes a micro-step
 * backwards (0.05) using the ray's step direction to read the light
 * "in the air". Also normalizes the grid coordinate for negative steps.
 *
 * @param ray        The current ray containing hit data.
 * @param exact_wall Array to store the resulting precise [X, Y] coordinates.
 */
static void	set_exact_light_coord(t_ray *ray, double *exact_wall)
{
	double	fraction;

	fraction = ray->wall[X];
	exact_wall[X] = ray->pos[X];
	exact_wall[Y] = ray->pos[Y];
	if (ray->wall_side == NORTH || ray->wall_side == SOUTH)
	{
		exact_wall[X] += fraction;
		exact_wall[Y] -= (ray->step[Y] * 0.05);
		if (ray->step[Y] < 0)
			exact_wall[Y] += 1.0;
	}
	else
	{
		exact_wall[Y] += fraction;
		exact_wall[X] -= (ray->step[X] * 0.05);
		if (ray->step[X] < 0)
			exact_wall[X] += 1.0;
	}
}

/**
 * Retrieves the precise brightness level for a specific vertical strip
 * of a wall. It delegates the spatial calculation, scales the result
 * to match the high-resolution lightmap, and fetches the data.
 *
 * @param data  Main program structure.
 * @param ray   The current ray being cast.
 * @return      The brightness multiplier (e.g., 0.0 to 1.0).
 */
static uint32_t	get_wall_brightness(t_data *data, t_ray *ray)
{
	double	exact_wall[AXIS];
	int		light[AXIS];

	set_exact_light_coord(ray, exact_wall);
	light[X] = (int)(exact_wall[X] * LIGHT_RESOLUTION);
	light[Y] = (int)(exact_wall[Y] * LIGHT_RESOLUTION);
	return (get_brightness(&data->map, light[X], light[Y]));
}

/**
 * Draws a vertical line of a single solid color on the screen.
 * This is used as a fallback or design choice when the map configuration
 * provides a hexadecimal color code instead of a texture file path.
 *
 * @param data     Main program structure containing the image buffer.
 * @param ray      The ray struct containing the vertical drawing limits.
 * @param texture  The struct containing the parsed hex color.
 * @param x        The current vertical strip of the screen (pixel column).
 */
static void	draw_solid_col(t_data *data, t_ray *ray, t_txtr *texture, int x)
{
	int			y;
	double		brightness;
	uint32_t	color;

	y = ray->wall_start;
	brightness = get_wall_brightness(data, ray);
	color = apply_light(data, texture->hex_color, brightness);
	while (y <= ray->wall_end)
	{
		fast_put_pixel(data->img, x, y, color);
		y++;
	}
}

/**
 * Draws a vertical strip of a wall or transparent texture mapping.
 * 1. Secures the X coordinate using modulo to prevent out-of-bounds access.
 * 2. Loops from the top visible pixel to the bottom visible pixel of the strip.
 * 3. Maps the mathematical texture Y coordinate to a real integer pixel index.
 * 4. Checks visibility: Only draws the pixel if `is_visible_pixel` is TRUE.
 * This ensures that the "empty" or "glass" parts of a door texture do not
 * overwrite the background walls already drawn behind them.
 *
 * @param data  Main program structure.
 * @param ray   The ray struct containing texture coordinates and steps.
 * @param tex   The texture struct containing the loaded image data.
 * @param x     The current vertical screen coordinate (pixel column).
 */
static void	draw_txtr_col(t_data *data, t_ray *ray, mlx_texture_t *txtr, int x)
{
	int			mapped_tex[AXIS];
	int			bg[AXIS];
	double		brightness;
	uint32_t	color;

	bg[X] = x;
	mapped_tex[X] = (int)ray->tex[X] & TEXTURE_MODULE;
	brightness = get_wall_brightness(data, ray);
	while (ray->wall_start <= ray->wall_end)
	{
		mapped_tex[Y] = (int)ray->tex[Y] & TEXTURE_MODULE;
		color = get_pixel_color(txtr->pixels, mapped_tex, txtr->width);
		if (is_visible_pixel(color))
		{
			bg[Y] = ray->wall_start;
			color = apply_light(data, color, brightness);
			color = blend_pixel(data, bg, color);
			fast_put_pixel(data->img, x, ray->wall_start, color);
		}
		ray->tex[Y] += ray->tex_step;
		ray->wall_start++;
	}
}

/**
 * Main orchestrator for rendering a vertical slice of a wall.
 * Acts as a router that checks the format of the parsed map asset
 * and redirects to the appropriate drawing function (solid color or texture).
 *
 * @param data     Main program structure.
 * @param ray      The current ray containing intersection data.
 * @param texture  The linked texture or color data for the wall hit.
 * @param x        The current screen column being rendered.
 */
void	draw_wall_or_door(t_data *data, t_ray *ray, t_txtr *texture, int x)
{
	if (texture->format == COLOR)
		draw_solid_col(data, ray, texture, x);
	else if (texture->format == TEXTURE)
		draw_txtr_col(data, ray, texture->txtr, x);
}
