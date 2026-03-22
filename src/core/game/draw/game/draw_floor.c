/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 00:44:26 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 21:44:26 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../inc/cube.h"

uint32_t	get_brightness(t_map *map, int x, int y);
uint32_t	get_pixel_color(uint8_t *pixels, int *tex, int width);
uint32_t	apply_light(t_data *data, uint32_t color, uint32_t brightness);

static void	get_floor_coord(t_data *data, t_ray *ray, int y)
{
	double	row_dist;

	row_dist = data->vars.half_img_height / (y - ray->screen_center[Y]);
	ray->floor[X] = data->player.pos[X] + row_dist * ray->dir[X];
	ray->floor[Y] = data->player.pos[Y] + row_dist * ray->dir[Y];
}

static void	get_tex_coord(t_ray *ray, int *tex_coord, mlx_texture_t *txtr)
{
	tex_coord[X] = (int)(ray->floor[X] * txtr->width) & TEXTURE_MODULE;
	tex_coord[Y] = (int)(ray->floor[Y] * txtr->height) & TEXTURE_MODULE;
	if (tex_coord[X] < 0)
		tex_coord[X] += txtr->width;
	if (tex_coord[Y] < 0)
		tex_coord[Y] += txtr->height;
}

static void	draw_txtr_col(t_data *data, t_ray *ray, mlx_texture_t *txtr, int x)
{
	int			y;
	uint32_t	color;
	double		bright;
	int			light[AXIS];
	int			tex_coord[AXIS];

	y = ray->wall_end + 1;
	while (y < (int)data->img->height)
	{
		get_floor_coord(data, ray, y);
		get_tex_coord(ray, tex_coord, txtr);
		light[X] = (int)(ray->floor[X] * LIGHT_RESOLUTION);
		light[Y] = (int)(ray->floor[Y] * LIGHT_RESOLUTION);
		bright = get_brightness(&data->map, light[X], light[Y]);
		color = get_pixel_color(txtr->pixels, tex_coord, txtr->width);
		color = apply_light(data, color, bright);
		fast_put_pixel(data->img, x, y, color);
		y++;
	}
}

static void	draw_solid_col(t_data *data, t_ray *ray, t_txtr *texture, int x)
{
	int			y;
	double		bright;
	int			light[AXIS];
	uint32_t	color;

	y = ray->wall_end + 1;
	while (y < (int)data->img->height)
	{
		get_floor_coord(data, ray, y);
		light[X] = (int)(ray->floor[X] * LIGHT_RESOLUTION);
		light[Y] = (int)(ray->floor[Y] * LIGHT_RESOLUTION);
		bright = get_brightness(&data->map, light[X], light[Y]);
		color = apply_light(data, texture->hex_color, bright);
		fast_put_pixel(data->img, x, y, color);
		y++;
	}
	return ;
}

void	draw_floor(t_data *data, t_ray *ray, t_txtr *texture, int x)
{
	if (texture->format == COLOR)
		draw_solid_col(data, ray, texture, x);
	else if (texture->format == TEXTURE)
		draw_txtr_col(data, ray, texture->txtr, x);
}
