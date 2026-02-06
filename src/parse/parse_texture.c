/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 01:59:54 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/06 02:24:46 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/**
 * Packs separate RGB components into a single 32-bit integer.
 * Uses bitwise operations to shift each channel to its correct byte position:
 * - Red:   Bits 24-31 (Shifted left by 24)
 * - Green: Bits 16-23 (Shifted left by 16)
 * - Blue:  Bits 8-15  (Shifted left by 8)
 * - Alpha: Bits 0-7   (Set to 0xFF for full opacity)
 * The bitwise OR (|) combines these shifted values into the final color code.
 *
 * @param color  Array containing [R, G, B] integer values.
 * @return       The packed uint32_t color value (0xRRGGBBAA).
 */
uint32_t	rgb_to_uint32(int *color)
{
	return (((uint32_t)color[R] << 24)
		| ((uint32_t)color[B] << 16)
		| ((uint32_t)color[G] << 8)
		| 0xFF);
}

/**
 * Validates a single color channel.
 * Converts the string to an integer and checks strictly for the 0-255 range.
 * We use long for the conversion to safely detect overflows before cast to int.
 *
 * @param data  The main struct for error handling.
 * @param str   The string containing the number.
 * @return      The validated integer value (0-255).
 */
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

/**
 * Extracts Floor (F) or Ceiling (C) colors.
 * It splits the line by commas and validates that we have 3 values (R,G,B).
 * We also check for duplicates to prevent overwriting previous configs.
 *
 * @param data     The main struct.
 * @param texture  The texture struct to store the RGB array.
 * @param line     The raw line from the file.
 * @param type     The identifier (FLOOR or CEILING).
 */
static void	get_color(t_data *data, t_txtr *texture, char *line, int type)
{
	char	**rgb_split;

	if (is_duplicated_or_initialized_texture(texture))
		exit_error(data, ERR_DUPLICATE, EXIT_USE);
	texture->type = type;
	texture->path = ft_strleftrim(line + 1, " \t\n\r\v\f");
	if (!texture->path)
		exit_error(data, ERR_MALLOC, EXIT_FAILURE);
	rgb_split = ft_split(texture->path, ',');
	if (!rgb_split || ft_arraylen(rgb_split) != 3)
		exit_error(data, ERR_COLOR_FMT, EXIT_FAILURE);
	texture->color[R] = parse_rgb_value(data, rgb_split[0]);
	texture->color[G] = parse_rgb_value(data, rgb_split[1]);
	texture->color[B] = parse_rgb_value(data, rgb_split[2]);
	texture->hex_color = rgb_to_uint32(texture->color);
	ft_free_str_array(&rgb_split);
}

/**
 * Loads a wall texture.
 * We process textures by immediately attempting to load the PNG via MLX
 * The approach ensures the asset path is valid and readable right now
 * rather than crashing later during the game.
 *
 * @param data     The main struct containing the MLX instance.
 * @param texture  The target struct to store the loaded image.
 * @param line     The raw line containing the path.
 * @param type     The orientation (NO, SO, WE, EA).
 */
static void	get_texture(t_data *data, t_txtr *texture, char *line, int type)
{
	if (is_duplicated_or_initialized_texture(texture))
		exit_error(data, ERR_DUPLICATE, EXIT_USE);
	texture->type = type;
	texture->path = ft_strleftrim(line + 2, " \t\n\r\v\f");
	if (!texture->path)
		exit_error(data, ERR_MALLOC, EXIT_FAILURE);
	texture->txtr = mlx_load_png(texture->path);
	if (!texture->txtr)
		exit_error(data, ERR_TEX_INVALID, EXIT_FAILURE);
	texture->img = mlx_texture_to_image(data->mlx, texture->txtr);
	if (!texture->img)
		exit_error(data, ERR_MLX_TXT_IMG, EXIT_FAILURE);
	texture->extracted = TRUE;
}

/**
 * Configuration dispatcher.
 * Identifies the type of configuration line (texture or color) and
 * routes it to the specific parsing function.
 *
 * @param data  The main struct.
 * @param map   The map struct to populate.
 * @param line  The current line to analyze.
 */
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
		get_color(data, &map->textures[CEILING], line, CEILING);
}
