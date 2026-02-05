/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:56:52 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/04 21:47:50 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/**
 * Checks inputs right at startup.
 * We catch errors (wrong count or extension) immediately to
 * keep the parser safe from reading invalid files.
 *
 * @param ac  The argument count (must be 2).
 * @param av  The argument vector (av[1] must be the map path).
 */
void	check_args(int ac, char **av)
{
	if (ac != 2)
		exit_error(NULL, ERR_ARGS, EXIT_USE);
	if (ac == 2)
	{
		if (ft_strcmp(ft_strrchr(av[1], '.'), ".cub") != EQUAL)
			exit_error(NULL, ERR_FILE_EXT, EXIT_USE);
	}
	ft_printf_fd(STDOUT, MSG_VALID);
}
