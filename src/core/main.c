/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 00:51:35 by king              #+#    #+#             */
/*   Updated: 2025/12/27 02:18:01 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

int	main(int ac, char **av)
{
	t_data	data;

	check_args(ac, av);
	init_data(&data);
	parse_map(&data, av[1]);
	game_loop(&data);
	return (EXIT_SUCCESS);
}
