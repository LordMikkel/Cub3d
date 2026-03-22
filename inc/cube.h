/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 01:27:17 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 18:44:08 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# define GNU_SOURCE
/* ************************************************************************** */
/*                               Includes                                     */
/* ************************************************************************** */
# include "../lib/mlx42/include/MLX42/MLX42.h"
# include "../lib/libft_plus/libft_plus.h"
# include "cube_structs.h"
# include "cube_macros.h"
# include <sys/types.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <errno.h>
# include <time.h>
# include <math.h>

/* ************************************************************************** */
/*                                  Core                                      */
/* ************************************************************************** */
void	game_loop(t_data *data);

/* ************************************************************************** */
/*                                  Init                                      */
/* ************************************************************************** */
void	init_data(t_data *data);
int		init_mlx(t_data *data);
void	init_jump(t_plyr *player);
void	init_minimap(t_mm *minimap);
void	init_opt(t_data *data, t_opt *vars);
void	init_transparent_hit(t_ray *ray);
void	init_gun(t_data *data, t_gun *gun);
void	init_cores(t_data *data, t_opt *vars);
void	init_lightmap(t_data *data, t_map *map);
void	init_door(t_data *data, int x, int y, char type);
void	init_player(t_data *data, int x, int y, char spawn_dir);
void	init_enemy(t_data *data, int x, int y, char type);
void	init_bresenham(int *delta, int *step, int *origin, int *end);
void	init_light_ray(t_ray *ray, t_light *light, double *target);
void	init_player_ray(t_data *data, t_plyr player, t_ray *ray, int x);
void	init_thread(t_data *data, t_thread *threads, int i, int cols_x_thread);
void	init_light(t_data *data, int x, int y, char type);
void	init_map_grid(t_data *data, t_map *map);

/* ************************************************************************** */
/*                                  Parse                                     */
/* ************************************************************************** */
void	check_args(int ac, char **av);
void	normalize_info(t_map *map);
void	parse_info(t_data *data, t_map *map);
void	parse_file(t_data *data, char *map_path);
void	get_file_info(t_data *data, t_map *map, char *map_path);
void	parse_texture(t_data *data, t_map *map, char *line);
void	parse_map(t_data *data, t_map *map, char *line);
void	validate_map(t_data *data, t_map *map);
void	get_texture(t_data *data, t_txtr *texture, char *line, int type);
void	get_color(t_data *data, t_txtr *texture, char *line, int type);

/* ************************************************************************** */
/*                                 Engine                                     */
/* ************************************************************************** */
void	game_render(void *param);
void	render_map(t_data *data);
void	render_lightmap(t_data	*data);
void	render_gun(t_data *data, t_gun *gun);
void	render_minimap(t_data *data, t_mm *minimap);
void	render_transparent_hits(t_data *data, t_ray *ray, int x);
void	render_enemies(t_data *data, t_plyr *player, t_enemy *enemies);
void	perform_dda(t_map *map, t_ray *ray);
void	calc_wall_height(t_data *data, t_ray *ray);
void	calc_perp_distance(t_plyr *player, t_ray *ray);
void	calc_wall_texture_y(t_ray *ray, t_txtr *texture);
void	calc_wall_texture_x(t_data *data, t_ray *ray);
void	calc_impact_in_wall_x(t_plyr *player, t_ray *ray);
void	calc_sprite_bounds(t_data *data, t_opt *vars, t_sprtren *ren);
void	calc_col_mappd(t_data *d, mlx_texture_t *txtr, t_sprtren *ren, int x);
void	calc_matrix_inverse(t_plyr *player, t_enemy *enemy, t_sprtren *ren);
void	gun_apply_hit(t_data *data, t_gun *gun, int damage, double max_dist);
void	open_close_door(t_data *data, t_map *map, bool *key_held);
double	get_brightness(t_map *map, int x, int y);
void	check_reload_gun_finish(t_gun *gun);
void	shot_gun(t_data *data, t_gun *gun);
void	reload_gun(t_gun *gun);
void	unaim_gun(t_gun *gun);
void	aim_gun(t_gun *gun);

/* ************************************************************************** */
/*                                  Draw                                      */
/* ************************************************************************** */
void	draw_vertical_line(t_data *data, t_ray *ray, int x);
void	draw_wall_or_door(t_data *data, t_ray *ray, t_txtr *textures, int x);
void	draw_ceiling(t_data *data, t_ray *ray, t_txtr *texture, int x);
void	draw_floor(t_data *data, t_ray *ray, t_txtr *texture, int x);
void	draw_minimap_circle_background(t_data *data, t_mm *minimap);
void	draw_minimap_cells(t_data *data, t_plyr *player, t_mm *minimap);
void	draw_minimap_enemies(t_data *data, t_plyr *player, t_mm *minimap);
void	draw_minimap_fov(t_data *data, t_plyr *player, t_mm *minimap);
void	draw_enemy(t_data *data, t_opt *vars, t_enemy *enemy);
void	draw_minimap_health(t_data *data, t_plyr *player);
void	draw_minimap_player(t_data *data, t_mm *minimap);
void	draw_gun(t_data *data, mlx_texture_t *texture);

/* ************************************************************************** */
/*                                  Update                                    */
/* ************************************************************************** */
void	update_data(t_data *data);
void	update_doors(t_map *map);
void	update_game_over(t_data *data);
void	update_gun(t_data *data, t_gun *gun);
void	update_player(t_data *data, t_plyr *player);
void	update_enemies(t_data *data, t_enemy *enemies);
void	update_enemy_animation(t_data *data, t_enemy *enemy);
void	update_enemy_state(t_data *data, t_plyr *player, t_enemy *enemy);

