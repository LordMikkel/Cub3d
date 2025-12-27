/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:51:54 by migarrid          #+#    #+#             */
/*   Updated: 2025/12/27 02:20:00 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_STRUCTS_H
# define CUBE_STRUCTS_H

# include "cube.h"

typedef struct s_map	t_map;
typedef struct s_data	t_data;

typedef enum e_type
{
	ZERO_TYPE,
	MENU,
	GAME,
}	t_type;

typedef struct s_map
{
	int		fd;
	char	**map;
}	t_map;

typedef struct s_data
{
	t_type			mode;
	t_map			map;
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				status;
}	t_data;

#endif
