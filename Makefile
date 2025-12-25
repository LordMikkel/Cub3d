# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/21 00:54:42 by migarrid          #+#    #+#              #
#    Updated: 2025/12/25 19:17:52 by migarrid         ###   ########.fr        #
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
WFLAGS				= -Wall -Wextra -Werror
DFLAGS				= -g
DMAIN				= -D MAIN
#VFLAGS				= -Ofast -march=native -flto
#OFLAGS				= -Os -flto -ffunction-sections -fdata-sections -Wl,--gc-sections
DEPFLAGS			= -MMD -MP
LIBFLAGS			= -ldl -lglfw -pthread -lm
SFLAGS				=

# **************************************************************************** #
#                               Shell Comands                                  #
# **************************************************************************** #
RM					= rm -rf
PRINT				= printf
MAKE				= make
MKDIR				= mkdir -p
NORM				= norminette
CMAKE				= cmake
MV					= mv
CD					= cd

# **************************************************************************** #
#                              Directories                                     #
# **************************************************************************** #
INC_DIR				= inc
LIB_DIR				= lib
OBJ_DIR				= obj
SRC_DIR				= src
MAP_DIR				= map
EXT_DIR				= ext
LIBFT_DIR			= $(LIB_DIR)/libft_plus
MLX_DIR				= $(LIB_DIR)/mlx42

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
SAN_SUPP			= $(EXT_DIR)/sanitize_leaks.supp
VAL_SUPP			= $(EXT_DIR)/valgrind_leaks.supp
MAP					= $(MAP_DIR)/test.cub
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
#                              Progress Bars                                   #
# **************************************************************************** #
SRC_COUNT_TOT := $(shell echo -n $(SRCS) | wc -w)
ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRCS) | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

# **************************************************************************** #
#                               Source File                                    #
# **************************************************************************** #
SRCS =				core/main.c \
					core/init/init_data.c \
					core/init/init_mlx.c \
					core/game/game_loop.c \
					core/clean/clean_all.c \
					core/clean/clean_mlx.c \
					core/exit/exit_succes.c \
					core/exit/exit_error.c \
					parse/check_args.c \
					parse/parse_map.c \
					input/handle/keyboard_input.c \
					input/handle/cursor_input.c \
					input/handle/click_input.c \
					input/events/close_events.c \

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
	@$(CC) $(WFLAGS) $(DMAIN) $(DFLAGS) $(SFLAGS) $(VFLAGS) $(OFLAGS) $(OBJS) $(LIBFT_A) $(MLX_A) -I$(INC_DIR) $(LIBFLAGS) $(LDLIBS) -o $(NAME)
	@$(PRINT) "${CLEAR}${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: ${RED}${BOLD}${NAME} ${RESET}compiled ${GREEN}successfully${RESET}.${GREY}\n${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}"

# Rebuild libft.a
$(LIBFT_A): FORCE $(LIBFT_MAKEFILE) $(LIBFT_H)
	@$(MAKE) -s -C $(LIBFT_DIR)

# Compile MLX library
$(MLX_A):
	@$(PRINT) "Compiling $(BLUE)mlx library$(DEFAULT)...\n"
	@$(CD) $(MLX_DIR) && $(CMAKE) -B build > /dev/null 2>&1 && $(CMAKE) --build build -j4 > /dev/null  2>&1


# **************************************************************************** #
#                            Object Compilation                                #
# **************************************************************************** #

# Rule to compile archive .c to ,o with progress bars
${OBJ_DIR}/%.o: ${SRC_DIR}/%.c $(DEPS) $(LIBFT_A) | $(OBJ_DIR)
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@$(PRINT) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)...\n" "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(MKDIR) $(dir $@)
	@$(CC) $(WFLAGS) $(DMAIN) $(DFLAGS) $(SFLAGS) $(VFLAGS) $(OFLAGS) -I$(INC_DIR) $(DEPFLAGS) -c -o $@ $<

# Include .deps files
-include $(DEPS_FILES)

# **************************************************************************** #
#                            Secondary Targets                                 #
# **************************************************************************** #

# test sanitize in cub3d
test:
	@clear
	@$(MAKE) --no-print-directory SFLAGS="-fsanitize=address,undefined -O0" all
	@LSAN_OPTIONS=suppressions=$(SAN_SUPP) ./$(NAME) $(MAP)

# Test leaks in cub3d
leaks:
	@clear
	@$(MAKE) --no-print-directory SFLAGS="" all
	@valgrind --suppressions=$(VAL_SUPP) --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(MAP)

# Test the norminette in my .c files
norm:
	-@$(NORM) $(LIBFT_DIR)
	-@$(NORM) $(INC_DIR)
	-@$(NORM) $(SRC_DIR)

# Clean object files
clean:
	@$(MAKE) clean -s -C $(LIBFT_DIR)
	@$(RM) $(MLX_DIR)/build
	@$(RM) $(OBJ_DIR)
	@$(PRINT) "${CLEAR}${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Objects were cleaned ${GREEN}successfully${RESET}.\n${RESET}"

# Full clean
fclean: clean
	@$(MAKE) fclean -s -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	@$(PRINT) "${CLEAR}${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Project cleaned ${GREEN}successfully${RESET}.${GREY}\n${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}"

# Rebuild everything
re: fclean all

# Force verification every build
FORCE:

# Phony targets
.PHONY: all clean fclean re test leaks norm
.DEFAULT_GOAL := all
