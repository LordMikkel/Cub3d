/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 00:51:35 by king              #+#    #+#             */
/*   Updated: 2026/02/07 02:08:33 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

/**
 * Main for Cub3d.
 * The program follows a setup sequence to prepare dependencies:
 * 1. Validation: Ensures inputs are correct before doing any work.
 * 2. Initialization: Sets up memory and safe defaults for the structs.
 * 3. Parsing: Loads and verifies the map content/textures.
 * 4. Game-loop: Enters the infinite game loop only when data is ready.
 *
 * @param ac  Argument count (from shell).
 * @param av  Argument vector (program name + map file).
 */
int	main(int ac, char **av)
{
	t_data	data;

	check_args(ac, av);
	init_data(&data);
	parse_file(&data, av[1]);
	game_loop(&data);
	return (EXIT_SUCCESS);
}
