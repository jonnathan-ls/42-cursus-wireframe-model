NAME = fdf

SRCS_DIR = ./sources
OBJS_DIR = ./objects
INCLUDES_DIR = ./includes
LIBS_DIR = ./libraries

SOURCES = $(SRCS_DIR)/fdf.c \
	$(SRCS_DIR)/ft_get_data.c \
	$(SRCS_DIR)/ft_set_points.c \
	$(SRCS_DIR)/fdf_errors.c \

OBJECTS = $(SOURCES:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

LIBFT_DIR = $(LIBS_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = $(LIBS_DIR)/printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

MLX_DIR = $(LIBS_DIR)/minilibx
MLX = $(MLX_DIR)/libmlx.a
MATH = -lm

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES_DIR) -I$(LIBFT_DIR)/includes -I$(PRINTF_DIR)/includes -I$(MLX_DIR)
LDFLAGS = -L$(MLX_DIR) -lmlx -L/usr/include -lXext -lX11

all: $(LIBFT) $(PRINTF) $(MLX) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJECTS) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(PRINTF) $(MLX) $(MATH) $(LDFLAGS) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES_DIR)/fdf.h
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re