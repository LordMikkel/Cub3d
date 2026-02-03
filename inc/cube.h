/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 01:27:17 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/03 07:04:55 by migarrid         ###   ########.fr       */
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
void	init_player(t_map *map, int x, int y, char dir);
void	init_enemy(t_data *data, int x, int y, char type);
void	init_ray(t_data *data, t_plyr player, t_ray *ray, int x);

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

/* ************************************************************************** */
/*                                 Engine                                     */
/* ************************************************************************** */
void	game_render(void *param);
void	raycast_render(t_data *data);

/* ************************************************************************** */
/*                                 Events                                     */
/* ************************************************************************** */
void	handle_click_inpt(mouse_key_t b, action_t a, modifier_key_t m, void *p);
void	handle_keyboard_inpt(mlx_key_data_t keydata, void *param);
void	handle_cursor_inpt(double xpos, double ypos, void *param);
int		close_esc(mlx_key_data_t keydata);
void	close_x(void *param);

/* ************************************************************************** */
/*                                 Clean                                      */
/* ************************************************************************** */
void	clean_all(t_data *data);
void	clean_mlx(t_data *data);
void	clean_map(t_data *data, t_map *map);
void	clean_enemies(t_data *data, t_map *map);
void	clean_textures(t_data *data, t_map *map);

/* ************************************************************************** */
/*                                 Exits                                      */
/* ************************************************************************** */
int		exit_success(t_data *data, const char *msg, int exit_code);
int		exit_error(t_data *data, const char *error, int exit_code, ...);

/* ************************************************************************** */
/*                                 utils                                      */
/* ************************************************************************** */
void	*allocator(t_data *data, size_t nmemb, size_t size);
bool	is_duplicated_or_initialized_texture(t_txtr *texture);
int		safe_open(t_data *data, t_map *map, char *map_path);
void	dbg_print_texture(t_map *map, int fd);
bool	is_not_an_empty_line(char *line);
bool	is_map_line(char *line);
bool	is_player(char c);
bool	is_enemy(char c);
bool	is_door(char c);
bool	is_valid_element(char c);
bool	is_valid_door(t_map *map, int x, int y);

/* ************************************************************************** */
/*                                extras                                      */
/* ************************************************************************** */

#endif
