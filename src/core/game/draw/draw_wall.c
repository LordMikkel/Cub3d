/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 03:09:39 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/19 22:21:28 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/cube.h"

void	draw_wall(t_data *data, t_ray *ray, t_txtr *texture, int x)
{
	int	y;

	(void)texture;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		mlx_put_pixel(data->img, x, y, 0xFFFFFFFF);
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

// void	draw_wall(t_data *data, t_ray *ray, t_txtr *texture, int x)
// {
//     t_txtr	*tex;
//     double	row;
//     int		tex_x;
//     int		tex_y;
//     int		y;

//     (void)texture;
//     tex = ray->texture;
//     if (!tex)
//         return ;
//     y = ray->draw_start;
//     if (tex->format == COLOR)
//     {
//         while (y <= ray->draw_end)
//         {
//             mlx_put_pixel(data->img, x, y, tex->hex_color);
//             y++;
//         }
//         return ;
//     }
//     if (!tex->img || !tex->img->pixels)
//         return ;
//     tex_x = (int)ray->tex[X] & ((int)tex->img->width - 1);
//     row = ray->tex[Y];
//     while (y <= ray->draw_end)
//     {
//         tex_y = (int)row & ((int)tex->img->height - 1);
//         row += ray->tex_step;
//         mlx_put_pixel(data->img, x, y,
//             get_pixel_color(tex->img->pixels, tex_x, tex_y, tex->img->width));
//         y++;
//     }
// }
