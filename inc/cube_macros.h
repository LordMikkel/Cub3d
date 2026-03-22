/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_macros.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 01:32:21 by migarrid          #+#    #+#             */
/*   Updated: 2026/03/22 21:02:22 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_MACROS_H
# define CUBE_MACROS_H

/* ************************************************************************** */
/*                              Windows Settings                              */
/* ************************************************************************** */
# define WIN_WIDTH					FULL_HD_WIDTH
# define WIN_HEIGHT					FULL_HD_HEIGHT
# define WIN_TITLE					"Cub3D"
# define TILE_SIZE					64

/* ************************************************************************** */
/*                              Windows Settings                              */
/* ************************************************************************** */
# define HD_WIDTH					1280
# define HD_HEIGHT					720
# define FULL_HD_WIDTH				1920
# define FULL_HD_HEIGHT				1080
# define ULTRA_HD_WIDTH				3840
# define ULTRA_HD_HEIGHT			2160

/* ************************************************************************** */
/*                               Math Constants                               */
/* ************************************************************************** */
# define PI							3.14159265358979323846
# define TWO_PI						6.28318530717958647692
# define ZERO						0.0
# define COS_45_DEG					0.707106
# define COS_135_DEG				-0.707106
# define CROSS_CENTER				0.0

/* ************************************************************************** */
/*                               Map Elements                                 */
/* ************************************************************************** */
# define SPACE						'0'
# define WALL						'1'
# define EMPTY						' '

/* ************************************************************************** */
/*                                  Limits                                    */
/* ************************************************************************** */
// Maths & System
# define MAX_NUMBER					1e30
# define FOV_FACTOR					0.8
# define MAX_THREADS 				32

// Map
# define MAX_MAP_SIZE				2000
# define MAX_ENEMIES				500
# define MAX_PLAYERS				1
# define MIN_MAP_SIZE				10
# define MIN_DISTANCE				0.001
# define PRECISE_CENTER_CELL		0.5
# define MIN_MAP_FEATURES			5
# define MAP_TXTR_SIZE				128
# define TEXTURE_MODULE				127

// Minimap
# define MINIMAP_CELL_SIZE			28
# define MINIMAP_RADIUS				3
# define MINIMAP_PADDING			40
# define MINIMAP_PLAYER_SIZE		5
# define MINIMAP_BORDER				2
# define MINIMAP_RAY_STRIDE			6
# define MINIMAP_WALL_COLOR			0x404040FF
# define MINIMAP_FLOOR_COLOR		0x1A1A1AFF
# define MINIMAP_PLAYER_COLOR		0x00FF00FF
# define MINIMAP_ENEMY_COLOR		0xFF0000FF
# define MINIMAP_RAY_COLOR			0xFFDD0070
# define MINIMAP_BORDER_COLOR		0x888888FF
# define MINIMAP_BG_COLOR			0x404040FF
# define HEALTH_BAR_RED				0xD9534FFF
# define HEALTH_BAR_YELLOW			0xF0AD4EFF
# define HEALTH_BAR_GREEN			0x5CB85CFF
# define HEALTH_BAR_BG				0x333333FF
# define BAR_BORDER					10
# define HEALTH_BAR_HEIGHT			15
# define HEALTH_BAR_Y_OFFSET		20

// Player
# define RUN_SPEED_PLAYER			0.045
# define WALK_SPEED_PLAYER			0.02
# define TILT_LIMIT					400
# define TILT_SENSITIVITY			1.0
# define HEAD_BOUNCE_SPEED			0.10
# define HEAD_MOV_AMPLIT			5.0
# define HEAD_X_AMPLIT				3.0
# define HEAD_IDLE_SPEED			0.01
# define HEAD_IDLE_AMPLIT			5.0
# define MOUSE_SENSITIVITY			0.004
# define MOUSE_DEADZONE				100
# define INIT_PLAYER_HEALTH			100
# define PASSIVE_HEAL_TIME			3.0
# define PASSIVE_HEAL_AMOUNT		2
# define ROTATION_ANGLE_KEYBOARD	0.03
# define JUMP_FORCE					35.0
# define GRAVITY					2

