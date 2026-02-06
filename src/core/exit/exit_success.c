/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_success.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:28:57 by migarrid          #+#    #+#             */
/*   Updated: 2026/02/06 02:29:55 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cube.h"

/**
 * Handles a clean, successful program termination.
 * It frees all resources (clean_all) before exiting ensuring zero memory leaks.
 * Also it prints an optional goodbye message to improve the user experience.
 * Supports printf-style formatting for flexible error messages.
 *
 * @param data       The main struct to clean up.
 * @param error      The success message format string.
 * @param exit_code  The status code to return to the shell.
 * @param ...        Arguments for the format string.
 */
int	exit_success(t_data *data, const char *msg, int exit_code)
{
	if (msg)
		ft_printf_fd(STDOUT, msg);
	if (data)
		clean_all(data);
	exit(exit_code);
	return (EXIT_SUCCESS);
}
