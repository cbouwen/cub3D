NAME = cub3D

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRC_DIR = ./src/
SRC_MAIN = main.c init_struct_default.c utils.c execute.c init_raycasting.c movement.c window_utils.c rendering.c free_utils.c
SRC_FILES = $(addprefix $(SRC_DIR), $(SRC_MAIN))
PARSER_SRC = $(addprefix $(SRC_DIR)parser/, parse_textures.c parse_texture_error.c parser.c mapinfo.c parse_utils.c parse_map.c valid_map.c parse_player.c)

SRC = $(SRC_FILES) $(PARSER_SRC)

GNL_DIR = ./lib/Getnextline/
GNL_LIB = $(GNL_DIR)getnextline.a
GNL_INC = -I $(GNL_DIR)

LIBFT_DIR = ./lib/Libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a
LIBFT_INC = -I $(LIBFT_DIR)

MLX_PATH = mlx_linux/
MLX_NAME = libmlx_Linux.a
MLX = $(MLX_PATH)$(MLX_NAME)

all : $(NAME)

$(NAME) : $(LIBFT_LIB) $(MLX) $(SRC) $(GNL_LIB)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT_LIB) $(GNL_LIB) $(MLX_FLAGS) -o $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(GNL_LIB):
	make -C $(GNL_DIR)

$(MLX):
	make -C $(MLX_PATH) all

clean : 
	make -C $(MLX_PATH) clean
	make clean -C $(LIBFT_DIR)
	make clean -C $(GNL_DIR)

fclean : clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(GNL_DIR)
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