// Enemy
# define ENEMY_RAY_STEP				0.2
# define ENEMY_TXTR_WIDTH_FHD		128
# define ENEMY_TXTR_HEIGH_FHD		128
# define ENEMY_SIGHT_RANGE			8.0
# define ENEMY_HEAR_RANGE			4.0
# define ENEMY_FOV_COS				0.5
# define ENEMY_SPEED_CHASE			0.7
# define ENEMY_SPEED_WALK			0.25
# define ENEMY_ATTACK_RANGE			1.0
# define ENEMY_SEG_FREC_DAMAGE		1.0
# define ENEMY_X_DAMAGE				25
# define ENEMY_X_HEALTH				100
# define ENEMY_Y_DAMAGE				50
# define ENEMY_Y_HEALTH				150
# define ENEMY_Z_DAMAGE				90
# define ENEMY_Z_HEALTH				350
# define ENEMY_HITBOX				0.75
# define TOTAL_ENEMY_FRONT_FRAMES	7
# define TOTAL_ENEMY_BACK_FRAMES	10
# define TOTAL_ENEMY_LEFT_FRAMES	11
# define TOTAL_ENEMY_RIGHT_FRAMES	11
# define TOTAL_ENEMY_ATTACK_FRAMES	31
# define TOTAL_ENEMY_DEATH_FRAMES	24
# define FRAME_ENEMY_DURATION		0.12
# define ENEMY_SIDE_FRONT			0
# define ENEMY_SIDE_LEFT			1
# define ENEMY_SIDE_BACK			2
# define ENEMY_SIDE_RIGHT			3
# define ENEMY_X_FRONT_0			"tex/hospital/enemy/x/front/front_0.png"
# define ENEMY_X_FRONT_1			"tex/hospital/enemy/x/front/front_1.png"
# define ENEMY_X_FRONT_2			"tex/hospital/enemy/x/front/front_2.png"
# define ENEMY_X_FRONT_3			"tex/hospital/enemy/x/front/front_3.png"
# define ENEMY_X_FRONT_4			"tex/hospital/enemy/x/front/front_4.png"
# define ENEMY_X_FRONT_5			"tex/hospital/enemy/x/front/front_5.png"
# define ENEMY_X_FRONT_6			"tex/hospital/enemy/x/front/front_6.png"
# define ENEMY_X_BACK_0				"tex/hospital/enemy/x/back/back_0.png"
# define ENEMY_X_BACK_1				"tex/hospital/enemy/x/back/back_1.png"
# define ENEMY_X_BACK_2				"tex/hospital/enemy/x/back/back_2.png"
# define ENEMY_X_BACK_3				"tex/hospital/enemy/x/back/back_3.png"
# define ENEMY_X_BACK_4				"tex/hospital/enemy/x/back/back_4.png"
# define ENEMY_X_BACK_5				"tex/hospital/enemy/x/back/back_5.png"
# define ENEMY_X_BACK_6				"tex/hospital/enemy/x/back/back_6.png"
# define ENEMY_X_BACK_7				"tex/hospital/enemy/x/back/back_7.png"
# define ENEMY_X_BACK_8				"tex/hospital/enemy/x/back/back_8.png"
# define ENEMY_X_BACK_9				"tex/hospital/enemy/x/back/back_9.png"
# define ENEMY_X_LEFT_0				"tex/hospital/enemy/x/left/left_0.png"
# define ENEMY_X_LEFT_1				"tex/hospital/enemy/x/left/left_1.png"
# define ENEMY_X_LEFT_2				"tex/hospital/enemy/x/left/left_2.png"
# define ENEMY_X_LEFT_3				"tex/hospital/enemy/x/left/left_3.png"
# define ENEMY_X_LEFT_4				"tex/hospital/enemy/x/left/left_4.png"
# define ENEMY_X_LEFT_5				"tex/hospital/enemy/x/left/left_5.png"
# define ENEMY_X_LEFT_6				"tex/hospital/enemy/x/left/left_6.png"
# define ENEMY_X_LEFT_7				"tex/hospital/enemy/x/left/left_7.png"
# define ENEMY_X_LEFT_8				"tex/hospital/enemy/x/left/left_8.png"
# define ENEMY_X_LEFT_9				"tex/hospital/enemy/x/left/left_9.png"
# define ENEMY_X_LEFT_10			"tex/hospital/enemy/x/left/left_10.png"
# define ENEMY_X_RIGHT_0			"tex/hospital/enemy/x/right/right_0.png"
# define ENEMY_X_RIGHT_1			"tex/hospital/enemy/x/right/right_1.png"
# define ENEMY_X_RIGHT_2			"tex/hospital/enemy/x/right/right_2.png"
# define ENEMY_X_RIGHT_3			"tex/hospital/enemy/x/right/right_3.png"
# define ENEMY_X_RIGHT_4			"tex/hospital/enemy/x/right/right_4.png"
# define ENEMY_X_RIGHT_5			"tex/hospital/enemy/x/right/right_5.png"
# define ENEMY_X_RIGHT_6			"tex/hospital/enemy/x/right/right_6.png"
# define ENEMY_X_RIGHT_7			"tex/hospital/enemy/x/right/right_7.png"
# define ENEMY_X_RIGHT_8			"tex/hospital/enemy/x/right/right_8.png"
# define ENEMY_X_RIGHT_9			"tex/hospital/enemy/x/right/right_9.png"
# define ENEMY_X_RIGHT_10			"tex/hospital/enemy/x/right/right_10.png"
# define ENEMY_X_DEATH_0			"tex/hospital/enemy/x/death/death_0.png"
# define ENEMY_X_DEATH_1			"tex/hospital/enemy/x/death/death_1.png"
# define ENEMY_X_DEATH_2			"tex/hospital/enemy/x/death/death_2.png"
# define ENEMY_X_DEATH_3			"tex/hospital/enemy/x/death/death_3.png"
# define ENEMY_X_DEATH_4			"tex/hospital/enemy/x/death/death_4.png"
# define ENEMY_X_DEATH_5			"tex/hospital/enemy/x/death/death_5.png"
# define ENEMY_X_DEATH_6			"tex/hospital/enemy/x/death/death_6.png"
# define ENEMY_X_DEATH_7			"tex/hospital/enemy/x/death/death_7.png"
# define ENEMY_X_DEATH_8			"tex/hospital/enemy/x/death/death_8.png"
# define ENEMY_X_DEATH_9			"tex/hospital/enemy/x/death/death_9.png"
# define ENEMY_X_DEATH_10			"tex/hospital/enemy/x/death/death_10.png"
# define ENEMY_X_DEATH_11			"tex/hospital/enemy/x/death/death_11.png"
# define ENEMY_X_DEATH_12			"tex/hospital/enemy/x/death/death_12.png"
# define ENEMY_X_DEATH_13			"tex/hospital/enemy/x/death/death_13.png"
# define ENEMY_X_DEATH_14			"tex/hospital/enemy/x/death/death_14.png"
# define ENEMY_X_DEATH_15			"tex/hospital/enemy/x/death/death_15.png"
# define ENEMY_X_DEATH_16			"tex/hospital/enemy/x/death/death_16.png"
# define ENEMY_X_DEATH_17			"tex/hospital/enemy/x/death/death_17.png"
# define ENEMY_X_DEATH_18			"tex/hospital/enemy/x/death/death_18.png"
# define ENEMY_X_DEATH_19			"tex/hospital/enemy/x/death/death_19.png"
# define ENEMY_X_DEATH_20			"tex/hospital/enemy/x/death/death_20.png"
# define ENEMY_X_DEATH_21			"tex/hospital/enemy/x/death/death_21.png"
# define ENEMY_X_DEATH_22			"tex/hospital/enemy/x/death/death_22.png"
# define ENEMY_X_DEATH_23			"tex/hospital/enemy/x/death/death_23.png"
# define ENEMY_X_ATTACK_0			"tex/hospital/enemy/x/attack/attack_0.png"
# define ENEMY_X_ATTACK_1			"tex/hospital/enemy/x/attack/attack_1.png"
# define ENEMY_X_ATTACK_2			"tex/hospital/enemy/x/attack/attack_2.png"
# define ENEMY_X_ATTACK_3			"tex/hospital/enemy/x/attack/attack_3.png"
# define ENEMY_X_ATTACK_4			"tex/hospital/enemy/x/attack/attack_4.png"
# define ENEMY_X_ATTACK_5			"tex/hospital/enemy/x/attack/attack_5.png"
# define ENEMY_X_ATTACK_6			"tex/hospital/enemy/x/attack/attack_6.png"
# define ENEMY_X_ATTACK_7			"tex/hospital/enemy/x/attack/attack_7.png"
# define ENEMY_X_ATTACK_8			"tex/hospital/enemy/x/attack/attack_8.png"
# define ENEMY_X_ATTACK_9			"tex/hospital/enemy/x/attack/attack_9.png"
# define ENEMY_X_ATTACK_10			"tex/hospital/enemy/x/attack/attack_10.png"
# define ENEMY_X_ATTACK_11			"tex/hospital/enemy/x/attack/attack_11.png"
# define ENEMY_X_ATTACK_12			"tex/hospital/enemy/x/attack/attack_12.png"
# define ENEMY_X_ATTACK_13			"tex/hospital/enemy/x/attack/attack_13.png"
# define ENEMY_X_ATTACK_14			"tex/hospital/enemy/x/attack/attack_14.png"
# define ENEMY_X_ATTACK_15			"tex/hospital/enemy/x/attack/attack_15.png"
# define ENEMY_X_ATTACK_16			"tex/hospital/enemy/x/attack/attack_16.png"
# define ENEMY_X_ATTACK_17			"tex/hospital/enemy/x/attack/attack_17.png"
# define ENEMY_X_ATTACK_18			"tex/hospital/enemy/x/attack/attack_18.png"
# define ENEMY_X_ATTACK_19			"tex/hospital/enemy/x/attack/attack_19.png"
# define ENEMY_X_ATTACK_20			"tex/hospital/enemy/x/attack/attack_20.png"
# define ENEMY_X_ATTACK_21			"tex/hospital/enemy/x/attack/attack_21.png"
# define ENEMY_X_ATTACK_22			"tex/hospital/enemy/x/attack/attack_22.png"
# define ENEMY_X_ATTACK_23			"tex/hospital/enemy/x/attack/attack_23.png"
# define ENEMY_X_ATTACK_24			"tex/hospital/enemy/x/attack/attack_24.png"
# define ENEMY_X_ATTACK_25			"tex/hospital/enemy/x/attack/attack_25.png"
# define ENEMY_X_ATTACK_26			"tex/hospital/enemy/x/attack/attack_26.png"
# define ENEMY_X_ATTACK_27			"tex/hospital/enemy/x/attack/attack_27.png"
# define ENEMY_X_ATTACK_28			"tex/hospital/enemy/x/attack/attack_28.png"
# define ENEMY_X_ATTACK_29			"tex/hospital/enemy/x/attack/attack_29.png"
# define ENEMY_X_ATTACK_30			"tex/hospital/enemy/x/attack/attack_30.png"

