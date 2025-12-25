/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_macros.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 01:32:21 by migarrid          #+#    #+#             */
/*   Updated: 2025/12/25 19:12:54 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_MACROS_H
# define CUBE_MACROS_H

/* ************************************************************************** */
/*                              Windows Settings                              */
/* ************************************************************************** */
# define WIN_WIDTH					HD_WIDTH
# define WIN_HEIGHT					HD_HEIGHT
# define WIN_TITLE					"Cub3D"
# define TILE_SIZE					64

/* ************************************************************************** */
/*                              Windows Settings                              */
/* ************************************************************************** */
# define HD_WIDTH					1280
# define HD_HEIGHT					720
# define FULL_HD_WIDTH				1920
# define FULL_HD_HEIGHT				1080

/* ************************************************************************** */
/*                               Math Constants                               */
/* ************************************************************************** */
# define PI							3.14159265358979323846
# define TWO_PI						6.28318530717958647692

/* ************************************************************************** */
/*                               Map Elements                                 */
/* ************************************************************************** */
# define FLOOR						'0'
# define WALL						'1'
# define SPACE						' '

/* ************************************************************************** */
/*                                Keyboard keys                               */
/* ************************************************************************** */
# define KEY_LEFT					65361
# define KEY_RIGHT					65363
# define KEY_UP						65362
# define KEY_DOWN					65364
# define ESC_KEY					65307
# define KEY_W						119
# define KEY_A						97
# define KEY_S						115
# define KEY_D						100
# define KEY_SPACE					32
# define KEY_PRESS					2
# define KEY_RELEASE				3

/* ************************************************************************** */
/*                          Mouse and Window Keys                             */
/* ************************************************************************** */
# define ZOOM_IN					4
# define ZOOM_OUT					5
# define CLICK						1
# define MOUSE_RELESE				5
# define MOUSE_MOVE					6
# define RESIZE						12
# define CLOSE_EVENT				17

/* ************************************************************************** */
/*                                Key Masks                                   */
/* ************************************************************************** */
# define NO_MASK					0
# define MASK_KEY_PRESS				1		// 1<<0
# define MASK_KEY_RELE				2		// 1<<1
# define MASK_MOUSE_R				8		// 1 << 3
# define MASK_MOUSE_M				64		// 1 << 6
# define MASK_RESIZE				32768	// 1 << 15

/* ************************************************************************** */
/*                             File Descriptors                               */
/* ************************************************************************** */
# define STDIN						0
# define STDOUT						1
# define STDERR						2

/* ************************************************************************** */
/*                              Boolean Values                                */
/* ************************************************************************** */
# define TRUE						1
# define FALSE						0
# define SUCCESS					1
# define FAILURE					0
# define YES						1
# define NO							0

/* ************************************************************************** */
/*                              Return Values                                 */
/* ************************************************************************** */
# define EQUAL						0
# define ERROR						-1

/* ************************************************************************** */
/*                               Exit Codes                                   */
/* ************************************************************************** */
# define EXIT_SUCCESS				0
# define EXIT_FAILURE				1
# define EXIT_USE					2

/* ************************************************************************** */
/*                             Error Messages                                 */
/* ************************************************************************** */
# define ERR_PREFIX			"\033[1;31mError\033[0m\n"

// General Errors
# define ERR_MALLOC			"Memory allocation failed\n"
# define ERR_ARGS			"Invalid number of arguments\n"
# define ERR_FILE_EXT		"Invalid file extension. Expected .cub\n"
# define ERR_FILE_OPEN		"Could not open file: %s\n"

// Map Parsing Errors
# define ERR_MAP_EMPTY		"Map file is empty\n"
# define ERR_MAP_INVALID	"Map contains invalid characters\n"
# define ERR_MAP_WALLS		"Map is not enclosed by walls\n"
# define ERR_MAP_PLAYER		"Map must have exactly one player start position\n"
# define ERR_MAP_MISSING	"Map description is missing or incomplete\n"

// Texture/Color Errors
# define ERR_TEX_MISSING	"Missing texture path\n"
# define ERR_TEX_INVALID	"Invalid texture file or path\n"
# define ERR_TEX_XPM		"Texture must be an XPM file\n"
# define ERR_COLOR_FMT		"Invalid color format. Expected R,G,B (0-255)\n"
# define ERR_COLOR_RANGE	"Color values must be between 0 and 255\n"
# define ERR_DUPLICATE		"Duplicate identifier found in map file\n"

// MLX Errors
# define ERR_MLX_INIT		"MiniLibX initialization failed\n"
# define ERR_MLX_WIN		"MiniLibX window creation failed\n"
# define ERR_MLX_IMG		"MiniLibX image creation failed\n"

/* ************************************************************************** */
/*                             Debug Messages                                 */
/* ************************************************************************** */
# define MSG_INIT			"Initializing cub3D\n"
# define MSG_PARSING		"Parsing map file\n"
# define MSG_TEXTURES		"Loading textures\n"
# define MSG_READY			"Raycaster ready\n"
# define MSG_EXIT			"Closing cub3D\n"

#endif
