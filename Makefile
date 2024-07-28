NAME = fdf

SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), colors.c hooks.c main.c parser.c render.c utils.c)

LIBFT = libft/libft.a
MLX42_AR = MLX42/build/libmlx42.a

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

CFLAGS = -Wall -Wextra -Werror -I includes/ -I MLX42/include -I libft/includes -Ofast

ifeq ($(OS), Windows_NT)
	ARCH := Windows
else
	ARCH := $(shell uname -s)
endif

MLX_LD = -L MLX42/build

ifeq ($(ARCH), Linux)
	MLX_LD += -ldl -lglfw -pthread -lm
else ifeq ($(ARCH), Windows)
	MLX_LD += -lglfw3 -lopengl32 -lgdi32
else ifeq ($(ARCH), Darwin)
	MLX_LD += -L /users/$(USER)/.brew/opt/glfw/lib -lglfw -framework Cocoa -framework OpenGL -framework IOKit
endif

all: $(NAME)

$(NAME): $(MLX42_AR) $(LIBFT) $(OBJ_DIR) $(OBJ)
	cc $(CFLAGS) $(OBJ) libft/libft.a MLX42/build/libmlx42.a $(MLX_LD) -o $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(MLX42_AR):
	# git clone https://github.com/codam-coding-college/MLX42.git
	cmake MLX42/ -B MLX42/build && make -C MLX42/build -j4

$(LIBFT):
	mkdir -p libft/obj/
	make -C libft/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C libft/ 

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/
	rm -rf MLX42/build/

re: fclean all