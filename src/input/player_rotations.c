/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 01:28:12 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/13 05:31:49 by migarrid         ###   ########.fr       */
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

// necesita mas trabajo, Inicialización, abstracción y hacer el eje y
void	input_player_rotation(t_data *data)
{
	int			mouse[AXIS];
	static int	center[AXIS] = {WIN_WIDTH / 2, WIN_HEIGHT / 2};
	double		angle;

	mlx_get_mouse_pos(data->mlx, &mouse[X], &mouse[Y]);
	printf("Mouse: %d, %d | Dir: %f, %f\n", mouse[X], mouse[Y],
		data->player.dir[X], data->player.dir[Y]);
	angle = (mouse[X] - center[X]) * MOUSE_SENSITIVITY;
	if (mouse[X] == center[X] && mouse[Y] == center[Y])
		return ;
	if (mouse[X] != center[X])
	{
		angle = (mouse[X] - center[X]) * MOUSE_SENSITIVITY;
		apply_x_rotation(&data->player, angle);
	}
	// if (mouse[Y] != center[Y])
	// 	apply_y_rotation();
	if (mouse[X] > (int)data->img->width - 50)
	{
		center[X] = mouse[X] - 5;
		center[Y] = mouse[Y];
		mlx_set_mouse_pos(data->mlx, center[X], center[Y]);
	}
	else if (mouse[X] == 0)
	{
		center[X] = mouse[X];
		center[Y] = mouse[Y];
	}
	else if (mouse[X] < 50)
	{
		center[X] = mouse[X] + 5;
		center[Y] = mouse[Y];
	}
	else
	{
		center[X] = mouse[X];
		center[Y] = mouse[Y];
	}
}
