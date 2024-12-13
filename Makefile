# Program name
NAME =			push_swap
BONUS_NAME =	checker

# Directories
INC_DIR =	inc/
SRC_DIR =	src/
OBJ_DIR =	obj/
LIBFT_DIR =	libft/

# Header files
INC =				$(INC_DIR)push_swap.h

# Source files
SRC = \
					$(SRC_DIR)exit_func.c \
					$(SRC_DIR)free_func.c \
					$(SRC_DIR)ft_atol.c \
					$(SRC_DIR)init_stack_a.c \
					$(SRC_DIR)ops_list_create.c \
					$(SRC_DIR)ops_list_exec.c \
					$(SRC_DIR)ops_push.c \
					$(SRC_DIR)ops_rotate.c \
					$(SRC_DIR)ops_rvs_rotate.c \
					$(SRC_DIR)ops_swap.c \
					$(SRC_DIR)opss_exec_utils.c \
					$(SRC_DIR)opss_exec.c \
					$(SRC_DIR)opss_prep.c \
					$(SRC_DIR)proc_arg.c \
					$(SRC_DIR)sort_gt_three.c \
					$(SRC_DIR)sort_three.c \
					$(SRC_DIR)stack_find.c \
					$(SRC_DIR)stack_utils.c 
MANDATORY_MAIN =	$(SRC_DIR)push_swap.c
BONUS_MAIN =		$(SRC_DIR)checker.c

# Generate the list of object files in OBJ_DIR from source files in SRC_DIR
OBJ =				$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))
MANDATORY_OBJ =		$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(MANDATORY_MAIN))
BONUS_OBJ =			$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(BONUS_MAIN))

ifdef BONUS
OBJ += $(BONUS_OBJ)
else
OBJ += $(MANDATORY_OBJ)
endif

# Use libft.a
INCLUDE = -L ./libft -lft

# Compielr & flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Commands
RM = rm -f
AR = ar rcs

# Build rules
all: $(NAME)

bonus:
	@make $(BONUS_NAME) BONUS=1

$(NAME): $(OBJ)
	@make libft.a -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) -I$(INC_DIR) -o $@ $(INCLUDE)

$(BONUS_NAME): $(OBJ)
	@make libft.a -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) -I$(INC_DIR) -o $@ $(INCLUDE)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus
