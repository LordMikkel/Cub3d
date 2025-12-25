/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:51:54 by migarrid          #+#    #+#             */
/*   Updated: 2025/12/25 18:43:00 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_STRUCTS_H
# define CUBE_STRUCTS_H

# include "cube.h"

typedef struct s_mlx	t_mlx;
typedef struct s_data	t_data;

typedef enum e_type
{
	ZERO_TYPE,
	MENU,
	GAME,
}	t_type;

typedef struct s_data
{
	t_type			mode;
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				status;
}	t_data;

#endif
