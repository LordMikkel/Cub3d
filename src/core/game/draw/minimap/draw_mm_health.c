/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mm_health.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:31:48 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 18:14:27 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

/**
 * Enforces strict memory boundaries for rendering on the MLX image buffer.
 * Before a primitive shape (like a rectangle) is drawn, this ensures its
 * start and end coordinates do not exceed the image's dimensions.
 * Prevents catastrophic segmentation faults when UI elements go off-screen.
 *
 * @param img    The MLX image buffer being drawn to.
 * @param start  The [X, Y] starting coordinates (top-left).
 * @param end    The [X, Y] ending coordinates (bottom-right).
 */
static void	clamp_bounds(mlx_image_t *img, int *start, int *end)
{
	if (start[X] < 0)
		start[X] = 0;
	if (start[Y] < 0)
		start[Y] = 0;
	if (end[X] > (int)img->width)
		end[X] = (int)img->width;
	if (end[Y] > (int)img->height)
		end[Y] = (int)img->height;
}

/**
 * Rasterizes a solid rectangle directly onto the pixel buffer.
 * Clamps the bounds first for safety, then iterates through the restricted
 * X/Y space, coloring each pixel individually. Used heavily for drawing UI.
 *
 * @param data   Main program struct containing the target image buffer.
 * @param start  The [X, Y] top-left corner of the rectangle.
 * @param end    The [X, Y] bottom-right corner of the rectangle.
 * @param color  The 32-bit (RGBA) color to fill the rectangle with.
 */
static void	fill_rect(t_data *data, int *start, int *end, uint32_t color)
{
	int	x;
	int	y;

	clamp_bounds(data->img, start, end);
	y = start[Y];
	while (y < end[Y])
	{
		x = start[X];
		while (x < end[X])
		{
			fast_put_pixel(data->img, x, y, color);
			x++;
		}
		y++;
	}
}

/**
 * Renders the player's dynamic health bar on the Heads-Up Display (HUD)..
 * 1. Calculates the health percentage and clamps it between 0.0 and 1.0.
 * 2. Determines the bar's color (Green > 60%, Yellow > 20%, Red <= 20%).
 * 3. Draws a static dark background rectangle for the empty portion of the bar.
 * 4. Overlays the colored rectangle scaled to the current health percentage.
 *
 * @param data     Main program struct containing UI layout variables.
 * @param player   The player structure to read current health from.
 * @param minimap  Minimap struct (unused in this specific implementation).
 */
void	draw_minimap_health(t_data *data, t_plyr *player)
{
	int			start[AXIS];
	int			end[AXIS];
	uint32_t	color;
	double		health_percent;

	health_percent = (double)player->health / INIT_PLAYER_HEALTH;
	if (health_percent < 0.0)
		health_percent = 0.0;
	else if (health_percent > 1.0)
		health_percent = 1.0;
	if (health_percent > 0.6)
		color = HEALTH_BAR_GREEN;
	else if (health_percent > 0.2)
		color = HEALTH_BAR_YELLOW;
	else
		color = HEALTH_BAR_RED;
	start[X] = data->vars.health_bar_pos[X];
	start[Y] = data->vars.health_bar_pos[Y];
	end[Y] = start[Y] + HEALTH_BAR_HEIGHT;
	end[X] = start[X] + data->vars.health_bar_width;
	fill_rect(data, start, end, HEALTH_BAR_BG);
	end[X] = start[X] + (int)(data->vars.health_bar_width * health_percent);
	fill_rect(data, start, end, color);
}
