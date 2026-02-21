/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 19:40:02 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/21 19:42:35 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	init_opt(t_data *data)
{
	init_cores(data, &data->vars);
	data->vars.half_img_height = data->img->height / 2;
	data->vars.half_img_width = data->img->width / 2;
}
