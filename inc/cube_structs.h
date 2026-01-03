/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:51:54 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/03 00:21:12 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_STRUCTS_H
# define CUBE_STRUCTS_H

# include "cube.h"

typedef struct s_texture	t_texture;
typedef struct s_map		t_map;
typedef struct s_data		t_data;

typedef enum e_type
{
	ZERO_TYPE,
	MENU,
	GAME,
	NORTH,
	SOUTH,
	WEST,
	EAST,
}	t_type;

typedef struct s_texture
{
	t_type			direction;
	char			*path;
	mlx_texture_t	*txtr;
	mlx_image_t		*img;
	bool			extracted;
}	t_texture;

typedef struct s_map
{
	int				fd;
	char			**map_file;
	char			**map_grid;

}	t_map;

typedef struct s_data
{
	t_type			mode;
	t_map			map;
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				status;
}	t_data;

#endif
