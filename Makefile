NAME = fdf
BONUS_NAME	= fdf_bonus

SRCS_DIR = ./sources
OBJS_DIR = ./objects
INCLUDES_DIR = ./includes
LIBS_DIR = ./libraries

SOURCES = \
	$(SRCS_DIR)/fdf.c \
	$(SRCS_DIR)/utils.c \
	$(SRCS_DIR)/mapper.c \
	$(SRCS_DIR)/drawer.c \
	$(SRCS_DIR)/cleaner.c \
	$(SRCS_DIR)/validator.c \
	$(SRCS_DIR)/algorithm.c \
	$(SRCS_DIR)/projection.c \
	$(SRCS_DIR)/coordinates.c \
	$(SRCS_DIR)/initializer.c	\
	$(SRCS_DIR)/configurator.c \

BONUS_SOURCES = \
	$(SRCS_DIR)/utils.c \
	$(SRCS_DIR)/mapper.c \
	$(SRCS_DIR)/drawer.c \
	$(SRCS_DIR)/cleaner.c \
	$(SRCS_DIR)/validator.c \
	$(SRCS_DIR)/algorithm.c \
	$(SRCS_DIR)/projection.c \
	$(SRCS_DIR)/coordinates.c \
	$(SRCS_DIR)/initializer.c	\
	$(SRCS_DIR)/configurator.c \
	$(SRCS_DIR)/fdf_bonus.c \
	$(SRCS_DIR)/utils_bonus.c \
	$(SRCS_DIR)/handler_bonus.c \
	$(SRCS_DIR)/instructions_bonus.c \

OBJECTS = $(SOURCES:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
BONUS_OBJECTS = $(BONUS_SOURCES:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

LIBFT_DIR = $(LIBS_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = $(LIBS_DIR)/printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

MLX_DIR = $(LIBS_DIR)/minilibx
MLX = $(MLX_DIR)/libmlx.a
MATH = -lm

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(INCLUDES_DIR) -I$(LIBFT_DIR)/includes -I$(PRINTF_DIR)/includes -I$(MLX_DIR)
LDFLAGS = -L$(MLX_DIR) -lmlx -L/usr/include -lXext -lX11

all: $(LIBFT) $(PRINTF) $(MLX) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJECTS) $(LIBFT) $(PRINTF) $(MLX) 
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(PRINTF) $(MLX) $(MATH) $(LDFLAGS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJECTS) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(BONUS_OBJECTS) $(LIBFT) $(PRINTF) $(MLX) $(MATH) $(LDFLAGS) -o $(BONUS_NAME)

bonus: $(LIBFT) $(PRINTF) $(MLX) $(BONUS_NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c 
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re