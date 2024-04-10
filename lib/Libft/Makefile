CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
AR = ar
ARFLAGS = rcs
SRCS = ft_strndup.c ft_strcmp.c ft_atoi.c ft_isascii.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strlen.c ft_strtrim.c ft_bzero.c ft_isdigit.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_substr.c ft_calloc.c ft_isprint.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c ft_isalnum.c ft_itoa.c ft_memset.c ft_split.c ft_strlcat.c ft_strnstr.c ft_toupper.c ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlcpy.c ft_strrchr.c ft_max.c ft_atol.c
OBJ = $(SRCS:.c=.o)
BONUSSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUSOBJ = $(BONUSSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(BONUSOBJ)

fclean: clean
	rm -rf $(NAME)

re: clean all

bonus: $(NAME) $(BONUSOBJ)
	$(AR) $(ARFLAGS) $(NAME) $(BONUSOBJ)
	
.PHONY: all clean fclean re bonus
