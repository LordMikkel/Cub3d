/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 03:09:39 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/21 20:29:29 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

uint32_t	get_pixel_color(uint8_t *pixels, int *tex, int width);

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
static void	draw_solid_column(t_data *data, t_ray *ray, t_txtr *texture, int x)
{
	int	y;

	y = ray->wall_start;
	while (y <= ray->wall_end)
	{
		mlx_put_pixel(data->img, x, y, texture->hex_color);
		y++;
	}
}

/**
 * Draws a vertical strip of the wall by mapping pixels from an image.
 * 1. Secures the X coordinate using modulo to prevent out-of-bounds access.
 * 2. Loops from the top visible pixel to the bottom visible pixel of the wall.
 * 3. Maps the mathematical texture Y coordinate to a real integer pixel index.
 * 4. Extracts the color and draws it, then steps down the exact texture.
 *
 * @param data     Main program structure.
 * @param ray      The ray struct containing texture coordinates and steps.
 * @param texture  The texture struct containing the loaded image data.
 * @param x        The current vertical strip of the screen (pixel column).
 */
static void	draw_txtr_column(t_data *data, t_ray *ray, t_txtr *tex, int x)
{
	int			mapped_tex[AXIS];
	uint32_t	color;

	mapped_tex[X] = (int)ray->tex[X] % tex->img->width;
	while (ray->wall_start <= ray->wall_end)
	{
		mapped_tex[Y] = (int)ray->tex[Y] % tex->img->height;
		color = get_pixel_color(tex->img->pixels, mapped_tex, tex->img->width);
		mlx_put_pixel(data->img, x, ray->wall_start, color);
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
void	draw_wall(t_data *data, t_ray *ray, t_txtr *texture, int x)
{
	if (texture->format == COLOR)
		draw_solid_column(data, ray, texture, x);
	else if (texture->format == TEXTURE)
		draw_txtr_column(data, ray, texture, x);
}
