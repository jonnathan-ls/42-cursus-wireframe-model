MAKEFLAGS += --no-print-directory

NAME = fdf
BONUS_NAME	= fdf_bonus

SRCS_DIR = ./sources
OBJS_DIR = ./objects
DEPS_DIR = ./depends
LIBS_DIR = ./libraries
INCLUDES_DIR = ./includes

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

SOURCES_BONUS = \
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
	$(SRCS_DIR)/key_press_bonus.c \
	$(SRCS_DIR)/instructions_bonus.c \

OBJECTS = $(SOURCES:.c=.o)
DEPENDS = $(SOURCES:.c=.d)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)
DEPENDS_BONUS = $(SOURCES_BONUS:.c=.d)

LIBFT_DIR = $(LIBS_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = $(LIBS_DIR)/minilibx
MLX = $(MLX_DIR)/libmlx.a
MATH = -lm

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(INCLUDES_DIR) -I$(LIBFT_DIR)/includes -I$(MLX_DIR)
LDFLAGS = -L$(MLX_DIR) -lmlx -L/usr/include -lXext -lX11

LIBS = $(LIBFT) \ $(MLX) \ $(MATH)

all: $(NAME)

$(NAME): $(LIBS) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LIBFT) $(MLX) $(MATH) $(LDFLAGS) 

%.o : %.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

-include $(DEPENDS)
-include $(DEPENDS_BONUS)

$(LIBS):
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR)

bonus : $(LIBS) $(OBJECTS_BONUS)
	$(CC) $(FLAGS) $(OBJECTS_BONUS) -o $(NAME) $(LIBFT) $(MLX) $(MATH) $(LDFLAGS) -DBONUS

clean:
	$(RM) $(OBJECTS) 
	$(RM) $(DEPENDS)
	$(RM) $(OBJECTS_BONUS) 
	$(RM) $(DEPENDS_BONUS)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean
	
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all


.PHONY: all clean fclean re bonus