# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/21 00:54:42 by migarrid          #+#    #+#              #
#    Updated: 2026/03/25 02:37:49 by migarrid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                              Project Information                             #
# **************************************************************************** #
NAME				= cub3d

# **************************************************************************** #
#                            Compiler and Flags                                #
# **************************************************************************** #
CC					= gcc
WFLAGS				= -Wall -Wextra -Werror -Wpedantic
DMODE				= -D MAIN
DEPFLAGS			= -MMD -MP
LIBFLAGS			= -ldl -lglfw -pthread -lm
VFLAGS				= -Ofast -march=native -flto -funroll-loops -fno-strict-aliasing
OFLAGS				= -Os -ffunction-sections -fdata-sections -Wl,--gc-sections
DFLAGS				= -g -O0
SFLAGS				= $(DFLAGS) -fsanitize=address,undefined
TFLAGS				= $(DFLAGS) -fsanitize=thread,undefined

# **************************************************************************** #
#                               Build Modes                                    #
# **************************************************************************** #
MODE				?= release

ifeq ($(MODE), release)
	CFLAGS = $(VFLAGS)
else ifeq ($(MODE), debug)
	CFLAGS = $(DFLAGS)
else ifeq ($(MODE), asan)
	CFLAGS = $(DFLAGS) $(SFLAGS)
else ifeq ($(MODE), tsan)
	CFLAGS = $(DFLAGS) $(TFLAGS)
else
	$(error "Unknown build mode: $(MODE)")
endif

# **************************************************************************** #
#                               Shell Commands                                 #
# **************************************************************************** #
RM					= rm -rf
PRINT				= printf
MAKE				= make
MKDIR				= mkdir -p
NORM				= norminette
WATCH				= watch
CMAKE				= cmake
MV					= mv
CD					= cd
GIT					= git

# **************************************************************************** #
#                              Directories                                     #
# **************************************************************************** #
INC_DIR				= inc
LIB_DIR				= lib
OBJ_DIR				= obj/$(MODE)
SRC_DIR				= src
MAP_DIR				= map
EXT_DIR				= ext
LIBFT_DIR			= $(LIB_DIR)/libft_plus
MLX_DIR				= $(LIB_DIR)/mlx42
MLX42_REPO			= https://github.com/codam-coding-college/MLX42.git

# **************************************************************************** #
#                      File Paths and Dependencies                             #
# **************************************************************************** #
MAKEFILE			= Makefile
HEADER				= $(INC_DIR)/cube.h \
					  $(INC_DIR)/cube_macros.h \
					  $(INC_DIR)/cube_structs.h
LIBFT_A				= $(LIBFT_DIR)/libft_plus.a
LIBFT_H				= $(LIBFT_DIR)/libft_plus.h
LIBFT_MAKEFILE		= $(LIBFT_DIR)/Makefile
MLX_A				= $(MLX_DIR)/build/libmlx42.a
MLX_H				= $(MLX_DIR)/include/include/MLX42/MLX42.h
SANL_SUPP			= $(EXT_DIR)/sanitize_leaks.supp
SANT_SUPP			= $(EXT_DIR)/sanitize_threads.supp
VAL_SUPP			= $(EXT_DIR)/valgrind_leaks.supp
MAP					= $(MAP_DIR)/hospital.cub
DEPS				= $(HEADER) $(MAKEFILE) $(LIBFT_H) $(LIBFT_MAKEFILE)

