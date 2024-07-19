NAME = so_long
SRCS = index.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
LIBENGIME = ./engime/libengime.a
LIBSMLX = ./smlx/libsmlx.a
LIBMLX =  ./mlx/libmlx.a
LIBMLX_URL = https://cdn.intra.42.fr/document/document/26489/minilibx-linux.tgz
LIBMLX_TGZ = minilibx-linux

CC = cc
CFLAGS = -g -Imlx
LDFLAGS = -Lmlx -lmlx_Linux -lXext -lX11 -lm -lz
all: $(NAME)

$(LIBSMLX):
	$(MAKE) -C ./smlx

$(LIBFT):
	$(MAKE) bonus -C ./libft

$(LIBENGIME):
	$(MAKE) -C ./engime

$(NAME): $(LIBFT) $(LIBENGIME) $(LIBSMLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBENGIME) $(LIBSMLX) $(LIBFT) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) fclean -C ./smlx
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./engime
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -rf mlx
	rm -rf $(LIBMLX_TGZ).tgz

re: fclean all

configure:
	rm -rf mlx
	wget -nc $(LIBMLX_URL)
	tar -xzf $(LIBMLX_TGZ).tgz
	mv $(LIBMLX_TGZ) mlx
	$(MAKE) -C ./mlx
	rm -rf $(LIBMLX_TGZ).tgz

.PHONY: all clean fclean re
