/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 03:20:45 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/17 19:24:38 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Retrieves the hardcoded file path for a specific door animation frame.
 *
 * @param i  The frame index of the animation sequence.
 * @return   The string path to the corresponding texture file.
 */
static char	*get_door_tex_path(int i)
{
	if (i == 0)
		return (DOOR_TEX_0);
	if (i == 1)
		return (DOOR_TEX_1);
	if (i == 2)
		return (DOOR_TEX_2);
	if (i == 3)
		return (DOOR_TEX_3);
	if (i == 4)
		return (DOOR_TEX_4);
	return (NULL);
}

/**
 * Loads the sequence of images required for a door's opening animation.
 * Iterates through the predefined number of animation frames, loading each
 * PNG into the mlx graphics environment. It validates both the texture
 * load and the image conversion, acting as a security checkpoint before
 * rendering begins.
 *
 * @param data     Main program structure containing the mlx instance.
 * @param sprites  The array of texture structures to populate with frames.
 */
void	init_door_textures(t_data *data, t_txtr *sprites)
{
	int	i;

	i = 0;
	while (i < DOOR_ANIMATIONS)
	{
		sprites[i].type = DOOR;
		sprites[i].format = TEXTURE;
		sprites[i].path = (char *)get_door_tex_path(i);
		sprites[i].txtr = mlx_load_png(sprites[i].path);
		if (!sprites[i].txtr)
			exit_error(data, ERR_TEX_INVALID, EXIT_FAILURE, sprites[i].path);
		sprites[i].img = mlx_texture_to_image(data->mlx, sprites[i].txtr);
		if (!sprites[i].img)
			exit_error(data, ERR_MLX_TXT_IMG, EXIT_FAILURE);
		check_valid_texture(data, &sprites[i], MAP_TXTR_SIZE, MAP_TXTR_SIZE);
		sprites[i].extracted = TRUE;
		sprites[i].format = TEXTURE;
		i++;
	}
}

/**
 * Registers a new door entity into the game's internal logic map.
 * Converts the 2D grid coordinates (integers) into precise floating-point
 * world coordinates by adding an offset to center the door in the cell.
 * Initializes it as completely closed and triggers the texture loading.
 * Uses a static index to track the current door across multiple calls.
 *
 * @param data  Main program structure holding the map data.
 * @param x     The X grid coordinate where the door is located.
 * @param y     The Y grid coordinate where the door is located.
 * @param type  The character identifier from the map file (unused here).
 */
void	init_door(t_data *data, int x, int y, char type)
{
	static int	i = 0;

	(void)type;
	if (!data->map.doors)
		data->map.doors = alloc(data, data->map.n_doors, sizeof(t_door));
	data->map.doors[i].pos[X] = (double)x + PRECISE_CENTER_CELL;
	data->map.doors[i].pos[Y] = (double)y + PRECISE_CENTER_CELL;
	data->map.doors[i].needs_to_open = FALSE;
	data->map.doors[i].open_percent = 0.0;
	init_door_textures(data, data->map.doors[i].sprites);
	i++;
}
