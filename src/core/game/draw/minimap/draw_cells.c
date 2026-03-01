/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cells.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:25:15 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/02 00:01:37 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

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

static void	get_pixel_pos(t_plyr *player, t_mm *minimap, int *cell, int *pixel)
{
	double	dist[AXIS];

	dist[X] = cell[X] - player->pos[X];
	dist[Y] = cell[Y] - player->pos[Y];
	pixel[X] = minimap->center[X] + (int)(dist[X] * minimap->cell_size);
	pixel[Y] = minimap->center[Y] + (int)(dist[Y] * minimap->cell_size);
}

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
