/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:51:54 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/17 01:23:37 by migarrid         ###   ########.fr       */
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
typedef struct s_gun		t_gun;
typedef struct s_plyr		t_plyr;
typedef struct s_mm			t_mm;
typedef struct s_map		t_map;
typedef struct s_opt		t_opt;
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
	LIGHT,
	SPRITE,
	TOTAL_TEXTURE,
}	t_type;

typedef enum e_form
{
	ZERO_FORMAT,
	COLOR,
	TEXTURE,
}	t_form;

typedef enum e_kind
{
	ENEMY_ONE,
	ENEMY_TWO,
	ENEMY_THREE,
	TOTAL_ENEMIES,
}	t_kind;

typedef enum e_model
{
	CROSSBOW,
	REVOLVER,
	KATANA,
	TOTAL_GUN_MODELS,
}	t_model;

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

typedef enum e_plane
{
	HORIZONTAL,
	VERTICAL,
}	t_plane;

typedef enum e_head
{
	TILT,
	BOUNCE,
	STEP,
	POS,
	SWAY,
	ATRIBUTES,
}	t_head;

typedef enum e_limits
{
	MIN_X,
	MAX_X,
	MIN_Y,
	MAX_Y,
	LIMITS,
}	t_limits;

typedef enum e_limit
{
	MIN,
	MAX,
	LIMIT,
}	t_limit;

typedef enum e_mov
{
	FRONT,
	BACK,
	RIGHT,
	LEFT,
}	t_mov;

typedef enum e_state
{
	GUN_IDLE_A,
	GUN_IDLE_E,
	GUN_AIM,
	GUN_UNAIM,
	GUN_SHOOT,
	GUN_MELEE,
	GUN_RELOAD,
	TOTAL_GUN_STATES,
}	t_state;

typedef enum e_mood
{
	ENEMY_IDLE,
	ENEMY_ALERT,
	ENEMY_CHASE,
	ENEMY_ATTACK,
}	t_mood;

typedef enum e_gun_hit
{
	HIT_NONE,
	HIT_DAMAGE,
}	t_gun_hit;

typedef struct s_p2d
{
	int				x;
	int				y;
}	t_p2d;

typedef struct s_txtr
{
	t_type			type;
	t_form			format;
	char			*path;
	int				color[RGB];
	uint32_t		hex_color;
	mlx_texture_t	*txtr;
	mlx_image_t		*img;
	uint8_t			*original_pixels;
	bool			extracted;
}	t_txtr;

typedef struct s_enemy
{
	t_kind			type;
	int				damage;
	int				health;
	bool			is_dead;
	double			pos[AXIS];
	double			dir[AXIS];
	t_mood			mood;
	double			mood_timer;
	double			last_known_pos[AXIS];
	t_txtr			*sprites;
}	t_enemy;

typedef struct s_gun
{
	t_model		model;
	t_state		state;
	t_state		prev_state;
	int			shoot_damage;
	int			melee_damage;
	int			ammo;
	int			max_ammo;
	int			current_frame;
	double		frame_timer;
	double		frame_duration;
	bool		anim_done;
	bool		last_hit;
	t_txtr		idle_frames[TOTAL_GUN_IDLE_FRAMES];
	t_txtr		aim_frames[TOTAL_GUN_AIM_FRAMES];
	t_txtr		shoot_frames[TOTAL_GUN_SHOOT_FRAMES];
	t_txtr		melee_frames[TOTAL_GUN_MELEE_FRAMES];
	t_txtr		reload_frames[TOTAL_GUN_RELOAD_FRAMES];
}	t_gun;

typedef struct s_plyr
{
	t_dir			spawn_dir;
	int				health;
	bool			is_dead;
	bool			has_won;
	double			pos[AXIS];
	double			dir[AXIS];
	double			fov[AXIS];
	double			head[ATRIBUTES];
	bool			moving;
	bool			jumping;
	double			jump_vel;
	double			jump_offset;
	t_gun			gun;
}	t_plyr;

typedef struct s_light
{
	double			pos[AXIS];
	double			intensity;
	double			radius;
	int				color[RGB];
	int				bounds[LIMITS];
	uint32_t		hex_color;
	t_txtr			sprite;
}	t_light;

typedef struct s_door
{
	double	pos[AXIS];
	bool	needs_to_open;
	double	open_percent;
	t_txtr	sprites[DOOR_ANIMATIONS];
}	t_door;

typedef struct s_thread
{
	t_data		*data;
	pthread_t	thread;
	int			x[RANGE];
}	t_thread;

typedef struct s_hit
{
	int		pos[AXIS];
	t_type	wall_side;
	double	perp_dist;
	double	wall[AXIS];
}	t_hit;

typedef struct s_ray
{
	double			dir[AXIS];
	int				pos[AXIS];
	int				step[AXIS];
	double			delta_dist[AXIS];
	double			side_dist[AXIS];
	double			perp_dist;
	double			screen_center[AXIS];
	int				img_center[AXIS];
	double			wall[AXIS];
	double			ceiling[AXIS];
	double			floor[AXIS];
	t_type			wall_side;
	int				wall_height;
	int				wall_start;
	int				wall_end;
	t_txtr			*texture;
	double			tex[AXIS];
	double			tex_step;
	int				n_transparent_hits;
	t_hit			transparent_hits[MAX_TRANSPARENT_HITS];
}	t_ray;

typedef struct s_mm
{
	int				size[AXIS];
	int				offset[AXIS];
	int				center[AXIS];
	int				cell_size;
	int				player_center;
	int				radius;
	int				radius_sq_px;
	double			ray_hits[WIN_WIDTH][AXIS];
}	t_mm;

typedef struct s_map
{
	int				fd;
	int				file_size;
	int				grid_size;
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
	int				n_features;
	t_door			*doors;
	t_light			*lights;
	double			**lightmap;
	int				lightmap_limit[AXIS];
	t_txtr			textures[TOTAL_TEXTURE];
}	t_map;

typedef struct s_opt
{
	double			initial_min_dist_sq;
	int				half_img_height;
	int				half_img_width;
	int				gun_pos[AXIS];
	int				n_cores;
	uint32_t		gun_max_pixels;
}	t_opt;

typedef struct s_data
{
	t_mode			mode;
	t_map			map;
	t_mm			minimap;
	t_plyr			player;
	t_enemy			*enemies;
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_opt			vars;
	int				status;
}	t_data;

#endif
