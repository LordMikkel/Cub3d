/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:56:52 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/03 00:05:01 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	check_args(int ac, char **av)
{
	if (ac > 2)
		exit_error(NULL, ERR_ARGS, EXIT_USE);
	if (ac == 2)
	{
		if (ft_strcmp(ft_strrchr(av[1], '.'), ".cub") != EQUAL)
			exit_error(NULL, ERR_FILE_EXT, EXIT_USE);
	}
	ft_printf_fd(STDOUT, MSG_VALID);
}
