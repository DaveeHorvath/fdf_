NAME = libft.a

CC = cc

SRC_LIB_CHAR = $(addprefix char/, ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_toupper.c ft_tolower.c)
SRC_LIB_LLIST = $(addprefix llist/, ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c)
SRC_LIB_MATH = $(addprefix math/, ft_atoi.c ft_itoa.c)
SRC_LIB_MEM = $(addprefix mem/, ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c)
SRC_LIB_PUT = $(addprefix put_fd/, ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putnbr_long_fd.c)
SRC_LIB_STR = $(addprefix str/, ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c)

SRC_LIB = $(addprefix libft/, $(SRC_LIB_CHAR) $(SRC_LIB_LLIST) $(SRC_LIB_MATH) $(SRC_LIB_MEM) $(SRC_LIB_PUT) $(SRC_LIB_STR))
OBJ_LIB = $(addprefix $(OBJDIR_LIBFT), $(notdir $(SRC_LIB:.c=.o)))

SRC_PRINTF = $(addprefix ft_printf/, arg_print.c ft_printf.c hex_print.c utils.c)
OBJ_PRINTF = $(addprefix $(OBJDIR_PRF), $(notdir $(SRC_PRINTF:.c=.o)))

SRC_GNL = $(addprefix gnl/, get_next_line.c get_next_line_utils.c)
OBJ_GNL = $(addprefix $(OBJDIR_GNL), $(notdir $(SRC_GNL:.c=.o)))

SRC = $(addprefix src/, $(SRC_LIB) $(SRC_GNL) $(SRC_PRINTF))

OBJ = $(OBJ_GNL) $(OBJ_LIB) $(OBJ_PRINTF)

OBJDIR_GNL = obj/gnl/
OBJDIR_LIBFT = obj/libft/
OBJDIR_PRF = obj/ft_printf/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) 
	ar rus $(NAME) $(OBJ)

$(OBJ): $(OBJDIR_GNL) $(OBJDIR_LIBFT) $(OBJDIR_PRF)

$(OBJDIR_GNL):
	mkdir $(OBJDIR_GNL)

$(OBJDIR_PRF):
	mkdir $(OBJDIR_PRF)

$(OBJDIR_LIBFT):
	mkdir $(OBJDIR_LIBFT)

$(OBJDIR_PRF)%.o: src/ft_printf/%.c 
	$(CC) $(FLAGS) -c -o $@ $< -I includes/

$(OBJDIR_GNL)%.o: src/gnl/%.c
	$(CC) $(FLAGS) -c -o $@ $< -I includes/

$(OBJDIR_LIBFT)%.o: src/libft/*/%.c
	$(CC) $(FLAGS) -c -o $@ $< -I includes/

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
