NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx-linux
LIBFT_DIR = libft
INCLUDES = -I $(MLX_DIR) -I $(LIBFT_DIR)
LDFLAGS = -L $(MLX_DIR) -lmlx -L $(LIBFT_DIR) -lft -lXext -lX11 -lm

SRCS = fractol.c fractal_initialization.c math.c rendering.c utils.c events.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LDFLAGS) -o $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@  
clean:
	rm -f $(OBJS) $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
