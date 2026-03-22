/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 13:10:39 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 21:47:48 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

uint32_t		get_brightness(t_map *map, int x, int y);
uint32_t		get_pixel_color(uint8_t *pixels, int *tex, int width);
uint32_t		apply_light(t_data *data, uint32_t color, uint32_t brightness);

void	draw_enemy_col(t_data *data, mlx_texture_t *txtr, t_sprtren *ren, int x)
{
	int			y;
	int			tex[AXIS];
	uint32_t	color;

	calc_col_mappd(data, txtr, ren, x);
	tex[X] = ren->coord[X];
	y = ren->start[Y];
	while (y < ren->end[Y])
	{
		tex[Y] = (int)ren->coord[Y];
		color = get_pixel_color(txtr->pixels, tex, txtr->width);
		if (is_visible_pixel(color))
		{
			color = apply_light(data, color, ren->brightness);
			fast_put_pixel(data->img, x, y, color);
		}
		ren->coord[Y] += ren->step;
		y++;
	}
}

static void	draw_enemies_cols(t_data *data, t_enemy *enemy, t_sprtren *ren)
{
	int	x;

	x = ren->start[X];
	while (x < ren->end[X])
	{
		if (is_sprite_visible(&data->map, ren, x))
			draw_enemy_col(data, enemy->current_tex->txtr, ren, x);
		x++;
	}
}

void	draw_enemy(t_data *data, t_opt *vars, t_enemy *enemy)
{
	t_sprtren	ren;
	int			light[AXIS];

	if (enemy->is_dead || !enemy->current_tex || !enemy->current_tex->txtr)
		return ;
	calc_matrix_inverse(&data->player, enemy, &ren);
	if (is_behind_player(&ren))
		return ;
	light[X] = (int)(enemy->pos[X] * LIGHT_RESOLUTION);
	light[Y] = (int)(enemy->pos[Y] * LIGHT_RESOLUTION);
	ren.brightness = get_brightness(&data->map, light[X], light[Y]);
	calc_sprite_bounds(data, vars, &ren);
	draw_enemies_cols(data, enemy, &ren);
}
