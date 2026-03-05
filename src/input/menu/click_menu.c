/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:34:13 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/05 19:30:46 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	handle_click_menu(mouse_key_t button,
	action_t action, modifier_key_t mods, void *param)
{
	t_data	*data;

	(void)data;
	(void)mods;
	data = (t_data *)param;
	if (data->mode != MENU)
		return ;
	if (action == MLX_PRESS)
	{
		if (button == MLX_MOUSE_BUTTON_LEFT)
		{
		}
		if (button == MLX_MOUSE_BUTTON_MIDDLE)
		{
		}
		if (button == MLX_MOUSE_BUTTON_RIGHT)
		{
		}
	}
}
