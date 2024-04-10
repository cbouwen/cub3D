NAME = cub3D

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRC_DIR = ./src/
SRC = main.c
SRC_FILES = $(addprefix $(SRC_DIR), $(SRC))

LIBFT_DIR = ./lib/Libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a
LIBFT_INC = -I $(LIBFT_DIR)

all : $(NAME)

$(NAME) : $(LIBFT_LIB) $(SRC_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean : 
	make clean -C $(LIBFT_DIR)

fclean : clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
