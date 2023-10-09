CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

NAME = cub3D
LIBFT = ./lib/libft/libft.a

#HEADERS = cub3d.h
# Source files
MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

LIB = $(LIBFT)  # $(wildcard ./lib/**/*.c)
SRC = $(wildcard ./src/*.c ./src/**/*.c)
OBJ = $(SRC:.c=.o)

all : $(NAME) #$(HEADERS)

$(LIBFT) : $(wildcard ./lib/libft/*.c)
	@echo "⌛ Compiling libft\n"
	@make -C ./lib/libft
	@make -C ./lib/libft bonus
	@make -C ./lib/libft clean

$(NAME): $(SRC) $(LIB)
	@echo "$(GREEN)⌛ Compiling $(NAME) ...$(END)"
	@$(CC) $(CFLAGS) $(SRC) $(LIB) $(MLX) -o $(NAME)
	@echo "✅ $(NAME) compiled successfully\n"

%.o : %.c cub3d.h
	$(CC) $(CFLAGS) $< -c -o $@

clean :
	@rm -rf $(OBJ)
	@make -C  ./lib/libft clean
	@echo "🗑️  objects removed \n"

fclean : clean
	@rm -rf $(NAME)
	@make -C  ./lib/libft fclean
	@echo "🗑️  $(NAME) $(OBJ) removed \n"

re : fclean all

.PHONY: all clean fclean re
