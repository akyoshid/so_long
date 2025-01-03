# Program name
NAME =			so_long
BONUS_NAME =	so_long_bonus

# Directories
INC_DIR =	inc/
SRC_DIR =	src/
OBJ_DIR =	obj/
LIBFT_DIR =	libft/
MLX_DIR =	minilibx-linux/

# Header files
INC =				$(INC_DIR)so_long.h

# Source files
SRC = \
					$(SRC_DIR)check_arg.c \
					$(SRC_DIR)check_compo.c \
					$(SRC_DIR)check_map.c \
					$(SRC_DIR)check_path_c.c \
					$(SRC_DIR)check_path_e.c \
					$(SRC_DIR)ft_rand_256.c \
					$(SRC_DIR)handle_flag.c \
					$(SRC_DIR)img_utils.c \
					$(SRC_DIR)loop_hook.c \
					$(SRC_DIR)map_utils.c \
					$(SRC_DIR)move_enemy_utils.c \
					$(SRC_DIR)move_enemy.c \
					$(SRC_DIR)on_key_press.c \
					$(SRC_DIR)open_map_file.c \
					$(SRC_DIR)proc_err.c \
					$(SRC_DIR)proc_mlx_buff_image.c \
					$(SRC_DIR)proc_mlx_err.c \
					$(SRC_DIR)proc_mlx_init.c \
					$(SRC_DIR)proc_mlx_load_sprite.c \
					$(SRC_DIR)proc_mlx_new_window.c \
					$(SRC_DIR)put_images_to_buff.c \
					$(SRC_DIR)quit_program.c \
					$(SRC_DIR)read_map_file.c \
					$(SRC_DIR)refresh_display.c \
					$(SRC_DIR)refresh_map.c
MANDATORY_MAIN =	$(SRC_DIR)so_long.c
BONUS_MAIN =		$(SRC_DIR)so_long_bonus.c

# Generate the list of object files in OBJ_DIR from source files in SRC_DIR
OBJ =				$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))
MANDATORY_OBJ =		$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(MANDATORY_MAIN))
BONUS_OBJ =			$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(BONUS_MAIN))

ifdef BONUS
OBJ += $(BONUS_OBJ)
else
OBJ += $(MANDATORY_OBJ)
endif

# Compile
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_LIB = -L ./libft -lft
MLX_LIB = -L ./minilibx-linux -lmlx_Linux -lXext -lX11

# Commands
RM = rm -f
AR = ar rcs

# Build rules
all: $(NAME)

bonus:
	@make $(BONUS_NAME) BONUS=1

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) -I$(INC_DIR) -o $@ $(LIBFT_LIB) $(MLX_LIB)

$(BONUS_NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) -I$(INC_DIR) -o $@ $(LIBFT_LIB) $(MLX_LIB)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus
