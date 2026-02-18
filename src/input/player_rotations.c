/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 01:28:12 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/18 23:25:17 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

static void	apply_x_rotation(t_plyr *player, double angle)
{
	double	sin_a;
	double	cos_a;
	double	old_dir_x;

	cos_a = cos(angle);
	sin_a = sin(angle);
	old_dir_x = player->dir[X];
	player->dir[X] = player->dir[X] * cos_a - player->dir[Y] * sin_a;
	player->dir[Y] = old_dir_x * sin_a + player->dir[Y] * cos_a;
	player->fov[X] = -player->dir[Y] * FOV_FACTOR;
	player->fov[Y] = player->dir[X] * FOV_FACTOR;
}

static void	apply_y_rotation(t_plyr *player, double angle)
{
	player->head[TILT] -= (int)(angle);
	if (player->head[TILT] > TILT_LIMIT)
		player->head[TILT] = TILT_LIMIT;
	if (player->head[TILT] < -TILT_LIMIT)
		player->head[TILT] = -TILT_LIMIT;
}

static void	mouse_rotation(t_data *data, int *mouse, int *prev)
{
	double	angle;

	if (mouse[X] == prev[X] && mouse[Y] == prev[Y])
		return ;
	if (mouse[X] != prev[X])
	{
		angle = (mouse[X] - prev[X]) * MOUSE_SENSITIVITY;
		apply_x_rotation(&data->player, angle);
	}
	if (mouse[Y] != prev[Y])
	{
		angle = (mouse[Y] - prev[Y]) * TILT_SENSITIVITY;
		apply_y_rotation(&data->player, angle);
	}
	limits_player_rotation(data, prev, mouse);
}

static void	keyboard_rotation(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		apply_x_rotation(&data->player, -ROTATION_ANGLE_KEYBOARD);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		apply_x_rotation(&data->player, ROTATION_ANGLE_KEYBOARD);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		apply_y_rotation(&data->player, -TILT_SENSITIVITY * 5);
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		apply_y_rotation(&data->player, TILT_SENSITIVITY * 5);
}

void	input_player_rotation(t_data *data)
{
	int			mouse[AXIS];
	static int	center[AXIS] = {WIN_WIDTH / 2, WIN_HEIGHT / 2};

	keyboard_rotation(data);
	mlx_get_mouse_pos(data->mlx, &mouse[X], &mouse[Y]);
	dbg_print_player_info(&data->player, mouse, STDOUT);
	mouse_rotation(data, mouse, center);
}
