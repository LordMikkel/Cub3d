/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 01:10:17 by migarrid          #+#    #+#             */
/*   Updated: 2025/12/25 04:09:44 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

int	exit_error(t_data *data, const char *error, int exit_code, ...)
{
	va_list	args;

	if (error)
	{
		va_start(args, exit_code);
		ft_var_printf_fd(STDERR, error, args);
		va_end(args);
	}
	if (data)
		clean_all(data);
	if (errno)
		perror("Error");
	exit(exit_code);
	return (EXIT_FAILURE);
}
