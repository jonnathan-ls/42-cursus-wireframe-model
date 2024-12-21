NAME = fdf

SRCS_DIR = ./sources
OBJS_DIR = ./objects
INCLUDES_DIR = ./includes
LIBS_DIR = ./libraries

SOURCES = $(SRCS_DIR)/fdf.c
OBJECTS = $(SOURCES:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

LIBFT_DIR = $(LIBS_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES_DIR) -I$(LIBFT_DIR)/includes

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES_DIR)/fdf.h
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re