/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 01:01:26 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/08 01:51:07 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

void	init_data(t_data *data)
{
	*data = (t_data){0};
	init_mlx(data);
	ft_printf_fd(STDOUT, MSG_INIT);
}
