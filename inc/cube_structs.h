/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:51:54 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/09 05:58:38 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_STRUCTS_H
# define CUBE_STRUCTS_H

# include "cube.h"

typedef struct s_txtr		t_txtr;
typedef struct s_map		t_map;
typedef struct s_data		t_data;

typedef enum e_mode
{
	ZERO_MODE,
	MENU,
	GAME,
}	t_mode;

typedef enum e_type
{
	ZERO_TXTR,
	NORTH,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CEALING,
	DOOR,
	SPRITE,
	TOTAL_TEXTURE,
}	t_type;

typedef enum e_rgb
{
	ZERO_RGB,
	R,
	G,
	B,
	RGB,
}	t_rgb;

typedef struct s_txtr
{
	t_type			type;
	char			*path;
	int				color[RGB];
	mlx_texture_t	*txtr;
	mlx_image_t		*img;
	bool			extracted;
}	t_txtr;

typedef struct s_map
{
	int				fd;
	int				file_size;
	char			**map_file;
	int				map_size;
	char			**map_grid;
	int				player_count;
	t_txtr			textures[TOTAL_TEXTURE];
}	t_map;

typedef struct s_data
{
	t_mode			mode;
	t_map			map;
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				status;
}	t_data;

#endif