# **************************************************************************** #
#                                   Colors                                     #
# **************************************************************************** #
DEFAULT				= \033[0;39m
GREEN 				= \033[0;92m
BLUE 				= \033[0;94m
MAGENTA 			= \033[0;95m
CYAN 				= \033[0;96m
YELLOW 				= \033[0;33m
RED 				= \033[0;31m
GREY 				= \033[38;5;240m
PURPLE 				= \033[38;5;141m
RESET 				= \033[0m
BOLD 				= \033[1m
CLEAR 				= \r\033[K

# **************************************************************************** #
#                               Source File                                    #
# **************************************************************************** #
SRCS =				core/main.c \
					core/init/init_data.c \
					core/init/init_mlx.c \
					core/init/allocator.c \
					core/init/init_player.c \
					core/init/init_enemy.c \
					core/init/init_gun.c \
					core/init/init_jump.c \
					core/init/init_light_ray.c \
					core/init/init_player_ray.c \
					core/init/init_transparent_hit.c \
					core/init/init_opt.c \
					core/init/init_cores.c \
					core/init/init_thread.c \
					core/init/init_door.c \
					core/init/init_light.c \
					core/init/init_minimap.c \
					core/init/init_bresenham.c \
					core/init/init_map_grid.c \
					core/game/game_loop.c \
					core/game/game_render.c \
					core/game/render/render_map.c \
					core/game/render/render_lightmap.c \
					core/game/render/render_minimap.c \
					core/game/render/render_gun.c \
					core/game/render/render_enemies.c \
					core/game/render/render_transparent_hits.c \
					core/game/render/calculate/perform_dda.c \
					core/game/render/calculate/calculate_perp_distance.c \
					core/game/render/calculate/calculate_impact_in_wall_x.c \
					core/game/render/calculate/calculate_wall_height.c \
					core/game/render/calculate/calculate_wall_texture_x.c \
					core/game/render/calculate/calculate_wall_texture_y.c \
					core/game/draw/game/draw_vertical_line.c \
					core/game/draw/game/draw_wall_or_door.c \
					core/game/draw/game/draw_ceiling.c \
					core/game/draw/game/draw_floor.c \
					core/game/draw/color/get_pixel_color.c \
					core/game/draw/color/get_brightness.c \
					core/game/draw/color/apply_light.c \
					core/game/draw/color/blend_pixel.c \
					core/game/draw/enemy/draw_enemy.c \
					core/game/draw/enemy/calc_draw_enemy.c \
					core/game/draw/minimap/draw_mm_cells.c \
					core/game/draw/minimap/draw_mm_fov.c \
					core/game/draw/minimap/draw_mm_player.c \
					core/game/draw/minimap/draw_mm_health.c \
					core/game/draw/minimap/draw_mm_enemies.c \
					core/game/draw/minimap/draw_mm_circle_background.c \
					core/game/draw/minimap/draw_mm_square_background.c \
					core/game/draw/gun/draw_gun.c \
					core/game/input/game/player_movements_i.c \
					core/game/input/game/player_movements_ii.c \
					core/game/input/game/player_rotations.c \
					core/game/input/game/player_interact.c \
					core/game/input/game/interact/open_close_door.c \
					core/game/input/game/interact/aim_gun.c \
					core/game/input/game/interact/gun_apply_hit.c \
					core/game/input/game/interact/reload_gun.c \
					core/game/input/game/interact/shot_gun.c \
					core/game/input/menu/keyboard_menu.c \
					core/game/input/menu/cursor_menu.c \
					core/game/input/menu/click_menu.c \
					core/game/input/menu/events/close_events.c \
					core/game/update/update_data.c \
					core/game/update/update_player.c \
					core/game/update/update_game_over.c \
					core/game/update/update_door.c \
					core/game/update/update_gun_i.c \
					core/game/update/update_gun_ii.c \
					core/game/update/update_enemies_i.c \
					core/game/update/update_enemies_ii.c \
					core/game/update/update_enemies_iii.c \
					core/game/update/update_enemies_iv.c \
					parse/check_args.c \
					parse/parse_file.c \
					parse/get_file_info.c \
					parse/normalize_info.c \
					parse/parse_info.c \
					parse/parse_texture.c \
					parse/parse_map.c \
					parse/validate_map.c \
					utils/is_door.c \
					utils/is_wall.c \
					utils/is_light.c \
					utils/is_enemy.c \
					utils/is_player.c \
					utils/is_file_info.c \
					utils/is_sprite_visible.c \
					utils/is_behind_player.c \
					utils/is_last_aim_frame.c \
					utils/is_door_close.c \
					utils/is_player_not_moving.c \
					utils/is_visible_pixel.c \
					utils/is_transparent_door.c \
					utils/is_valid_door.c \
					utils/is_frame_not_finished.c \
					utils/is_infinite_gun_animation.c \
					utils/is_enemy_in_the_same_cell.c \
					utils/is_valid_element.c \
					utils/is_ray_hit_the_door.c \
					utils/is_inside_map_cells.c \
					utils/is_player_inside_door.c \
					utils/is_inside_circle.c \
					utils/is_unblocked_light_path.c \
					utils/is_one_or_two_letters.c \
					utils/check_valid_texture.c \
					utils/save_buffers_map.c \
					utils/manage_color_or_texture.c \
					debug/dbg_print_fps.c \
					debug/dbg_print_textures.c \
					debug/dbg_print_map_grid.c \
					debug/dbg_print_gun_state.c \
					debug/dbg_print_enemy_state.c \
					debug/dbg_print_player_pos.c \
					core/exit/clean/clean_all.c \
					core/exit/clean/clean_mlx.c \
					core/exit/clean/clean_opt.c \
					core/exit/clean/clean_map.c \
					core/exit/clean/clean_gun.c \
					core/exit/clean/clean_doors.c \
					core/exit/clean/clean_enemies.c \
					core/exit/clean/clean_textures.c \
					core/exit/clean/clean_lights.c \
					core/exit/exit_success.c \
					core/exit/exit_error.c \

# **************************************************************************** #
#                               Object File                                    #
# **************************************************************************** #
# Create directories
$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)
	@$(MKDIR) $(DEPS_DIR)

OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)
DEPS_DIR	= $(OBJ_DIR)
DEPS_FILES	= $(SRCS:%.c=$(DEPS_DIR)/%.d)

# **************************************************************************** #
#                              Progress Bars                                   #
# **************************************************************************** #
SRC_COUNT_TOT := $(shell echo -n $(SRCS) | wc -w)
ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRCS) | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

# **************************************************************************** #
#                              Main Target                                     #
# **************************************************************************** #

all: $(MLX_A) $(LIBFT_A) $(NAME)

# Build executable
$(NAME): $(OBJS) $(LIBFT_A) $(MLX_A)
	@$(CC) $(DMODE) $(WFLAGS) $(CFLAGS) $(OBJS) $(LIBFT_A) $(MLX_A) -I$(INC_DIR) $(LIBFLAGS) -o $(NAME)
	@$(PRINT) "${CLEAR}${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: ${RED}${BOLD}${NAME} ${RESET}compiled ${GREEN}successfully${RESET}.${GREY}\n${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}"

# Rebuild libft.a
$(LIBFT_A): FORCE $(LIBFT_MAKEFILE) $(LIBFT_H)
	@$(MAKE) -s -C $(LIBFT_DIR)

# Download MLX library
$(MLX_DIR):
	@$(PRINT) "Downloading $(BLUE)mlx library$(DEFAULT)...\n"
	@$(GIT) clone $(MLX42_REPO) $(MLX_DIR) > /dev/null 2>&1

# Compile MLX library
$(MLX_A): $(MLX_DIR)
	@$(PRINT) "Compiling $(BLUE)mlx library$(DEFAULT)...\n"
	@$(CD) $(MLX_DIR) && $(CMAKE) -B build > /dev/null 2>&1 && $(CMAKE) --build build -j4 > /dev/null 2>&1

# **************************************************************************** #
#                            Object Compilation                                #
# **************************************************************************** #

# Rule to compile archive .c to ,o with progress bars
${OBJ_DIR}/%.o: ${SRC_DIR}/%.c $(DEPS) $(LIBFT_A) | $(OBJ_DIR)
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@$(PRINT) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)...\n" "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(MKDIR) $(dir $@)
	@$(CC) $(DMODE) $(WFLAGS) $(CFLAGS) -I$(INC_DIR) $(DEPFLAGS) -c -o $@ $<

# Include .deps files
-include $(DEPS_FILES)

# **************************************************************************** #
#                            Secondary Targets                                 #
# **************************************************************************** #

# Compilation for maximum performance
fast:
	@clear
	@$(MAKE) --no-print-directory MODE=release all
	@LD_PRELOAD="" ./$(NAME) $(MAP)

# test sanitize leaks in cub3d
leaks:
	@clear
	@$(MAKE) --no-print-directory MODE=asan all
	@LD_PRELOAD="" LSAN_OPTIONS=suppressions=$(SANL_SUPP) ./$(NAME) $(MAP)

# test sanitize threads in cub3d
races:
	@clear
	@$(MAKE) --no-print-directory MODE=tsan all
	@LD_PRELOAD="" TSAN_OPTIONS="suppressions=$(SANT_SUPP) ignore_noninstrumented_modules=1" ./$(NAME) $(MAP)

# Compilation for debugging
debug:
	@clear
	@$(MAKE) --no-print-directory MODE=debug all
	@LD_PRELOAD="" ./$(NAME) $(MAP)

# Test the norminette in my .c files
norm:
	-@$(NORM) $(LIBFT_DIR)
	-@$(NORM) $(INC_DIR)
	-@$(NORM) $(SRC_DIR)

# Correct the norminette in my .c files
check:
	-@$(WATCH) -n 0.5 --color "make norm | grep -v 'OK!' | grep -v 'Error: PREPROC_CONSTANT'"

# Clean object files
clean:
	@$(MAKE) clean -s -C $(LIBFT_DIR)
	@$(RM) $(MLX_DIR)/build
	@$(RM) obj
	@$(PRINT) "${CLEAR}${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Objects were cleaned ${GREEN}successfully${RESET}.\n${RESET}"

# Full clean
fclean: clean
	@$(MAKE) fclean -s -C $(LIBFT_DIR)
	@$(RM) $(MLX_DIR)
	@$(RM) $(NAME)
	@$(PRINT) "${CLEAR}${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Project cleaned ${GREEN}successfully${RESET}.${GREY}\n${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}"

# Rebuild everything
re: fclean all

# Force verification every build
FORCE:

# Phony targets
.PHONY: all clean fclean re test-leaks test-races debug fast norm check
.DEFAULT_GOAL := all
