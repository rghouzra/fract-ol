NAME = fract-ol

FLAGS = -Wall -Wextra -Werror

SOURCES = ft_draw.c \
            ft_init.c \
            ft_color.c \
            main.c \
            utils.c \
            ft_map.c \
            mandelbrot.c \
            julia.c \
            libft_utils.c \
            hook.c \
            keyboard_event.c \
            mouse_event.c \
            perpe_bship.c

OBJS = $(SOURCES:.c=.o)

MLX_PATH = minilibx
MLX_LIB = -L$(MLX_PATH) -lmlx

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(MLX_LIB) -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c fractal.h
	$(CC) $(FLAGS) -I$(MLX_PATH) -c $< -o $@

bonus: all

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all