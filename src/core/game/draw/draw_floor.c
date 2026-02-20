/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 00:44:26 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/20 00:21:11 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

void	draw_floor(t_data *data, t_ray *ray, t_txtr *texture, int x)
{
	int	y;

	y = ray->draw_end;
	while (y < (int)data->img->height)
	{
		mlx_put_pixel(data->img, x, y, texture->hex_color);
		y++;
	}
}

// static uint32_t	get_pixel_color(uint8_t *pixels, int tex_x, int tex_y, int width)
// {
//     uint8_t	*p;

//     p = pixels + (tex_y * width + tex_x) * 4;
//     return ((uint32_t)p[0] << 24 | (uint32_t)p[1] << 16
//         | (uint32_t)p[2] << 8 | (uint32_t)p[3]);
// }

// static void	get_flat_tex_coords(t_data *data, t_ray *ray,
//                 int y, int *tex_x, int *tex_y, t_txtr *tex)
// {
//     double	row_dist;
//     double	floor_x;
//     double	floor_y;
//     double	step_x;
//     double	step_y;
//     int		half_h;

//     half_h = data->img->height / 2;
//     row_dist = (double)half_h / (double)(half_h - y);
//     step_x = row_dist * (data->player.fov[X] * 2.0) / data->img->width;
//     step_y = row_dist * (data->player.fov[Y] * 2.0) / data->img->width;
//     floor_x = data->player.pos[X] + row_dist * ray->dir[X]
//         - step_x * (data->img->width / 2.0);
//     floor_y = data->player.pos[Y] + row_dist * ray->dir[Y]
//         - step_y * (data->img->width / 2.0);
//     *tex_x = (int)(floor_x * tex->img->width) % (int)tex->img->width;
//     *tex_y = (int)(floor_y * tex->img->height) % (int)tex->img->height;
//     if (*tex_x < 0)
//         *tex_x += tex->img->width;
//     if (*tex_y < 0)
//         *tex_y += tex->img->height;
// }

// void	draw_ceiling(t_data *data, t_ray *ray, t_txtr *textures, int x)
// {
//     t_txtr	*tex;
//     int		tex_x;
//     int		tex_y;
//     int		y;

//     tex = &textures[CEILING];
//     if (!tex->img)
//     {
//         y = 0;
//         while (y < ray->draw_start)
//             mlx_put_pixel(data->img, x, y++, tex->hex_color);
//         return ;
//     }
//     y = 0;
//     while (y < ray->draw_start)
//     {
//         get_flat_tex_coords(data, ray, y, &tex_x, &tex_y, tex);
//         mlx_put_pixel(data->img, x, y,
//             get_pixel_color(tex->img->pixels, tex_x, tex_y, tex->img->width));
//         y++;
//     }
// }
