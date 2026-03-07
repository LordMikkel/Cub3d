/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cells.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:25:15 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/06 21:06:51 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

/**
 * Draws a solid square, but applies a circular clipping mask.
 * Iterates through a square bounding box, but only paints the pixel if
 * it falls within the minimap's calculated radius.
 *
 * @param data   Main data struct containing the image buffer.
 * @param pixel  The top-left starting [X, Y] coordinates for the square.
 * @param size   The width and height of the square in pixels.
 * @param color  The hex color to paint the square.
 */
void	draw_square(t_data *data, int *pixel, int size, uint32_t color)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (is_inside_circle(&data->minimap, pixel[X] + x, pixel[Y] + y))
				mlx_put_pixel(data->img, pixel[X] + x, pixel[Y] + y, color);
			x++;
		}
		y++;
	}
}

/**
 * Converts a map grid cell coordinate into a screen pixel coordinate.
 * This is the core of the scrolling minimap logic: it calculates the relative
 * distance between the cell and the precise (double) player position, then
 * scales it by the cell size and offsets it by the minimap's center point.
 * This ensures the map moves smoothly around a stationary player.
 *
 * @param player   Player struct for absolute world coordinates.
 * @param minimap  Minimap struct for center offsets and scaling.
 * @param cell     The [X, Y] grid coordinate of the map cell.
 * @param pixel    Output array to store the calculated [X, Y] screen pixels.
 */
static void	get_pixel_pos(t_plyr *player, t_mm *minimap, int *cell, int *pixel)
{
	double	dist[AXIS];

	dist[X] = cell[X] - player->pos[X];
	dist[Y] = cell[Y] - player->pos[Y];
	pixel[X] = minimap->center[X] + (int)(dist[X] * minimap->cell_size);
	pixel[Y] = minimap->center[Y] + (int)(dist[Y] * minimap->cell_size);
}

/**
 * Determines the type of a specific map cell and draws it.
 * Checks if the cell is within bounds, assigns the correct color
 * (wall or floor), translates its grid coordinate to a screen pixel,
 * and draw it.
 *
 * @param data     Main data struct for the map grid access.
 * @param player   Player struct to calculate relative distance.
 * @param minimap  Minimap struct containing rendering configurations.
 * @param cell     The [X, Y] grid coordinate to evaluate and draw.
 */
static void	draw_cell(t_data *data, t_plyr *player, t_mm *minimap, int *cell)
{
	int			pixel[AXIS];
	uint32_t	color;

	if (!is_inside_map_cells(&data->map, cell))
		return ;
	if (is_wall(data->map.map_grid[cell[Y]][cell[X]]))
		color = MINIMAP_WALL_COLOR;
	else
		color = MINIMAP_FLOOR_COLOR;
	get_pixel_pos(player, minimap, cell, pixel);
	draw_square(data, pixel, data->minimap.cell_size, color);
}

/**
 * Renders the visible portion of the map around the player.
 * For optimization, it does not iterate through the entire map matrix.
 * Instead, it defines a logical bounding box (radius + 1) around the
 * player's current grid position and only draws cells within that range.
 *
 * @param data     Main data struct.
 * @param player   Player struct for the center reference point.
 * @param minimap  Minimap struct for radius limits.
 */
void	draw_minimap_cells(t_data *data, t_plyr *player, t_mm *minimap)
{
	int		cell[AXIS];
	int		limit_cells[AXIS];

	cell[Y] = (int)player->pos[Y] - minimap->radius - 1;
	limit_cells[X] = (int)player->pos[X] + minimap->radius + 1;
	limit_cells[Y] = (int)player->pos[Y] + minimap->radius + 1;
	while (cell[Y] <= limit_cells[Y])
	{
		cell[X] = (int)player->pos[X] - minimap->radius - 1;
		while (cell[X] <= limit_cells[X])
		{
			draw_cell(data, player, minimap, cell);
			cell[X]++;
		}
		cell[Y]++;
	}
}
