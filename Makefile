NAME = fdf

SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), colors.c hooks.c main.c parser.c render.c utils.c)

LIBFT = libft/libft.a
MLX42 = MLX42/build/libmlx42.a

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

CFLAGS = -Wall -Wextra -Werror -I includes/ -I MLX42/include -I libft/includes -Ofast

MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"



all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(MLX42) $(LIBFT)
	cc $(CFLAGS) $(MLXFLAGS) $(OBJ) libft/libft.a MLX42/build/libmlx42.a -o $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(MLX42):
	cmake MLX42/ -B MLX42/build && make -C MLX42/build -j4

$(LIBFT):
	make -C libft/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all