# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 19:51:37 by migarrid          #+#    #+#              #
#    Updated: 2026/03/02 00:14:38 by migarrid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library name
NAME = libft_plus.a

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wpedantic -g -lm -Ofast -march=native -flto
OFLAGS = -Os -ffunction-sections -fdata-sections -Wl,--gc-sections
VFLAGS = -Ofast -march=native -flto

# Colors
DEFAULT = \033[0;39m
GREEN = \033[0;92m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m

# Commands
PRINTF = printf
RM = rm -f

# Source files
SRCS =	libft/ft_isalpha.c \
		libft/ft_isdigit.c \
		libft/ft_isalnum.c \
		libft/ft_isascii.c \
		libft/ft_isprint.c \
		libft/ft_issign.c \
		libft/ft_isspace.c \
		libft/ft_isspecial.c \
		libft/ft_ishex.c \
		libft/ft_strlen.c \
		libft/ft_count_char.c \
		libft/ft_memset.c \
		libft/ft_bzero.c \
		libft/ft_memcpy.c \
		libft/ft_memmove.c \
		libft/ft_strlcpy.c \
		libft/ft_strlcat.c \
		libft/ft_toupper.c \
		libft/ft_tolower.c \
		libft/ft_strchr.c \
		libft/ft_strrchr.c \
		libft/ft_strcmp.c \
		libft/ft_strncmp.c \
		libft/ft_strmatch_cmp.c \
		libft/ft_memchr.c \
		libft/ft_memcmp.c \
		libft/ft_memnuke.c \
		libft/ft_strnstr.c \
		libft/ft_atoi.c \
		libft/ft_atol.c \
		libft/ft_atoi_range.c \
		libft/ft_atol_range.c \
		libft/ft_strtol.c \
		libft/ft_strtof.c \
		libft/ft_square.c \
		libft/ft_max.c \
		libft/ft_distance.c \
		libft/ft_alloc.c \
		libft/ft_calloc.c \
		libft/ft_realloc.c \
		libft/ft_priv_alloc.c \
		libft/ft_privatize.c \
		libft/ft_strdup.c \
		libft/ft_strndup.c \
		libft/ft_arraydup.c \
		libft/ft_substr.c \
		libft/ft_strjoin.c \
		libft/ft_strjoin_multi.c \
		libft/ft_strtrim.c \
		libft/ft_strightrim.c \
		libft/ft_strleftrim.c \
		libft/ft_strfilter_c.c\
		libft/ft_strcut.c \
		libft/ft_strchr_swap.c \
		libft/ft_strnorm_spaces.c \
		libft/ft_strnorm_multi.c \
		libft/ft_split.c \
		libft/ft_itoa.c \
		libft/ft_arraylen.c \
		libft/ft_strmapi.c \
		libft/ft_striteri.c \
		libft/ft_putchar_fd.c \
		libft/ft_strindex.c \
		libft/ft_putstr_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c \
		libft/ft_print_str_array.c \
		libft/ft_print_int_matrix.c \
		libft/ft_capitalize.c \
		libft/ft_str_replace.c \
		libft/ft_free.c \
		libft/ft_free_str_array.c \
		libft/ft_free_int_matrix.c \
		libft/ft_free_double_matrix.c \
		libft/ft_free_multi.c \
		libft/ft_lstnew_bonus.c \
		libft/ft_lstadd_front_bonus.c \
		libft/ft_lstsize_bonus.c \
		libft/ft_lstlast_bonus.c \
		libft/ft_lstadd_back_bonus.c \
		libft/ft_lstdelone_bonus.c \
		libft/ft_lstclear_bonus.c \
		libft/ft_lstiter_bonus.c \
		libft/ft_lstmap_bonus.c \
		ft_printf_fd/ft_printf_fd_bonus.c \
		ft_printf_fd/ft_var_printf_fd_bonus.c \
		ft_printf_fd/ft_apply_flags_bonus.c \
		ft_printf_fd/ft_apply_hash_bonus.c \
		ft_printf_fd/ft_apply_left_align_bonus.c \
		ft_printf_fd/ft_apply_plus_bonus.c \
		ft_printf_fd/ft_apply_precision_bonus.c \
		ft_printf_fd/ft_apply_space_bonus.c \
		ft_printf_fd/ft_apply_zero_pad_bonus.c \
		ft_printf_fd/ft_apply_min_width_bonus.c \
		ft_printf_fd/ft_print_char_fd_bonus.c \
		ft_printf_fd/ft_print_str_fd_bonus.c \
		ft_printf_fd/ft_print_ptr_fd_bonus.c \
		ft_printf_fd/ft_print_num_fd_bonus.c \
		ft_printf_fd/ft_print_unsigned_fd_bonus.c \
		ft_printf_fd/ft_print_hex_fd_bonus.c \
		ft_printf_fd/ft_print_float_fd_bonus.c \
		ft_printf_fd/ft_print_float_fd_utils_bonus.c \
		ft_printf_fd/ft_itoa_base_bonus.c \
		ft_printf_fd/ft_utoa_bonus.c \
		get_next_line/get_next_line_bonus.c \

# Mandatory objects
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

# Progress variables
SRC_COUNT_TOT := $(shell echo -n $(SRCS) | wc -w)
ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRCS) | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

# Main rule: compile the library
all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

# Rule to compile .c to .o files with progress bar
%.o: %.c libft_plus.h Makefile
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(CFLAGS) $(VFLAGS) $(OFLAGS) -I. -MMD -MP -c -o $@ $<

# Include dependency files
-include $(DEPS)

# Clean objects
clean:
	@$(RM) $(OBJS) $(DEPS)

# Clean everything (objects + library)
fclean: clean
	@$(RM) $(NAME)
	@$(RM) ../$(NAME)

# Recompile everything from scratch
re: fclean all

# Ensure rules are executed as make commands
.PHONY: all clean fclean re bonus
