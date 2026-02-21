/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 00:44:26 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/21 20:44:39 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

uint32_t	get_pixel_color(uint8_t *pixels, int *tex, int width);

static void	draw_solid_column(t_data *data, t_ray *ray, t_txtr *texture, int x)
{
	int	y;

	y = ray->wall_end + 1;
	while (y < (int)data->img->height)
	{
		mlx_put_pixel(data->img, x, y, texture->hex_color);
		y++;
	}
	return ;
}

static void	get_floor_tex_coord(t_data *data, t_ray *ray, int y)
{
	double	row_dist;

	row_dist = data->vars.half_img_height / (y - ray->screen_center[Y]);
	ray->floor[X] = data->player.pos[X] + row_dist * ray->dir[X];
	ray->floor[Y] = data->player.pos[Y] + row_dist * ray->dir[Y];
}

static void	get_mapped_tex_coord(t_ray *ray, int *mapped_tex, mlx_image_t *txtr)
{
	mapped_tex[X] = (int)(ray->floor[X] * txtr->width) % (int)txtr->width;
	mapped_tex[Y] = (int)(ray->floor[Y] * txtr->height) % (int)txtr->height;
	if (mapped_tex[X] < 0)
		mapped_tex[X] += txtr->width;
	if (mapped_tex[Y] < 0)
		mapped_tex[Y] += txtr->height;
}

static void	draw_txtr_column(t_data *data, t_ray *ray, t_txtr *tex, int x)
{
	int			y;
	uint32_t	color;
	int			mapped_tex[AXIS];

	y = ray->wall_end + 1;
	while (y < (int)data->img->height)
	{
		get_floor_tex_coord(data, ray, y);
		get_mapped_tex_coord(ray, mapped_tex, tex->img);
		color = get_pixel_color(tex->img->pixels, mapped_tex, tex->img->width);
		mlx_put_pixel(data->img, x, y, color);
		y++;
	}
}

void	draw_floor(t_data *data, t_ray *ray, t_txtr *texture, int x)
{
	if (texture->format == COLOR)
		draw_solid_column(data, ray, texture, x);
	else if (texture->format == TEXTURE)
		draw_txtr_column(data, ray, texture, x);
}
