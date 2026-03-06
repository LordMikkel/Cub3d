/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 03:20:45 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/06 15:39:23 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

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
		is_valid_texture(data, &sprites[i]);
		sprites[i].extracted = TRUE;
		sprites[i].format = TEXTURE;
		i++;
	}
}

void	init_door(t_data *data, int x, int y, char type)
{
	static int	i = 0;

	(void)type;
	if (!data->map.doors)
		data->map.doors = alloc(data, data->map.n_doors, sizeof(t_door));
	data->map.doors[i].pos[X] = (double)x + PRECISE_CENTER_CELL;
	data->map.doors[i].pos[Y] = (double)y + PRECISE_CENTER_CELL;
	data->map.doors[i].is_open = FALSE;
	data->map.doors[i].open_percent = 0.0;
	init_door_textures(data, data->map.doors[i].sprites);
	i++;
}
