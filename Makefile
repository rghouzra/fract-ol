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

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -lmlx -framework OpenGL -framework  AppKit -o fast -o $(NAME)

%.o: %.c fractal.h
	$(CC) $(FLAGS) -Imlx -c -ofast $< -o $@

bonus:all
clean:
	rm -rf *.o

fclean:clean
	rm -rf $(NAME)

re:fclean all