/* ************************************************************************** */
/*                                 Inputs                                     */
/* ************************************************************************** */
void	input_player_movement(t_data *data);
void	input_player_rotation(t_data *data);
void	input_player_interact(t_data *data);
void	handle_click_menu(mouse_key_t b, action_t a, modifier_key_t m, void *p);
void	handle_keyboard_menu(mlx_key_data_t keydata, void *param);
void	handle_cursor_menu(double xpos, double ypos, void *param);
int		close_esc(mlx_key_data_t keydata);
void	close_x(void *param);

/* ************************************************************************** */
/*                                 utils                                      */
/* ************************************************************************** */
bool	is_door(char c);
bool	is_wall(char c);
bool	is_light(char c);
bool	is_enemy(char c);
bool	is_player(char c);
bool	is_door_close(char c);
bool	is_map_line(char *line);
bool	is_valid_element(char c);
bool	is_last_aim_frame(t_gun *gun);
bool	is_behind_player(t_sprtren *ren);
bool	is_infinite_gun_animation(t_gun *gun);
void	*alloc(t_data *data, size_t nmemb, size_t size);
bool	is_sprite_visible(t_map *map, t_sprtren *ren, int x);
bool	is_duplicated_or_initialized_texture(t_txtr *texture);
int		safe_open(t_data *data, t_map *map, char *map_path);
bool	is_line_of_sight_clear(t_data *d, double dist, double *s, double *e);
void	draw_square(t_data *data, int *screen, int size, uint32_t color);
void	save_ray_hit_mm(t_mm *minimap, t_plyr *player, t_ray *ray, int col);
void	manage_color_or_texture(t_data *data, t_map *map, char *line, int type);
void	limits_player_rotation(t_data *data, int *prev, int *mouse);
bool	is_inside_circle(t_mm *minimap, int point_x, int point_y);
void	check_valid_texture(t_data *d, t_txtr *txtr, int opt_w, int opt_h);
bool	is_different_to_prev_frame(t_txtr *prev_frame, t_txtr *frame);
bool	can_enemy_see_player(t_data *data, t_plyr *player, t_enemy *enemy);
void	enemy_death(t_map *map, t_plyr *player, t_enemy *enemy);
bool	is_player_not_moving(t_plyr *player, t_gun *gun);
bool	is_player_inside_door(t_plyr *player, t_door *door);
bool	can_enemy_hear_player(t_data *data, t_enemy *enemy);
void	save_t_buffer(t_map *map, t_ray *ray, int x);
void	save_z_buffer(t_map *map, t_ray *ray, int x);
bool	is_ray_hit_the_door(t_door *door, t_ray *ray);
bool	is_ray_door(t_door *door, t_ray *ray);
bool	is_out_of_the_map(t_map *map, int *pos);
bool	is_hit_wall_or_door(t_map *map, t_ray *ray);
bool	is_valid_door(t_map *map, int x, int y);
bool	is_enemy_in_the_same_cell(double dist_sq);
bool	is_frame_not_finished(t_gun *gun, double now);
bool	is_inside_map_cells(t_map *map, int *cell);
bool	is_transparent_door(t_map *map, t_ray *ray);
int		get_max_frames(t_data *data, t_gun *gun);
bool	is_not_an_empty_line(char *line);
bool	is_visible_pixel(uint32_t color);
int		is_one_or_two_letters(int type);
double	get_frame_duration(t_gun *gun);
void	set_last_aim_frame(t_gun *gun);
void	move_x_side(t_ray *ray);
void	move_y_side(t_ray *ray);

/* ************************************************************************** */
/*                             Optimization                                   */
/* ************************************************************************** */

static inline void
	fast_put_pixel(mlx_image_t *img, int x, int y, uint32_t color)
{
	uint8_t	*pixel;

	pixel = &img->pixels[(y * (int)img->width + x) * 4];
	*(pixel++) = (uint8_t)(color >> 24);
	*(pixel++) = (uint8_t)(color >> 16);
	*(pixel++) = (uint8_t)(color >> 8);
	*(pixel) = (uint8_t)(color & 0xFF);
}

/* ************************************************************************** */
/*                                  Debug                                     */
/* ************************************************************************** */
void	dbg_print_fps(int fd);
void	dbg_print_texture(t_map *map, int fd);
void	dbg_print_map_grid(t_map *map, int fd);
void	dbg_print_gun_state(t_gun *gun, int fd);
void	dbg_print_player_pos(t_plyr *player, int *mouse, int fd);

/* ************************************************************************** */
/*                                 Clean                                      */
/* ************************************************************************** */
void	clean_all(t_data *data);
void	clean_mlx(t_data *data);
void	clean_gun(t_gun *gun);
void	clean_opt(t_opt *vars);
void	clean_doors(t_map *map);
void	clean_lights(t_map *map);
void	clean_textures(t_map *map);
void	clean_map(t_data *data, t_map *map);
void	clean_enemies(t_data *data, t_map *map, t_opt *vars);

/* ************************************************************************** */
/*                                 Exits                                      */
/* ************************************************************************** */
int		exit_success(t_data *data, const char *msg, int exit_code);
int		exit_error(t_data *data, const char *error, int exit_code, ...);

#endif
