NAME = cub3D

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRC_DIR = ./src/
SRC = main.c utils.c map_checker.c
SRC_FILES = $(addprefix $(SRC_DIR), $(SRC))

GNL_DIR = ./lib/Getnextline/
GNL_LIB = $(GNL_DIR)getnextline.a
GNL_INC = -I $(GNL_DIR)

LIBFT_DIR = ./lib/Libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a
LIBFT_INC = -I $(LIBFT_DIR)

all : $(NAME)

$(NAME) : $(LIBFT_LIB) $(SRC_FILES) $(GNL_LIB)
	$(CC) $(CFLAGS) $(SRC_FILES) $(LIBFT_LIB) $(GNL_LIB) -o $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(GNL_LIB):
	make -C $(GNL_DIR)

clean : 
	make clean -C $(LIBFT_DIR)
	make clean -C $(GNL_DIR)

fclean : clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(GNL_DIR)
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
