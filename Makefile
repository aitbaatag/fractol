SRCS = colors.c draw_fract_ol.c error_input.c \
       evens_fractol.c ft_myatoi.c ft_strcmp.c init_fract_ol.c \
       julia.c main.c mandelbrot.c utils_fractol.c burning_ship.c tools.c
OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LDFLAGS =  -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm
NAME = fractol

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)


fclean: clean
	$(RM) $(NAME)

re: fclean all