// Lights
# define LIGHT_INTENSITY			0.8
# define LIGHT_RADIUS				6.0
# define AMBIENT_LIGHT				0.1
# define LIGHT_RESOLUTION			8
# define GUN_MIN_BRIGHTNESS			0.3

// Doors
# define MAX_TRANSPARENT_HITS		3
# define DOOR_INTERACT_DIST 		2.5
# define DOOR_ANIM_SPEED			0.05
# define DOOR_ANIMATIONS			5
# define DOOR_TEX_0					"tex/hospital/door/door_0.png"
# define DOOR_TEX_1					"tex/hospital/door/door_1.png"
# define DOOR_TEX_2					"tex/hospital/door/door_2.png"
# define DOOR_TEX_3					"tex/hospital/door/door_3.png"
# define DOOR_TEX_4					"tex/hospital/door/door_3.png"

// Gun
# define CROSSBOW_DAMAGE			100
# define CROSSBOW_MELEE_DAMAGE		200
# define GUN_TXTR_WIDTH_FHD			1920
# define GUN_TXTR_HEIGH_FHD			1050
# define GUN_CROSSBOW_MAX_AMMO		3
# define MAX_DISTANCE_MELEE			1.25
# define MAX_DISTANCE_SHOT			10.0
# define FRAME_GUN_IDLE_DURATION	0.12
# define FRAME_GUN_AIM_DURATION		0.03
# define FRAME_GUN_UNAIM_DURATION	0.04
# define FRAME_GUN_SHOOT_DURATION	0.03
# define FRAME_GUN_MELEE_DURATION	0.025
# define FRAME_GUN_RELOAD_DURATION	0.085
# define TOTAL_GUN_IDLE_FRAMES		5
# define TOTAL_GUN_AIM_FRAMES		10
# define TOTAL_GUN_UNAIM_FRAMES		14
# define TOTAL_GUN_SHOOT_FRAMES		10
# define TOTAL_GUN_MELEE_FRAMES		24
# define TOTAL_GUN_RELOAD_FRAMES	25
# define GUN_IDLE_0					"tex/hospital/gun/idle/idle_0.png"
# define GUN_IDLE_1					"tex/hospital/gun/idle/idle_1.png"
# define GUN_IDLE_2					"tex/hospital/gun/idle/idle_2.png"
# define GUN_AIM_0					"tex/hospital/gun/aim/aim_0.png"
# define GUN_AIM_1					"tex/hospital/gun/aim/aim_1.png"
# define GUN_AIM_2					"tex/hospital/gun/aim/aim_2.png"
# define GUN_AIM_3					"tex/hospital/gun/aim/aim_3.png"
# define GUN_AIM_4					"tex/hospital/gun/aim/aim_4.png"
# define GUN_AIM_5					"tex/hospital/gun/aim/aim_5.png"
# define GUN_AIM_6					"tex/hospital/gun/aim/aim_6.png"
# define GUN_AIM_7					"tex/hospital/gun/aim/aim_7.png"
# define GUN_AIM_8					"tex/hospital/gun/aim/aim_8.png"
# define GUN_AIM_9					"tex/hospital/gun/aim/aim_9.png"
# define GUN_SHOOT_0				"tex/hospital/gun/shoot/shoot_0.png"
# define GUN_SHOOT_1				"tex/hospital/gun/shoot/shoot_1.png"
# define GUN_SHOOT_2				"tex/hospital/gun/shoot/shoot_2.png"
# define GUN_SHOOT_3				"tex/hospital/gun/shoot/shoot_3.png"
# define GUN_SHOOT_4				"tex/hospital/gun/shoot/shoot_4.png"
# define GUN_SHOOT_5				"tex/hospital/gun/shoot/shoot_5.png"
# define GUN_SHOOT_6				"tex/hospital/gun/shoot/shoot_6.png"
# define GUN_SHOOT_7				"tex/hospital/gun/shoot/shoot_7.png"
# define GUN_SHOOT_8				"tex/hospital/gun/shoot/shoot_8.png"
# define GUN_SHOOT_9				"tex/hospital/gun/shoot/shoot_9.png"
# define GUN_EMPTY_0				"tex/hospital/gun/empty/empty_0.png"
# define GUN_EMPTY_1				"tex/hospital/gun/empty/empty_1.png"
# define GUN_EMPTY_2				"tex/hospital/gun/empty/empty_2.png"
# define GUN_MELEE_0				"tex/hospital/gun/melee/melee_0.png"
# define GUN_MELEE_1				"tex/hospital/gun/melee/melee_1.png"
# define GUN_MELEE_2				"tex/hospital/gun/melee/melee_2.png"
# define GUN_MELEE_3				"tex/hospital/gun/melee/melee_3.png"
# define GUN_MELEE_4				"tex/hospital/gun/melee/melee_4.png"
# define GUN_MELEE_5				"tex/hospital/gun/melee/melee_5.png"
# define GUN_MELEE_6				"tex/hospital/gun/melee/melee_6.png"
# define GUN_MELEE_7				"tex/hospital/gun/melee/melee_7.png"
# define GUN_MELEE_8				"tex/hospital/gun/melee/melee_8.png"
# define GUN_MELEE_9				"tex/hospital/gun/melee/melee_9.png"
# define GUN_MELEE_10				"tex/hospital/gun/melee/melee_10.png"
# define GUN_MELEE_11				"tex/hospital/gun/melee/melee_11.png"
# define GUN_MELEE_12				"tex/hospital/gun/melee/melee_12.png"
# define GUN_MELEE_13				"tex/hospital/gun/melee/melee_13.png"
# define GUN_MELEE_14				"tex/hospital/gun/melee/melee_14.png"
# define GUN_MELEE_15				"tex/hospital/gun/melee/melee_15.png"
# define GUN_MELEE_16				"tex/hospital/gun/melee/melee_16.png"
# define GUN_MELEE_17				"tex/hospital/gun/melee/melee_17.png"
# define GUN_MELEE_18				"tex/hospital/gun/melee/melee_18.png"
# define GUN_MELEE_19				"tex/hospital/gun/melee/melee_19.png"
# define GUN_MELEE_20				"tex/hospital/gun/melee/melee_20.png"
# define GUN_MELEE_21				"tex/hospital/gun/melee/melee_21.png"
# define GUN_MELEE_22				"tex/hospital/gun/melee/melee_22.png"
# define GUN_MELEE_23				"tex/hospital/gun/melee/melee_23.png"
# define GUN_RELOAD_0				"tex/hospital/gun/reload/reload_0.png"
# define GUN_RELOAD_1				"tex/hospital/gun/reload/reload_1.png"
# define GUN_RELOAD_2				"tex/hospital/gun/reload/reload_2.png"
# define GUN_RELOAD_3				"tex/hospital/gun/reload/reload_3.png"
# define GUN_RELOAD_4				"tex/hospital/gun/reload/reload_4.png"
# define GUN_RELOAD_5				"tex/hospital/gun/reload/reload_5.png"
# define GUN_RELOAD_6				"tex/hospital/gun/reload/reload_6.png"
# define GUN_RELOAD_7				"tex/hospital/gun/reload/reload_7.png"
# define GUN_RELOAD_8				"tex/hospital/gun/reload/reload_8.png"
# define GUN_RELOAD_9				"tex/hospital/gun/reload/reload_9.png"
# define GUN_RELOAD_10				"tex/hospital/gun/reload/reload_10.png"
# define GUN_RELOAD_11				"tex/hospital/gun/reload/reload_11.png"
# define GUN_RELOAD_12				"tex/hospital/gun/reload/reload_12.png"
# define GUN_RELOAD_13				"tex/hospital/gun/reload/reload_13.png"
# define GUN_RELOAD_14				"tex/hospital/gun/reload/reload_14.png"
# define GUN_RELOAD_15				"tex/hospital/gun/reload/reload_15.png"
# define GUN_RELOAD_16				"tex/hospital/gun/reload/reload_16.png"
# define GUN_RELOAD_17				"tex/hospital/gun/reload/reload_17.png"
# define GUN_RELOAD_18				"tex/hospital/gun/reload/reload_18.png"
# define GUN_RELOAD_19				"tex/hospital/gun/reload/reload_19.png"
# define GUN_RELOAD_20				"tex/hospital/gun/reload/reload_20.png"
# define GUN_RELOAD_21				"tex/hospital/gun/reload/reload_21.png"
# define GUN_RELOAD_22				"tex/hospital/gun/reload/reload_22.png"
# define GUN_RELOAD_23				"tex/hospital/gun/reload/reload_23.png"
# define GUN_RELOAD_24				"tex/hospital/gun/reload/reload_24.png"

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
# define MOUSE_RELEASE				5
# define MOUSE_MOVE					6
# define RESIZE						12
# define CLOSE_EVENT				17

