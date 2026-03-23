/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_draw_enemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 01:27:30 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/23 01:10:43 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

void	calc_matrix_inverse(t_plyr *player, t_enemy *enemy, t_sprtren *ren)
{
	double	det;
	double	inv_det;
	double	cam[AXIS];

	ren->dist[X] = enemy->pos[X] - player->pos[X];
	ren->dist[Y] = enemy->pos[Y] - player->pos[Y];
	det = (player->fov[X] * player->dir[Y]) - (player->dir[X] * player->fov[Y]);
	inv_det = 1.0 / det;
	cam[X] = player->dir[Y] * ren->dist[X] - player->dir[X] * ren->dist[Y];
	cam[Y] = -player->fov[Y] * ren->dist[X] + player->fov[X] * ren->dist[Y];
	ren->transform[X] = inv_det * cam[X];
	ren->transform[Y] = inv_det * cam[Y];
}

void	calc_sprite_bounds(t_data *data, t_opt *vars, t_sprtren *ren)
{
	double	cam_offset;
	int		center[AXIS];

	cam_offset = (ren->transform[X] / ren->transform[Y]) + 1.0;
	center[X] = vars->half_img_width * cam_offset + data->player.head[SWAY];
	center[Y] = vars->half_img_height + data->player.head[POS];
	ren->screen_x = center[X];
	ren->size = abs((int)(data->img->height / ren->transform[Y]));
	ren->half_size = ren->size / 2;
	ren->start[X] = -ren->half_size + center[X];
	if (ren->start[X] < 0)
		ren->start[X] = 0;
	ren->end[X] = ren->half_size + center[X];
	if (ren->end[X] >= (int)data->img->width)
		ren->end[X] = data->img->width - 1;
	ren->start[Y] = -ren->half_size + center[Y];
	if (ren->start[Y] < 0)
		ren->start[Y] = 0;
	ren->end[Y] = ren->half_size + center[Y];
	if (ren->end[Y] >= (int)data->img->height)
		ren->end[Y] = data->img->height - 1;
}

void	calc_col_mapped(t_data *data, mlx_texture_t *tex, t_sprtren *ren, int x)
{
	int		sprite_left_edge;
	int		dist_from_edge;
	double	ratio_x;
	double	top_edge;
	int		center_y;

	sprite_left_edge = ren->screen_x - (ren->size / 2);
	dist_from_edge = x - sprite_left_edge;
	ratio_x = (double)tex->width / ren->size;
	ren->coord[X] = (int)(dist_from_edge * ratio_x);
	ren->step = 1.0 * tex->height / ren->size;
	center_y = data->vars.half_img_height + data->player.head[POS];
	top_edge = center_y - (ren->size / 2.0);
	ren->coord[Y] = (ren->start[Y] - top_edge) * ren->step;
}
