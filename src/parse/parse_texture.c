/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 01:59:54 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/10 01:00:11 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

static int	parse_rgb_value(t_data *data, char *str)
{
	long	value;
	int		i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
		exit_error(data, ERR_COLOR_FMT, EXIT_USE);
	if (!ft_atol_range(str + i))
		exit_error(data, ERR_COLOR_FMT, EXIT_USE);
	value = ft_atol(str + i);
	if (value < 0 || value > 255)
		exit_error(data, ERR_COLOR_FMT, EXIT_USE);
	return (value);
}

static void	get_color(t_data *data, t_txtr *texture, char *line, int type)
{
	char	**rgb_split;

	if (texture->type != 0)
		exit_error(data, ERR_DUPLICATE, EXIT_USE);
	texture->type = type;
	texture->path = ft_strleftrim(line + 1, " \t\n\r\v\f");
	if (!texture->path)
		exit_error(data, ERR_MALLOC, EXIT_FAILURE);
	rgb_split = ft_split(texture->path, ',');
	if (!rgb_split)
		exit_error(data, ERR_COLOR_FMT, EXIT_FAILURE);
	texture->color[R] = parse_rgb_value(data, rgb_split[0]);
	texture->color[G] = parse_rgb_value(data, rgb_split[1]);
	texture->color[B] = parse_rgb_value(data, rgb_split[2]);
	ft_free_str_array(&rgb_split);
}

static void	get_texture(t_data *data, t_txtr *texture, char *line, int type)
{
	if (texture->path != NULL)
		exit_error(data, ERR_DUPLICATE, EXIT_FAILURE);
	texture->type = type;
	texture->path = ft_strleftrim(line + 2, " \t\n\r\v\f");
	if (!texture->path)
		exit_error(data, ERR_MALLOC, EXIT_FAILURE);
	texture->txtr = mlx_load_png(texture->path);
	if (!texture->txtr)
		exit_error(data, ERR_TEX_INVALID, EXIT_FAILURE);
}

void	parse_texture(t_data *data, t_map *map, char *line)
{
	if (ft_strncmp(line, "NO", 2) == EQUAL)
		get_texture(data, &map->textures[NORTH], line, NORTH);
	else if (ft_strncmp(line, "EA", 2) == EQUAL)
		get_texture(data, &map->textures[EAST], line, EAST);
	else if (ft_strncmp(line, "SO", 2) == EQUAL)
		get_texture(data, &map->textures[SOUTH], line, SOUTH);
	else if (ft_strncmp(line, "WE", 2) == EQUAL)
		get_texture(data, &map->textures[WEST], line, WEST);
	else if (ft_strncmp(line, "F", 1) == EQUAL)
		get_color(data, &map->textures[FLOOR], line, FLOOR);
	else if (ft_strncmp(line, "C", 1) == EQUAL)
		get_color(data, &map->textures[CEALING], line, CEALING);
}