/* ************************************************************************** */
/*                                Key Masks                                   */
/* ************************************************************************** */
# define NO_MASK					0
# define MASK_KEY_PRESS				1		// 1<<0
# define MASK_KEY_RELEASE			2		// 1<<1
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
# define EXIT_FAIL					1
# define EXIT_USE					2

/* ************************************************************************** */
/*                               Colors                                       */
/* ************************************************************************** */
# define RED				"\033[1;31m"
# define GREEN				"\033[1;32m"
# define YELLOW				"\033[0;33m"
# define CLEAR				"\033[0m"

/* ************************************************************************** */
/*                               Formats                                      */
/* ************************************************************************** */
# define OK					GREEN "[OK] " CLEAR
# define KO					RED "[KO] " CLEAR
# define WARN				YELLOW "[WARNING]" CLEAR

/* ************************************************************************** */
/*                             Error Messages                                 */
/* ************************************************************************** */
// General Errors
# define ERR_MALLOC			KO "Memory allocation failed\n"
# define ERR_ARGS			KO "Invalid number of arguments\n"
# define ERR_FILE_EXT		KO "Invalid file extension. Expected .cub\n"
# define ERR_FILE_OPEN		KO "Could not open file: %s\n"
# define ERR_CORES			KO "could not determine the number of cores\n"

