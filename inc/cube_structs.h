/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:51:54 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/09 01:30:16 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_STRUCTS_H
# define CUBE_STRUCTS_H

# include "cube.h"
# include "cube_macros.h"

typedef struct s_txtr		t_txtr;
typedef struct s_thread		t_thread;
typedef struct s_ray		t_ray;
typedef struct s_enemy		t_enemy;
typedef struct s_plyr		t_plyr;
typedef struct s_map		t_map;
typedef struct s_data		t_data;

typedef enum e_mode
{
	LOAD,
	MENU,
	GAME,
}	t_mode;

typedef enum e_type
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	DOOR,
	FLOOR,
	CEILING,
	SPRITE,
	TOTAL_TEXTURE,
}	t_type;

typedef enum e_kind
{
	ENEMY_ONE,
	ENEMY_TWO,
	ENEMY_THREE,
	TOTAL_ENEMIES,
}	t_kind;

typedef enum e_rgb
{
	R,
	G,
	B,
	RGB,
}	t_rgb;

typedef enum e_range
{
	START,
	END,
	RANGE,
}	t_range;

typedef enum e_pos
{
	X,
	Y,
	AXIS,
}	t_pos;

typedef enum e_dir
{
	N,
	S,
	W,
	E,
}	t_dir;

typedef enum e_mov
{
	FRONT,
	BACK,
	RIGHT,
	LEFT,
}	t_mov;


typedef struct s_p2d
{
	int				x;
	int				y;
}	t_p2d;

typedef struct s_enemy
{
	t_kind			type;
	int				damage;
	int				health;
	bool			is_dead;
	double			pos[AXIS];
	t_txtr			*sprite;
}	t_enemy;

typedef struct s_plyr
{
	t_dir			spawn_dir;
	int				health;
	int				damage;
	bool			is_dead;
	bool			has_won;
	double			pos[AXIS];
	double			dir[AXIS];
	double			fov[AXIS];
	int				pitch;
	t_txtr			*sprite;
}	t_plyr;

typedef struct s_txtr
{
	t_type			type;
	char			*path;
	int				color[RGB];
	uint32_t		hex_color;
	mlx_texture_t	*txtr;
	mlx_image_t		*img;
	bool			extracted;
}	t_txtr;

typedef struct s_light
{
	double			pos[AXIS];
	double			intensity;
	double			radius;
	int				color[RGB];
	t_txtr			sprite;
}	t_light;

typedef struct s_thread
{
	t_data		*data;
	pthread_t	thread;
	int			x[RANGE];
}	t_thread;

typedef struct s_ray
{
	double			dir[AXIS];
	int				pos[AXIS];
	int				step[AXIS];
	double			delta_dist[AXIS];
	double			side_dist[AXIS];
	double			perp_dist;
	t_type			wall_side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				color;
	t_txtr			texture;
}	t_ray;

typedef struct s_map
{
	int				fd;
	int				file_size;
	char			**map_file;
	char			**map_grid;
	char			**map_copy;
	int				map_size;
	int				map_max_len;
	int				map_limit[AXIS];
	int				n_players;
	int				n_enemies;
	int				n_doors;
	int				n_lights;
	t_light			*lights;
	t_txtr			textures[TOTAL_TEXTURE];
}	t_map;

typedef struct s_data
{
	t_mode			mode;
	t_map			map;
	t_plyr			player;
	t_enemy			*enemies;
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				n_cores;
	int				status;
}	t_data;

#endif
