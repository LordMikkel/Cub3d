/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_succes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:28:57 by migarrid          #+#    #+#             */
/*   Updated: 2025/12/25 04:12:24 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

int	exit_success(t_data *data, const char *msg, int exit_code)
{
	if (msg)
		ft_printf_fd(STDOUT, msg);
	if (data)
		clean_all(data);
	exit(exit_code);
	return (EXIT_SUCCESS);
}