// Map Parsing Errors
# define ERR_MAP_EMPTY		KO "Map file is empty\n"
# define ERR_MAP_BIG		KO "Map file is too big\n"
# define ERR_MAP_INVALID 	KO "Map contains invalid characters\n"
# define ERR_MAP_WALLS		KO "Map is not enclosed by walls\n"
# define ERR_MAP_PLAYER		KO "Map must have only one player start position\n"
# define ERR_MAP_ENEMY		KO "Map is limit to 100 enemies at start position\n"
# define ERR_MAP_REACHABLE	KO "Map contains unreachable enemies\n"
# define ERR_MAP_MISSING 	KO "Map information is missing or incomplete\n"
# define ERR_MAP_DOOR		KO "Map has an invalid door placement\n"

// Texture/Color Errors
# define ERR_TEX_INVALID 	KO "Invalid texture file or path: %s\n"
# define ERR_COLOR_FMT		KO "Invalid color format. Expected R,G,B (0-255)\n"
# define ERR_DUPLICATE		KO "Duplicate texture found in map file\n"
# define ERR_TXTR_SIZE		KO "Texture %s is not %d x %d pixels\n"

// Player, Gun, Enemies
# define ERR_GUN_STATE		KO "Invalid gun state\n"
# define ERR_ENEMY_STATE	KO "Invalid enemy state\n"

// MLX Errors
# define ERR_MLX_INIT		KO "MiniLibX initialization failed\n"
# define ERR_MLX_WIN		KO "MiniLibX window creation failed\n"
# define ERR_MLX_IMG		KO "MiniLibX image creation failed\n"
# define ERR_MLX_TXT_IMG	KO "MiniLibX texture to image failed\n"

/* ************************************************************************** */
/*                             Debug Messages                                 */
/* ************************************************************************** */
# define MSG_LOST			KO "Game Over: You have been eaten by a walker!\n"
# define MSG_WON			OK "Game Over: You have survive the game!\n"
# define MSG_VALID			OK "Args validated\n"
# define MSG_INIT			OK "Initialized cub3D\n"
# define MSG_PARSING		OK "Map file parsed\n"
# define MSG_TEXTURES		OK "Textures loaded\n"
# define MSG_LIGHTMAP		OK "Lightmap rendered\n"
# define MSG_GAME_RUN		OK "Cub3D game is running\n"
# define MSG_EXIT			OK "Cub3D closed\n"

#endif
