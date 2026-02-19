/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 01:28:12 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/19 21:02:28 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/**
 * Rotates the player's direction and FOV plane horizontally.
 * Applies a 2D rotation matrix to the direction vector using the given angle.
 * After updating the direction, recalculates the FOV plane to stay
 * perpendicular to the new direction with the correct field of view.
 *
 * @param player  The player struct containing direction and FOV vectors.
 * @param angle   The rotation angle in radians ('-' = left, '+ = right).
 */
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

/**
 * Tilts the player's view up or down by adjusting the head tilt offset.
 * Clamps the tilt value between -TILT_LIMIT and TILT_LIMIT to prevent
 * the camera from rotating beyond a natural vertical field of view.
 *
 * @param player  The player struct containing the head tilt state.
 * @param angle   The tilt delta to apply (negative = up, positive = down).
 */
static void	apply_y_rotation(t_plyr *player, double angle)
{
	player->head[TILT] -= (int)(angle);
	if (player->head[TILT] > TILT_LIMIT)
		player->head[TILT] = TILT_LIMIT;
	if (player->head[TILT] < -TILT_LIMIT)
		player->head[TILT] = -TILT_LIMIT;
}

/**
 * Handles player rotation based on mouse movement.
 * Compares the current mouse position against the previous reference point.
 * Horizontal movement triggers a horizontal rotation and vertical movement
 * triggers a vertical tilt. After processing, repositions the mouse
 * to avoid it escaping the window boundaries.
 *
 * @param data   The main data struct containing the player and mlx instance.
 * @param mouse  The current mouse position.
 * @param prev   The previous mouse reference position.
 */
static void	mouse_rotation(t_data *data, int *mouse, int *prev)
{
	double	angle;

	if ((mouse[X] == prev[X] && mouse[Y] == prev[Y])
		|| (mouse[X] == 0 && mouse[Y] == 0))
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

/**
 * Handles player rotation based on arrow key input.
 * LEFT and RIGHT arrow keys rotate the player horizontally.
 * UP and DOWN arrow keys tilt the camera vertically.
 * Each key applies a fixed rotation step defined by its respective constant.
 *
 * @param data  The main data struct containing the player and mlx instance.
 */
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

/**
 * Processes all rotation input for the player each frame.
 * Reads the current mouse position and delegates to both keyboard
 * and mouse rotation handlers. Uses a static center reference point
 * initialized to the middle of the window to track relative mouse movement.
 *
 * @param data  The main data struct containing the player and mlx instance.
 */
void	input_player_rotation(t_data *data)
{
	int			mouse[AXIS];
	static int	center[AXIS] = {WIN_WIDTH / 2, WIN_HEIGHT / 2};

	keyboard_rotation(data);
	mlx_get_mouse_pos(data->mlx, &mouse[X], &mouse[Y]);
	dbg_print_player_info(&data->player, mouse, STDOUT);
	mouse_rotation(data, mouse, center);
}
