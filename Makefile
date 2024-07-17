NAME = so_long
SRCS = index.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
LIBENGIME = ./engime/libengime.a
LIBMLX = ./smlx/libsmlx.a
CC = cc
CFLAGS = -g -Imlx
LDFLAGS = -Lmlx -lmlx_Linux -lXext -lX11 -lm -lz
.PHONY: all clean fclean re
all: $(NAME)

$(LIBMLX):
	$(MAKE) -C ./smlx

$(LIBFT):
	$(MAKE) bonus -C ./libft

$(LIBENGIME):
	$(MAKE) -C ./engime

$(NAME): $(LIBFT) $(LIBENGIME)  $(LIBMLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBENGIME) $(LIBMLX) $(LIBFT) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) fclean -C ./smlx
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./engime
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all