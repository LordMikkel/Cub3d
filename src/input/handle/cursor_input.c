/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:34:07 by migarrid          #+#    #+#             */
/*   Updated: 2025/12/25 18:51:21 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	handle_cursor_input(double xpos, double ypos, void *param)
{
	t_data	*data;

	(void)xpos;
	(void)ypos;
	data = (t_data *)param;
	if(data->mode == MENU)
	{
	}
	if (data->mode == GAME)
	{
	}
}
